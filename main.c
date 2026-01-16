/******************************************************************************
* File Name: main.c
*
* Description: This is the source code for the FreeRTOS
*              LE Long Range Central Example for ModusToolbox.
*
* Related Document: See README.md
*
*
*******************************************************************************
 * (c) 2021-2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 * This software, associated documentation and materials ("Software") is
 * owned by Infineon Technologies AG or one of its affiliates ("Infineon")
 * and is protected by and subject to worldwide patent protection, worldwide
 * copyright laws, and international treaty provisions. Therefore, you may use
 * this Software only as provided in the license agreement accompanying the
 * software package from which you obtained this Software. If no license
 * agreement applies, then any use, reproduction, modification, translation, or
 * compilation of this Software is prohibited without the express written
 * permission of Infineon.
 *
 * Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE
 * IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF
 * THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A
 * SPECIFIC USE/PURPOSE OR MERCHANTABILITY.
 * Infineon reserves the right to make changes to the Software without notice.
 * You are responsible for properly designing, programming, and testing the
 * functionality and safety of your intended application of the Software, as
 * well as complying with any legal requirements related to its use. Infineon
 * does not guarantee that the Software will be free from intrusion, data theft
 * or loss, or other breaches ("Security Breaches"), and Infineon shall have
 * no liability arising out of any Security Breaches. Unless otherwise
 * explicitly approved by Infineon, the Software may not be used in any
 * application where a failure of the Product or any consequences of the use
 * thereof can reasonably be expected to result in personal injury.
*******************************************************************************/

/*******************************************************************************
 * Header file includes
 ******************************************************************************/
#include "FreeRTOSConfig.h"
#include <FreeRTOS.h>
#include "task.h"

#include "wiced_bt_dev.h"
#include "wiced_bt_trace.h"
#include "wiced_bt_types.h"

#include "cy_pdl.h"
#include "cybsp.h"
#include "cybsp_types.h"

#include "cybt_platform_config.h"
#include "cybt_platform_hci.h"
#include "cybt_platform_trace.h"
#include "cybt_result.h"
#include "cycfg.h"
#include "cyhal.h"
#include "mtb_kvstore.h"
#include "app_serial_flash.h"
#include "cybsp_bt_config.h"
#include "cy_retarget_io.h"

#include "hello_client.h"
#include "user_oled.h"
#ifdef ENABLE_BT_SPY_LOG
#include "cybt_debug_uart.h"
#endif

/*******************************************************************************
 * Global Variables
 ******************************************************************************/
extern mtb_kvstore_bd_t block_device;

/*******************************************************************************
* Function Definitions
*******************************************************************************/

/*******************************************************************************
* Function Name : main
* ******************************************************************************
* Summary :
*   Entry point to the application. Set device configuration and start BT
*  freeRTOS tasks and initialization.
*
* Parameters:
*    None
*
* Return:
*    None
*******************************************************************************/
int main()
{
    cy_rslt_t result;

    /* Initialize the board support package */
    result = cybsp_init();

    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* Enable global interrupts */
    __enable_irq();

#ifdef ENABLE_BT_SPY_LOG
        cybt_debug_uart_config_t config = {
            .uart_tx_pin = CYBSP_DEBUG_UART_TX,
            .uart_rx_pin = CYBSP_DEBUG_UART_RX,
            .uart_cts_pin = CYBSP_DEBUG_UART_CTS,
            .uart_rts_pin = CYBSP_DEBUG_UART_RTS,
            .baud_rate = DEBUG_UART_BAUDRATE,
            .flow_control = TRUE};
        cybt_debug_uart_init(&config, NULL);
#else
    /* Initialize retarget-io to use the debug UART port */
    cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);
#endif // ENABLE_BT_SPY_LOG

    cybt_platform_set_trace_level(CYBT_TRACE_ID_STACK, CYBT_TRACE_ID_MAX);
    cybt_platform_config_init(&cybsp_bt_platform_cfg);

    /* \x1b[2J\x1b[;H - ANSI ESC sequence to clear screen */
    printf("\x1b[2J\x1b[;H");
    printf("==============================================\r\n");
    printf("Bluetooth LE-LR Client\n");
    printf("===============================================\r\n\n");

    /*Initialize the block device used by kv-store for performing read/write operations to the flash*/
    app_kvstore_bd_init(&block_device);

#ifdef USE_OLED_DISP
    /* Init OLED display */
    result = oled_init();
    if (result != CY_RSLT_SUCCESS)
    {
        printf("OLED initialization failed!\r\n");
        CY_ASSERT(0);
    }
    oled_clear_screen();
    oled_init_screen();
#endif
    /* Start application */
    application_start();

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    /* Should never get here */
    CY_ASSERT(0);
}
