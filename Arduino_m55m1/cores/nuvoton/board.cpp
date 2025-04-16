
#include "Arduino.h"
extern void CLK_EnableModuleClock(uint32_t);
#ifdef __cplusplus
extern "C" {
#endif

/** Tick Counter united by ms */
static volatile uint32_t _dwTickCount = 0 ;

/**
 * \brief SysTick_Handler.
 */
void SysTick_Handler(void)
{
    /* Increment counter necessary in delay(). */
    _dwTickCount++;
}

/**
 *  \brief Get current Tick Count, in ms.
 */
uint32_t GetTickCount(void)
{
    return _dwTickCount ;
}

#ifdef __cplusplus
}
#endif
//---------------------------------------------------------------------------

void Enable_All_IPs(void)
{

    /*M467SJ: PA, PB, PC, PF*/
    CLK_EnableModuleClock(GPIOA_MODULE);
    CLK_EnableModuleClock(GPIOB_MODULE);
    CLK_EnableModuleClock(GPIOC_MODULE);

    CLK_EnableModuleClock(UART0_MODULE);

}
//F_CPU
void init(void)
{
    init_flag = 1;
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable PLL0 180MHz clock from HIRC and switch SCLK clock source to PLL0 */
    CLK_SetBusClock(CLK_SCLKSEL_SCLKSEL_APLL0, CLK_APLLCTL_APLLSRC_HXT, FREQ_200MHZ);
    /* Set core clock to 192MHz */
    CLK_SetCoreClock(F_CPU);



    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set Systick to 1ms interval */
    if (SysTick_Config(F_CPU / 1000))
    {
        // Capture error
        while (true);
    }

    /* To update the variable SystemCoreClock */
    SystemCoreClockUpdate();
    /* Enable All of IP */
    Enable_All_IPs();
#if defined(__M460MINIMA__)    
    /* Do not Lock protected register for code jumping*/
    // Not to Lock
#else
    /* Lock protected registers */
    SYS_LockReg();
#endif    
}
