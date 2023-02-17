#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HGLCD_cfg.h"
#include "HGLCD_interface.h"
#include "util/delay.h"

static void send_command(u8_t au8_command)
{
    mdio_setPortData(GLCD_DATA_LINE_PORT , au8_command);
    _delay_ms(2);
    mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_RS_PIN , LOW);
    mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_RW_PIN , LOW);
    mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_EN_PIN , HIGH);
    _delay_ms(2);
    mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_EN_PIN , LOW);
    
/*Return Fnction*/
return;
}

static void send_data(u8_t au8_data)
{
    mdio_setPortData(GLCD_DATA_LINE_PORT , au8_data);
    _delay_ms(2);
    mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_RS_PIN , HIGH);
    mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_RW_PIN , LOW);
    mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_EN_PIN , HIGH);
    _delay_ms(2);
    mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_EN_PIN , LOW);
    
/*Return Fnction*/
return;
}

static void select_chip(u8_t au8_chip)
{
    switch(au8_chip)
    {
        case CHIP1 :
        mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_CS2_PIN , HIGH);
        mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_CS1_PIN , LOW);
        break;
        
        case CHIP2 :
        mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_CS1_PIN , HIGH);
        mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_CS2_PIN , LOW);
        break;
        
        default :
        break;
    }
/*Return Function*/
return;
}

void hglcd_init(void)
{
    mdio_setPortStatus(GLCD_DATA_LINE_PORT , OUTPUT);
    mdio_setPinStatus(GLCD_CTR_LINE_PORT , (GLCD_RS_PIN | GLCD_RW_PIN | GLCD_EN_PIN | GLCD_CS1_PIN | GLCD_CS2_PIN | GLCD_RST_PIN) , OUTPUT);

    mdio_setPinValue(GLCD_CTR_LINE_PORT , GLCD_RST_PIN , HIGH);
    _delay_ms(2);

    select_chip(CHIP1);
    send_command(SET_PAGE(0));
    send_command(SET_Y_ADD(0));
    send_command(DISPLAY_ON);

    select_chip(CHIP2);
    send_command(SET_PAGE(0));
    send_command(SET_Y_ADD(0));
    send_command(DISPLAY_ON);
    
/*Return Function*/
return;
}

void hglcd_displayphoto(const u8_t* pu8_photo)
{
u8_t column = 0 ;

for(u8_t page = 0 ; page < NO_PAGES ; page++)
{
  select_chip(CHIP1);
  send_command(SET_PAGE(page));
  send_command(SET_Y_ADD(0));

for( column = 0 ; column < NO_COLUMNS ; column++)
{
    if(column == NO_CH_COLUMNS)
    {
        select_chip(CHIP2);
        send_command(SET_PAGE(page));
        send_command(SET_Y_ADD(0));
    }
    else
    {
        /*Do Nothing*/
    }

    /*sending photo data*/
    send_data(*pu8_photo++);    
}
}

/*Return Function*/
return;
}

void hglcd_displayBegin(const u8_t* pu8_begin)
{

send_command(SET_Z_ADD(8));
  
send_data(*pu8_begin);

}