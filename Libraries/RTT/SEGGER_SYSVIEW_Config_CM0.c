/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************
*                                                                    *
*            (c) 1995 - 2019 SEGGER Microcontroller GmbH             *
*                                                                    *
*       www.segger.com     Support: support@segger.com               *
*                                                                    *
**********************************************************************
*                                                                    *
*       SEGGER SystemView * Real-time application analysis           *
*                                                                    *
**********************************************************************
*                                                                    *
* All rights reserved.                                               *
*                                                                    *
* SEGGER strongly recommends to not make any changes                 *
* to or modify the source code of this software in order to stay     *
* compatible with the SystemView and RTT protocol, and J-Link.       *
*                                                                    *
* Redistribution and use in source and binary forms, with or         *
* without modification, are permitted provided that the following    *
* condition is met:                                                  *
*                                                                    *
* o Redistributions of source code must retain the above copyright   *
*   notice, this condition and the following disclaimer.             *
*                                                                    *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND             *
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,        *
* INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF           *
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE           *
* DISCLAIMED. IN NO EVENT SHALL SEGGER Microcontroller BE LIABLE FOR *
* ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR           *
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  *
* OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;    *
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF      *
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT          *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  *
* USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
* DAMAGE.                                                            *
*                                                                    *
**********************************************************************
*                                                                    *
*       SystemView version: 3.20                                    *
*                                                                    *
**********************************************************************
-------------------------- END-OF-HEADER -----------------------------

File    : SEGGER_SYSVIEW_Config_NoOS.c
Purpose : Sample setup configuration of SystemView without an OS for Cortex-M0.
Revision: $Rev: 18540 $
*/
#include "SEGGER_SYSVIEW.h"
#include "SEGGER_SYSVIEW_Conf.h"

#include <datasheet.h>
#include <systick.h>

// SystemCoreClock can be used in most CMSIS compatible projects.
// In non-CMSIS projects define SYSVIEW_CPU_FREQ.
extern uint32_t SystemCoreClock;
extern uint32_t SEGGER_SYSVIEW_TickCnt;

// Frequency of the timestamp. Must match SEGGER_SYSVIEW_Conf.h
#define SYSVIEW_TIMESTAMP_FREQ (SystemCoreClock)

// System Frequency. SystemcoreClock is used in most CMSIS compatible projects.
#define SYSVIEW_CPU_FREQ (SystemCoreClock)

// The lowest RAM address used for IDs (pointers)
#define SYSVIEW_RAM_BASE (0x10000000)

/********************************************************************* 
*
*       _cbSendSystemDesc()
*
*  Function description
*    Sends SystemView description strings.
*/
static void _cbSendSystemDesc(void)
{
    SEGGER_SYSVIEW_SendSysDesc("N=" SEGGER_SYSVIEW_APP_NAME ",D=" SEGGER_SYSVIEW_DEVICE_NAME);
    SEGGER_SYSVIEW_SendSysDesc("I#15=SysTick,I#16=BLE_WAKEUP_LP,I#17=rwble_isr,I#18=UART,I#19=UART2,I#20=I2C,I#21=SPI,I#22=ADC,I#23=KEYBRD,I#24=BLE_RF_DIAG,I#25=RFCAL,I#26=GPIO0,I#27=GPIO1,I#28=GPIO2,I#29=GPIO3,I#30=GPIO4,I#31=SWTIM,I#32=WKUP_QUADEC,I#33=SWTIM1,I#34=RTC,I#35=DMA,I#36=XTAL32M_RDY");
}

/*********************************************************************
*
*       Global functions
*
**********************************************************************
*/
void SEGGER_SYSVIEW_Conf(void)
{
    systick_start(0x01000000, 0);
    SEGGER_SYSVIEW_Init(1000000, SYSVIEW_CPU_FREQ, 0, _cbSendSystemDesc);
    SEGGER_SYSVIEW_SetRAMBase(SYSVIEW_RAM_BASE);
}

/*********************************************************************
*
*       SEGGER_SYSVIEW_X_GetTimestamp()
*
* Function description
*   Returns the current timestamp in ticks using the system tick 
*   count and the SysTick counter.
*   All parameters of the SysTick have to be known and are set via
*   configuration defines on top of the file.
*
* Return value
*   The current timestamp.
*
* Additional information
*   SEGGER_SYSVIEW_X_GetTimestamp is always called when interrupts are
*   disabled. Therefore locking here is not required.
*/
U32 SEGGER_SYSVIEW_X_GetTimestamp(void)
{
    U32 tickCount;
    U32 cycles;
    U32 cyclesPerTick;

    /* Handle SysTick value, SysTick is down-counting. */
    cyclesPerTick = SysTick->LOAD + 1;
    cycles = (cyclesPerTick - SysTick->VAL);

    /* Load system tick count. */
    tickCount = SEGGER_SYSVIEW_TickCnt;

    /* Handle systick overflow, if the bit is set it will clear automatically on register read. */
    if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0)
    {
        /* Increase saved tick on overflow. */
        ++SEGGER_SYSVIEW_TickCnt;
        /* Refresh tick count. */
        ++tickCount;
    }

    /* Adjust cycles for past ticks. */
    cycles += tickCount * cyclesPerTick;

    return cycles;
}

/*********************************************************************
*
*       SEGGER_SYSVIEW_X_GetInterruptId()
*
* Function description
*   Return the currently active interrupt Id,
*   which ist the active vector taken from IPSR[5:0].
*
* Return value
*   The current currently active interrupt Id.
*
* Additional information
*   This function is not used by default, as the active vector can be 
*   read from ICSR instead on Cortex-M0.
*   For Cortex-M0+ devices, change SEGGER_SYSVIEW_GET_INTERRUPT_ID
*   in SEGGER_SYSVIEW_Conf.h to call this function instead.
*/
U32 SEGGER_SYSVIEW_X_GetInterruptId(void)
{
    U32 Id = __get_IPSR();
    Id &= 0x3F;

    return Id;
}
