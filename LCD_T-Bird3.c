#pragma once

#include "LCD_T-Bird3.h"

void _writeRegister(int reg, uint8_t data)
{
	if (reg)
		PORTF |= LCD_PIN_RS;
	PORTF &=~ LCD_PIN_RW;
	_delay_ms(1);
	PORTF |= LCD_PIN_EN;
	_delay_ms(1);
	PORTE |= (data & 15) << 4;
	_delay_ms(1);
	PORTF &= 0xf1;
	_delay_ms(1);
	PORTE &= 15;
	_delay_ms(1);
}

void sendCmd(uint8_t cmd)
{
	_writeRegister(LCD_CTRL_REGISTER, (cmd & 0xf0) >> 4);
	_writeRegister(LCD_CTRL_REGISTER, cmd & 0x0f);
	_delay_ms(1);
}

void sendByte(uint8_t data)
{
	_writeRegister(LCD_DATA_REGISTER, (data & 0xf0) >> 4);
	_writeRegister(LCD_DATA_REGISTER, data & 0x0f);
	_delay_ms(1);
}

void initLcd()
{
	DDRE = LCD_PIN_D7 | LCD_PIN_D6 | LCD_PIN_D5 | LCD_PIN_D4;
	DDRF = LCD_PIN_EN | LCD_PIN_RW | LCD_PIN_RS;
	
	_delay_ms(40);
	
	_writeRegister(LCD_CTRL_REGISTER, 3);
	_delay_ms(5);
	_writeRegister(LCD_CTRL_REGISTER, 3);
	_delay_ms(1);
	_writeRegister(LCD_CTRL_REGISTER, 3);
	_delay_ms(1);
	_writeRegister(LCD_CTRL_REGISTER, 2);
	
	sendCmd(LCD_CMD_FUNCSET | 8);
	sendCmd(LCD_CMD_DSPCTRL | 14);
	sendCmd(LCD_CMD_CLRDISP);
	sendCmd(LCD_CMD_ENTMODE | 2);
	sendCmd(LCD_CMD_RETHOME);
}

void createChar(uint8_t location, char charmap[])
{
	sendCmd(LCD_CMD_CGRAMAD | (location << 3));
	for (int i = 0; i < 8; i++)
		sendByte(charmap[i]);
}

void writeLcd(const char* str, int row)
{
	sendCmd(LCD_CMD_RETHOME);
	switch (row)
	{
		case 0:	sendCmd(LCD_CMD_DDRAMAD + 0x00); break;
		case 1:	sendCmd(LCD_CMD_DDRAMAD + 0x28); break;
		case 2:	sendCmd(LCD_CMD_DDRAMAD + 0x10); break;
		case 3:	sendCmd(LCD_CMD_DDRAMAD + 0x50); break;
	}

	while (*str)
	{
		sendByte(*str);
		str++;
	}
}

int writeLcdHun(const char* line0, const char* line1, const char* line2, const char* line3)
{
	char hunLetters[19] = {
		0xc1, 0xc9, 0xcd,	//Á, É, Í,
		0xd3, 0xd5, 0xd6,	//Ó, Õ, Ö,
		0xda, 0xdb, 0xdc,	//Ú, Û, Ü,
		0xe1, 0xe9, 0xed,	//á, é, í,
		0xf3, 0xf5, 0xf6,	//ó, õ, ö,
		0xfa, 0xfb, 0xfc,   //ú, û, ü
		0x00};
	
	char* replacement[19] = {
		upperAA, upperEE, upperII,
		upperOO, upperDO,    NULL,
		upperUU, upperDU,    NULL,
		lowerAA, lowerEE, lowerII,
		lowerOO, lowerDO,    NULL,
		lowerUU, lowerDU,    NULL,
	0x00};
	
	int fcnt = 0;
	char found[9];
	memset(found, 0, 9);
	
	
	
	/*for (int i = 0, found[i] > 0; i++)
		createChar(i, found[i]);
	sendCmd(LCD_CMD_DDRAMAD);*/
	
	//writeLcd(hunLetters, 1);
	
	return fcnt;
}