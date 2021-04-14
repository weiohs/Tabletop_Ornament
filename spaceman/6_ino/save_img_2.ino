#include <Arduino.h>
#include <EEPROM.h>
#define SECTOR_START 255

static const unsigned char spaceman[5][6016]  = {
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xE0,0x8F,0xE3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0x03,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x06,0xF0,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x07,0x78,0x0C,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0xF8,0x1C,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xF0,0x19,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xE0,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0xC0,0x07,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0x00,0x80,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x0E,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x0C,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,
0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x0C,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x0C,0x80,0x01,0x06,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0x06,0x00,
0x00,0x06,0x00,0x00,0x00,0x00,0x00,0xF8,0x01,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x01,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x03,0x80,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x03,0xC0,0xC1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x07,0xF0,0xC0,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0x3C,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0xFE,0x3F,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0xF0,0x6B,0x00,0x06,0x00,0x18,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0xDA,0x00,0x0C,0x18,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB6,0x01,0x0C,0x18,0x38,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x66,0x03,0x06,0x30,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC6,0x07,0x07,0x60,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x01,0xCC,0xC6,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x03,0x8C,0xFD,0x06,0xC0,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x03,0xD8,0xFB,0x0D,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xF8,0x87,0x0D,
0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x30,0x86,0x0D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x70,0x06,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x18,0xE0,0x07,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x30,0x80,0x0F,0x2F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0x60,0x00,0xBC,0x3F,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xF0,0x60,0x00,0xF0,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0xC0,0x00,0x60,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x60,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0xC0,0x23,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x06,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x0E,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0C,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x19,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0x1F,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x1E,0x06,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x07,0x7C,0x0C,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0xFC,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xF8,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0xE0,0x33,0x80,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0xC0,0x63,0x80,0x07,0x00,0x00,0x00,
0x00,0x00,0x00,0x78,0x00,0x80,0x67,0x80,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x20,0xC6,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x30,0x8C,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x8C,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,
0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0C,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0C,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x1E,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x80,0xE7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0xC0,0xCD,0x01,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xE0,0xB8,0x03,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x03,0x38,0x70,0x07,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0x1C,0xF0,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x07,0xE0,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x07,0xC0,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x07,0xC0,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x0D,0x80,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x1D,0x80,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x00,0x80,0x1D,0xC0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x3B,0xE0,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x7B,0xB0,0x0D,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x72,0x9C,0x18,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x0F,0x18,
0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0xFE,0x0F,0x18,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x03,0x1C,0xCC,0xCF,0x38,0x01,0x06,0x00,0x00,0x00,0x00,0x00,0x03,0x18,0xFC,0x83,0x7D,0x03,0x04,0x00,0x00,0x00,0x00,0x00,0x02,0x30,0x78,0x87,0x6F,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x8E,0x77,0x06,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x60,0x00,0xFC,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC1,0x00,0x70,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x87,0x01,0x20,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x86,0x01,0xE0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x07,0x03,0xC0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
0x07,0x06,0x18,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x38,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x30,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x60,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x26,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x87,0x77,0x7C,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0xE6,0x78,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xE0,0x19,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xE0,0x33,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0xC0,0x67,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0x00,0xC0,0x67,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x80,0xCF,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x80,0x8F,0x01,0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x8F,0x03,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0E,0x03,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,
0x00,0x00,0x0C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x0C,0x18,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x0C,0x10,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x06,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x80,0x3B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x67,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0xF0,0xCF,0x00,0x30,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0x3E,0x8F,0x01,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x1F,0x1B,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x07,0x1E,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xB6,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xEC,0x0D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x03,0xF8,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xD8,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xB0,0x37,0x00,0x00,0x00,0x00,0x00,0x00,0x28,0x00,0x00,0x0C,0x30,0x67,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x0C,0x38,0x4C,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x18,0x1C,0x0C,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x1E,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB0,0x3B,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x77,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0xCE,0x27,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x60,0x00,0xBC,0x33,0x04,0x00,0x00,0x00,
0x00,0x00,0x00,0x0C,0x60,0x00,0xF0,0x39,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x60,0x0F,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0xE0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x1F,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x0E,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x0C,0x20,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x18,0x60,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xC0,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xC0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x06,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x87,0x77,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0xE6,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xE0,0xD9,0x71,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xE0,0xF3,0x71,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0xC0,0xE7,0x70,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0x00,0xC0,0x67,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x80,0xCF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x80,0x8F,0x01,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x8F,0x03,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0E,0x03,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,
0x00,0x00,0x0C,0x06,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0C,0x0C,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x0C,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x0C,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x06,0x00,
0x18,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x06,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x1F,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x80,0x3B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x67,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0xF0,0xCF,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0x3E,0x8F,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x1F,0x1B,0x03,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x07,0x1E,0x07,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xB6,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xEC,0x0D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x03,0xF8,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xD8,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xB0,0x37,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x30,0x67,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x38,0x4C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x1C,0x0C,
0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x01,0x00,0x30,0x1E,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x01,0x00,0xB0,0x3B,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0xE0,0x77,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCE,0x27,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0xBC,0x33,0x04,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x60,0x00,0xF0,0x39,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0xC0,0x00,0x60,0x0F,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x80,0x01,0xE0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x0E,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x0C,0x20,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6C,0x18,0x60,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x30,0xC0,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x30,0xC0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x06,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x87,0x77,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0xE6,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xE0,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xE0,0xB3,0x61,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0xC0,0xE7,0xE3,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0x00,0xC0,0xE7,0xE1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x80,0xCF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x80,0x8F,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x8F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0E,0x03,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,
0x00,0x00,0x0C,0x06,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x0C,0x0C,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x0C,0x0C,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x0C,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x0C,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x06,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x1F,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x80,0x3B,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x67,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x80,0x03,0xF0,0xCF,0x00,0x00,0x00,0x00,0x00,
0x00,0x80,0x00,0x00,0x1F,0x3E,0x8F,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x1F,0x1B,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x07,0x1E,0x07,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xB6,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xEC,0x0D,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x03,0xF8,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xD8,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xB0,0x37,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x30,0x67,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x38,0x4C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x1C,0x0C,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x1E,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x01,0x00,0xB0,0x3B,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x03,0x00,0xE0,0x77,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x00,0xCE,0x27,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0xBC,0x33,0x04,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x60,0x00,0xF0,0x39,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x60,0x0F,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x80,0x01,0xE0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x80,0x01,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x0C,0x20,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x18,0x60,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x58,0x30,0xC0,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x30,0xC0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
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
  int c = 2;
  save_img(c*5, spaceman[0]);
  save_img(c*5+1, spaceman[1]);
  save_img(c*5+2, spaceman[2]);
  save_img(c*5+3, spaceman[3]);
  save_img(c*5+4, spaceman[4]);
  
}

void loop(void) {
  
  
}