#include <compiler.h> // Dialog SDK

extern void BLE_WAKEUP_LP_Handler(void);
extern void rwble_isr(void);

void IRQ_BLE_WAKEUP_LP_Handler(void)
{
    BLE_WAKEUP_LP_Handler();
}

void IRQ_rwble_isr(void)
{
    rwble_isr();
}

void IRQ_UART_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_UART2_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_I2C_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_SPI_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_ADC_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_KEYBRD_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_BLE_RF_DIAG_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_RFCAL_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_GPIO0_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_GPIO1_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_GPIO2_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_GPIO3_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_GPIO4_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_SWTIM_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_WKUP_QUADEC_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_SWTIM1_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_RTC_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_DMA_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}

void IRQ_XTAL32M_RDY_Handler(void)
{
    __BKPT(0);
    while (1)
    {
        __NOP();
    }
}
