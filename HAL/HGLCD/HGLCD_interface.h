/**
 * @file HLCD_interface.h
 * @author TarekHisham (tarekhesham2017@gmail.com@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*Header file guard*/
#ifndef __HGLCD_INTERFACE_H__
#define __HGLCD_INTERFACE_H__

/***************************************************************************************************/
/*                                         Interfacing macros                                      */
/***************************************************************************************************/
#define CHIP1                            (1)
#define CHIP2                            (2)

#define NO_PAGES                         (8)
#define NO_COLUMNS                       (128)
#define NO_CH_COLUMNS                    (64)

/***************************************************************************************************/
/*                                 Interfacing functions like macro                                */
/***************************************************************************************************/

/*Commands Lists*/
#define DISPLAY_ON                        (0x3F)
#define DISPLAY_OFF                       (0x3E)
#define SET_Y_ADD(COLUMN)                 (0x40 | COLUMN)
#define SET_PAGE(PAGE)                    (0xb8 | PAGE)
#define SET_Z_ADD(ADD)                    (0xc0 | ADD)

/***************************************************************************************************/
/*                                        Functions' prototypes                                    */
/***************************************************************************************************/

/**
 * @brief This function to itialize glcd
 * 
 */
void hglcd_init(void);

/**
 * @brief This function to display photo
 * 
 * @param pu8_photo 
 */
void hglcd_displayphoto(const u8_t* pu8_photo);

void hglcd_displayBegin(const u8_t* pu8_begin);


#endif /*__HGLCD_INTERFACE_H__*/