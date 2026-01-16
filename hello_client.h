/*******************************************************************************
* File Name:   hello_client.h
*
* Description: This is the header file for the hello_client.c
*
* Related Document: See README.md
*
*
********************************************************************************
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
 *        Macro Definitions
 ******************************************************************************/
#pragma once

#define HELLO_CLIENT_MAX_NUM_CLIENTS 1

/* Hello Sensor App Timer Timeout in seconds  */
#define HELLO_CLIENT_APP_TIMEOUT_IN_SECONDS                 1

/* Hello Sensor App Fine Timer Timeout in milli seconds  */
#define HELLO_CLIENT_APP_FINE_TIMEOUT_IN_MS                 1

/* Hello Sensor Connection Idle  Timeout in milli seconds  */
#define HELLO_CLIENT_CONN_IDLE_TIMEOUT_IN_SECONDS           3

#define HELLO_CLIENT_VS_ID                  100
#define HELLO_CLIENT_LOCAL_KEYS_VS_ID       101
#define HELLO_CLIENT_PAIRED_KEYS_VS_ID      102

/*******************************************************************************
 * Function Prototypes
 ******************************************************************************/
void application_start(void);

/* [] END OF FILE */