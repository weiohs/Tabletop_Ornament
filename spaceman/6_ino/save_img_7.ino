#include <Arduino.h>
#include <EEPROM.h>
#define SECTOR_START 255

static const unsigned char spaceman[5][6016]  = {
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xE0,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xF0,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC1,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x07,0xC3,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x06,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0x79,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x02,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xFC,0x01,0x03,0x0E,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0xFF,0x07,0x06,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x98,0xFF,0x0F,0x06,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDC,0xFF,0x1F,0x0C,0x1E,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0xFF,0x3F,0x0C,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0xFF,0x7F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,
0xFF,0x7F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0xFF,0x0C,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0xFF,0x0C,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0xFF,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0xFF,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0xFF,0x1E,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0xFF,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0x7F,0xE3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0xFF,0xC3,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0xFF,0xFF,0x8D,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDC,0xFF,0xFF,0x3C,0x06,0x30,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0xFF,0x3F,0x70,0x0E,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xFE,0x1F,0x60,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xF0,0x03,0xC0,0xFB,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x03,0xB0,0xF1,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x0F,0xF8,0x9B,0x01,0x0C,0x00,0x00,0x00,0x00,0x04,0x80,
0x01,0x0F,0xD8,0x8E,0x03,0x00,0x00,0x00,0x00,0x00,0x0E,0x80,0x01,0x0F,0xD8,0x06,0x03,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x03,0xDE,0x79,0x0F,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xFE,0xA3,0x0D,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x74,0x03,0x18,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x7C,0x03,0x18,
0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xFC,0x0F,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x18,0xD8,0xCF,0xB8,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x10,0xF0,0xC3,0xFD,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x87,0x6F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x9C,0x73,0x03,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x60,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x03,0x00,0x62,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x03,0x00,0xE6,0x81,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x03,0x00,0x0C,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
0x01,0x00,0x0C,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xE0,0x0F,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x06,0x07,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x7F,0x78,0x0C,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x1F,0xE0,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x03,0xC0,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x01,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0xFF,0x01,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x98,0xFF,0x07,0x06,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDC,0xFF,0x0F,0x0C,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0xFF,0x1F,0x0C,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x1F,0x0C,0x78,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,
0xFF,0x3F,0x0C,0x30,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x3F,0x0C,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x7F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x7F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x7F,0x0F,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x7F,0x0F,0x00,
0x00,0x01,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x7F,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0x3F,0x73,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0xBF,0xC3,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0xDF,0x8D,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xFF,0xFF,0x1C,0x07,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0x3F,0x30,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x1F,0x60,0x1F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x03,0xC0,0x1B,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x07,0xB8,0x9F,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
0x01,0x0F,0x7C,0x8F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x0E,0x64,0x07,0x03,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1E,0x7C,0x0F,0x06,0x10,0x00,0x00,0x00,0x00,0x18,0x00,0x06,0xFE,0xBC,0x0D,0x0C,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x06,0xFC,0x01,0x0C,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0xBC,0x01,0x18,
0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xF8,0x0D,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0xD8,0x6F,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xF0,0xE3,0xBC,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x60,0x00,0xC3,0x67,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0xCE,0x33,0x03,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x40,0x00,0xFC,0x1F,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0xC6,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x07,0x00,0x0C,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
0x0D,0x00,0x0C,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x0F,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xE0,0x0F,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x06,0x02,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x7F,0x78,0x0C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x1F,0xE0,0x1C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x03,0xC0,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x01,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0xFF,0x01,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x98,0xFF,0x07,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDC,0xFF,0x0F,0x0C,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0xFF,0x1F,0x0C,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x1F,0x0C,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,
0xFF,0x3F,0x0C,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x3F,0x0C,0x70,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x7F,0x0F,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x7F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x7F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x7F,0x0F,0x00,
0x00,0x03,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x7F,0x3E,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0x3F,0x73,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0xBF,0xC3,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0xDF,0x8D,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xFF,0xFF,0x1C,0x07,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0x3F,0x30,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x1F,0x60,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x03,0xC0,0x1B,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x19,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x07,0xB8,0x9F,0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
0x01,0x0F,0x7C,0x8F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x0E,0x64,0x07,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1E,0x7C,0x0F,0x06,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xFE,0xBC,0x0D,0x0C,0x20,0x00,0x00,0x00,0x00,0x30,0x00,0x06,0xFC,0x01,0x0C,0x1C,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x0C,0xBC,0x01,0x18,
0x18,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x18,0xF8,0x0D,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0xD8,0x6F,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xF0,0xE3,0xBC,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0xC3,0x67,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xC0,0x00,0xCE,0x33,0x03,0x00,0x00,0x00,
0x00,0x00,0x00,0x06,0x40,0x00,0xFC,0x1F,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x70,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC4,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x0C,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x0F,0x00,0x0C,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0D,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xC0,0x0F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0x03,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x06,0x60,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x0F,0x78,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0F,0xE0,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x03,0xC0,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x80,0x33,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x63,0x38,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x58,0x1C,0x00,0x66,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x98,0xFF,0x00,0x46,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0xFF,0x03,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x07,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x07,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,
0xFF,0x0F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x1F,0x0E,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x1F,0x0F,0xC0,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x1F,0x0F,0x60,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x1F,0x0F,0xC0,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x3F,0x06,0x00,
0x60,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x3F,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0x1F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0x9F,0xE3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0xDF,0xC7,0x01,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0xC0,0xFF,0xEF,0x0E,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0x3F,0x3C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x1F,0x70,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x03,0xE0,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x1D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x0F,0x1E,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x3E,0x07,0x02,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x33,0x0F,0x06,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0xDE,0x0D,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0xFC,0xDC,0x18,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0xFC,0x00,0x18,
0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xF8,0x0C,0x18,0x10,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x38,0xD8,0x2F,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x01,0x30,0xF0,0x63,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x60,0x00,0xC3,0x67,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xCE,0x33,0x03,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xC0,0x00,0xFC,0x1F,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x78,0x0F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xE0,0x03,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x01,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x08,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6C,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xC0,0x0F,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x7F,0xE0,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x06,0x80,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x0F,0x78,0x0C,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0F,0xE0,0x1C,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x03,0xC0,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x80,0x33,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x63,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x58,0x1C,0x00,0x66,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x98,0xFF,0x00,0x46,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0xFF,0x03,0x0C,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x07,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x07,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,
0xFF,0x0F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x1F,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x1F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0x1F,0x0F,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x1F,0x0F,0x80,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x3F,0x06,0x80,
0x0D,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,0x3F,0x1E,0x80,0x8F,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0x1F,0x3F,0x00,0x87,0x01,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0x9F,0xE3,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0xDF,0xC7,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xFF,0xEF,0x0E,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0x3F,0x3C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x1F,0x70,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x03,0xE0,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x03,0xC0,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x1D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x0F,0x1E,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x3E,0x07,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x33,0x0F,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0xDE,0x0D,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0xFC,0xDC,0x18,0x0C,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0xFC,0x00,0x18,
0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xF8,0x0C,0x18,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0xD8,0x2F,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xF0,0x63,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0xC3,0x67,0x03,0x00,0x00,0x00,0x00,0x00,0xC0,0x03,0xC0,0x00,0xCE,0x33,0x03,0x00,0x00,0x00,
0x00,0x00,0x80,0x07,0xC0,0x00,0xFC,0x1F,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x80,0x01,0x78,0x0F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xE0,0x03,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x60,
0x00,0x00,0x08,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

}

};


void save_img(int index, const unsigned char * str){
  EEPROMClass MYROM_0(2*index + SECTOR_START);
  MYROM_0.begin(3008);
  for(int i = 0 ; i < 3008; i++){
    MYROM_0.write(i, str[i]);
  }
  MYROM_0.commit();
  MYROM_0.end();

  EEPROMClass MYROM_1(2*index + 1 + SECTOR_START);
  MYROM_1.begin(3008);
  for(int i = 0 ; i < 3008; i++){
    MYROM_1.write(i, str[ i + 3008]);
  }
  MYROM_1.commit();
  MYROM_1.end();
}




void setup(void) {
  Serial.begin(115200);
  int c = 7;
  save_img(c*5, spaceman[0]);
  save_img(c*5+1, spaceman[1]);
  save_img(c*5+2, spaceman[2]);
  save_img(c*5+3, spaceman[3]);
  save_img(c*5+4, spaceman[4]);
  
}

void loop(void) {
  
  
}