/**
 * @file HGLCD_cfg.h
 * @author TarekHisham (tarekhesham2017@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*Header file guard*/
#ifndef __HGGLCD_CFG_H__
#define __HGGLCD_CFG_H__

/***************************************************************************************************/
/*                                         Configuration macros                                    */
/***************************************************************************************************/

/*GLCD Control lines configurations*/
#define GLCD_CTR_LINE_PORT           (PORTD)
#define GLCD_RST_PIN                 (PIN5)
#define GLCD_CS1_PIN                 (PIN4)
#define GLCD_CS2_PIN                 (PIN3)
#define GLCD_RS_PIN                  (PIN2)
#define GLCD_RW_PIN                  (PIN1)
#define GLCD_EN_PIN                  (PIN0)

/*GLCD Data lines configurations*/
#define GLCD_DATA_LINE_PORT         (PORTC)
#define GLCD_D0_PIN                  (PIN0)
#define GLCD_D1_PIN                  (PIN1)
#define GLCD_D2_PIN                  (PIN2)
#define GLCD_D3_PIN                  (PIN3)
#define GLCD_D4_PIN                  (PIN4)
#define GLCD_D5_PIN                  (PIN5)
#define GLCD_D6_PIN                  (PIN6)
#define GLCD_D7_PIN                  (PIN7)



#endif /*__HGLCD_CFG_H__*/