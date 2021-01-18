#pragma once

#ifndef LCD_TBIRD3_H
#define LCD_TBIRD3_H

#define F_CPU 8000000

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

#include "utils.h"

#define LCD_PIN_D7 _BV(PE7)
#define LCD_PIN_D6 _BV(PE6)
#define LCD_PIN_D5 _BV(PE5)
#define LCD_PIN_D4 _BV(PE4)
#define LCD_PIN_EN _BV(PF3)
#define LCD_PIN_RW _BV(PF2)
#define LCD_PIN_RS _BV(PF1)

#define LCD_DIR_RD 1
#define LCD_DIR_WR 0

#define LCD_CTRL_REGISTER 0
#define LCD_DATA_REGISTER 1

#define LCD_CMD_CLRDISP 0x01
#define LCD_CMD_RETHOME 0x02
#define LCD_CMD_ENTMODE 0x04
#define LCD_CMD_DSPCTRL 0x08
#define LCD_CMD_CDSHIFT 0x10
#define LCD_CMD_FUNCSET 0x20
#define LCD_CMD_CGRAMAD 0x40
#define LCD_CMD_DDRAMAD 0x80

#define LCD_EMPTY_LINE ((char[]){0x00})
	
void _writeRegister(int, uint8_t);

void sendCmd(uint8_t);
void sendByte(uint8_t);

void initLcd();

void createChar(uint8_t, char*);

void writeLcd(char*, int);

int writeLcdHun(char*, const char*, const char*, const char*);

#endif