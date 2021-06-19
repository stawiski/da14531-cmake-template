/**
 ****************************************************************************************
 *
 * @file user_periph_setup.c
 *
 * @brief Peripherals setup and initialization.
 *
 * Copyright (c) 2015-2019 Dialog Semiconductor. All rights reserved.
 *
 * This software ("Software") is owned by Dialog Semiconductor.
 *
 * By using this Software you agree that Dialog Semiconductor retains all
 * intellectual property and proprietary rights in and to this Software and any
 * use, reproduction, disclosure or distribution of the Software without express
 * written permission or a license agreement from Dialog Semiconductor is
 * strictly prohibited. This Software is solely for use on or in conjunction
 * with Dialog Semiconductor products.
 *
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, THE
 * SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. EXCEPT AS OTHERWISE
 * PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, IN NO EVENT SHALL
 * DIALOG SEMICONDUCTOR BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF
 * USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THE SOFTWARE.
 *
 ****************************************************************************************
 */
#include <user_periph_setup.h>
#include <datasheet.h>
#include <system_library.h>
#include <rwip_config.h>
#include <syscntl.h>
#include <gpio.h>

#include <debug.h>

#if DEVELOPMENT_DEBUG
void GPIO_reservations(void)
{
}
#endif

static void set_pad_functions(void)
{
}

void periph_init(void)
{
    // Disable HW RST on P0_0
    GPIO_Disable_HW_Reset();

    // Enable DC/DC buck mode
    if (syscntl_dcdc_turn_on_in_buck(SYSCNTL_DCDC_LEVEL_1V1) != 0)
    {
        __BKPT(0);
    }

    // ROM patch
    patch_func();

    // Set pad functionality
    set_pad_functions();

    // Enable the pads
    GPIO_set_pad_latch_en(true);

#ifdef DEBUG_SEGGER
    static bool isSeggerInitialized = false;
    if (!isSeggerInitialized)
    {
        // Set up JLink RTT
        SEGGER_RTT_Init();
        DEBUG_PRINT_STRING("periph_init()\r\n");

        isSeggerInitialized = true;
    }
#endif
}
