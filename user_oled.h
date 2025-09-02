/*******************************************************************************
* File Name:   user_oled.h
*
* Description: This is the header file for the oled.c
*
* Related Document: See README.md
*
*
********************************************************************************
* Copyright 2021-2025, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

/*******************************************************************************
 * Include guard
 ******************************************************************************/
#ifndef _USER_OLED_H_
#define _USER_OLED_H_

/*******************************************************************************
 * Header file includes
 ******************************************************************************/
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"

/*******************************************************************************
 * Macro Definitions
 ******************************************************************************/
#define SSD1309_I2C_ADDRESS                             0x3C

#define SSD1309_LCDWIDTH                                128u
#define SSD1309_LCDHEIGHT                               64u

#define SSD1309_SETCONTRAST                             0x81
#define SSD1309_DISPLAY_RAM                             0xA4
#define SSD1309_DISPLAYALLON                            0xA5
#define SSD1309_DISPLAY_NORMAL                          0xA6
#define SSD1309_DISPLAY_INVERTED                        0xA7
#define SSD1309_DISPLAYOFF                              0xAE
#define SSD1309_DISPLAYON                               0xAF

#define SSD1309_SETSTARTLINE                            0x40
#define SSD1309_SETDISPLAYOFFSET                        0xD3
#define SSD1309_SETCOMPINS                              0xDA
#define SSD1309_SETVCOMDETECT                           0xDB
#define SSD1309_SETDISPLAYCLOCKDIV                      0xD5
#define SSD1309_SETPRECHARGE                            0xD9
#define SSD1309_SETMULTIPLEX                            0xA8
#define SSD1309_SETLOWCOLUMN                            0x00
#define SSD1309_SETHIGHCOLUMN                           0x10


#define SSD1309_MEMORYMODE                              0x20
#define SSD1309_COLUMNADDR                              0x21
#define SSD1309_PAGEADDR                                0x22
#define SSD1309_COMSCANINC                              0xC0
#define SSD1309_COMSCANDEC                              0xC8
#define SSD1309_SEGREMAP                                0xA0
#define SSD1309_CHARGEPUMP                              0x8D

#define SSD1309_EXTERNALVCC                             0x01
#define SSD1309_SWITCHCAPVCC                            0x02

#define SSD1309_ACTIVATE_SCROLL                         0x2F
#define SSD1309_DEACTIVATE_SCROLL                       0x2E
#define SSD1309_LEFT_HORIZONTAL_SCROLL                  0x27
#define SSD1309_RIGHT_HORIZONTAL_SCROLL                 0x26
#define SSD1309_SET_VERTICAL_SCROLL_AREA                0xA3
#define SSD1309_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL    0x29
#define SSD1309_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL     0x2A

/*******************************************************************************
 * Function Prototypes
 ******************************************************************************/
cy_rslt_t oled_init(void);
void oled_clear_screen(void);
void oled_init_screen(void);
void oled_printText(uint8_t line, uint8_t x, char data[]);
void oled_printLargeText(uint8_t line, uint8_t x, char data[]);

#endif /* _USER_OLED_H_ */

/* [] END OF FILE */