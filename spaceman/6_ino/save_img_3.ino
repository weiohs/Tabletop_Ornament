#include <Arduino.h>
#include <EEPROM.h>
#define SECTOR_START 255

static const unsigned char spaceman[5][6016]  = {
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0xE0,0x01,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC7,0x7F,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xFC,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xFC,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0xFC,0x07,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0x00,0xFC,0x67,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0xFC,0xCF,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x00,0xF8,0x8F,0x8F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0xF8,0x8F,0x8F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0xF0,0x0F,0x83,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,
0x00,0xE0,0x0F,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0xC0,0x0F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x80,0x0F,0x0C,0x80,0x01,0x00,0x00,0x00,0x40,0x00,0x0C,0x00,0x00,0x0E,0x18,0xC0,0x03,0x00,0x00,0x00,0xC0,0x00,0x78,0x00,0x00,0x0C,0x30,0x40,0x03,0x00,0x00,0x00,0x80,0x00,0x78,0x00,0x00,0x06,0x30,
0xC0,0x03,0x00,0x00,0x00,0xC0,0x00,0xF8,0x00,0x00,0x06,0x60,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0xF0,0x01,0x00,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x01,0x80,0x1F,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x39,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0xF0,0x73,0x00,0x81,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0x7C,0xE6,0x00,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xDF,0xCC,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF7,0xD8,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x80,0xE1,0xD9,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0xC0,0xE0,0xF3,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0xC1,0xE3,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x81,0xFF,0x06,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0xDD,0x67,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x8F,0x66,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xDB,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0xF6,0x8C,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x98,0x1F,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x3F,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xEE,0x27,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x05,0x00,0x00,0xFC,0x33,0x00,0x00,0x00,0x00,
0x00,0x00,0x80,0x0F,0x00,0x00,0xF0,0x39,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0xE0,0x0F,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB0,0x07,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x0C,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x40,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xC0,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0xC0,0x00,
0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x61,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xC3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC3,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x81,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xF7,0x7F,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0xFF,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xFF,0x01,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xFF,0x03,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x31,0x00,0xFF,0x03,0x1B,0x00,0x00,0x00,0x00,
0x00,0x00,0x80,0x19,0x00,0xFF,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x19,0x00,0xFE,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x1C,0x00,0xFE,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xFE,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xFC,0x0F,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,
0x00,0xF8,0x0F,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xF8,0x0F,0x6C,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xF0,0x0F,0x7C,0x38,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xC0,0x0F,0x78,0x18,0x00,0x00,0x00,0x00,0x00,0xC0,0x38,0x00,0x80,0x0F,0x30,0x10,0x00,0x00,0x00,0x00,0x00,0x80,0x79,0x00,0x00,0x06,0x30,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x00,0x06,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x00,0x07,0xC0,0x00,0x0C,0x00,0x00,0x00,0x00,0x07,0xE0,0x03,0x80,0x0F,0xC0,0x01,0x1E,0x00,0x00,0x00,0x80,0x0C,0xE0,0x03,0xC0,0x19,0x80,0x01,0x16,0x00,0x00,0x00,0x80,0x0D,0xC0,0x03,0xF0,0x70,0x00,0x03,0x1E,0x00,0x00,
0x00,0x00,0x07,0x00,0x0F,0x3C,0xE0,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x7F,0xC6,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x6F,0xC6,0x01,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xCC,0xEC,0x03,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0xD8,0x38,0x03,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,
0x60,0xB0,0xF9,0x03,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xB0,0xF9,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x80,0x61,0x7F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x80,0xC1,0xC6,0x46,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x00,0xC3,0xCE,0xC6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0x7D,0x86,
0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x86,0x3B,0x8C,0x01,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCC,0x07,0x0C,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x0F,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x3E,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x33,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x07,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x03,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x68,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x80,0x00,
0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x60,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x07,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x18,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x19,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x80,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x80,0xFF,0x03,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x80,0xFF,0x03,0x38,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0x80,0xFF,0x07,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x80,0xFF,0x07,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x80,0xFF,0x0F,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x0C,0x80,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x80,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,
0x00,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xFE,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xFC,0x0F,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x18,0x00,0xF8,0x0F,0xF0,0x71,0x00,0x00,0x00,0x00,0x00,0x80,0x19,0x00,0xE0,0x07,0xF0,
0x71,0x00,0x00,0x00,0x00,0x00,0x80,0x39,0x00,0x00,0x06,0x60,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x00,0x00,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0x03,0x80,0x0F,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xE6,0x07,0xC0,0x19,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x0E,0xC6,0x1F,0xF0,0x70,0x00,0x03,0x18,0x00,0x00,
0x00,0x00,0x1E,0x0C,0x1F,0x3C,0xE0,0x00,0x06,0x08,0x00,0x00,0x00,0x00,0x12,0x18,0xFE,0x1F,0xC0,0x00,0x06,0x18,0x00,0x00,0x00,0x00,0x1E,0x38,0xF0,0xCF,0x80,0x01,0x0C,0x10,0x00,0x00,0x00,0x00,0x0C,0x30,0xC0,0xCE,0xF0,0x03,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x9C,0xF9,0x03,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xC0,0x1C,0x9B,0x03,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x38,0xF6,0x03,0x60,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x71,0x76,0x03,0xE0,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x73,0x0F,0x06,0xC0,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0xE3,0x1B,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0xE6,0x19,0x86,
0x01,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0xC6,0x1B,0x8C,0x01,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xCC,0x1F,0x0C,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x07,0x1C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x0F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x33,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x30,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0x7F,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x19,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x80,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x80,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x80,0xFF,0x03,0x58,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0x80,0xFF,0x07,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x80,0xFF,0x07,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x80,0xFF,0x0F,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x0C,0x80,0xFF,0x0F,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x80,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,
0x00,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xFE,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xFC,0x0F,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x18,0x00,0xF8,0x0F,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x19,0x00,0xE0,0x07,0xB0,
0xE3,0x00,0x00,0x00,0x00,0x00,0x80,0x39,0x00,0x00,0x06,0xE0,0xE3,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x00,0x00,0x07,0xC0,0xE1,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0x03,0x80,0x0F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE6,0x07,0xC0,0x19,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xC6,0x1F,0xF0,0x70,0x00,0x03,0x00,0x00,0x00,
0x00,0x00,0x1C,0x0C,0x1F,0x3C,0xE0,0x00,0x06,0x10,0x00,0x00,0x00,0x00,0x3E,0x18,0xFE,0x1F,0xC0,0x00,0x06,0x18,0x00,0x00,0x00,0x00,0x36,0x38,0xF0,0xCF,0x80,0x01,0x0C,0x10,0x00,0x00,0x00,0x00,0x3C,0x30,0xC0,0xCE,0xF0,0x03,0x18,0x20,0x00,0x00,0x00,0x00,0x18,0x00,0x60,0x9C,0xF9,0x03,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xC0,0x1C,0x9B,0x03,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x38,0xF6,0x03,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x71,0x76,0x03,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x73,0x0F,0x06,0xC0,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE3,0x1B,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE6,0x19,0x86,
0x01,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0xC6,0x1B,0x8C,0x01,0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x00,0xCC,0x1F,0x0C,0x03,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0xF8,0x07,0x1C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x0F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x33,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
/* (94 X 64 )*/

},{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x3F,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0x7F,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x19,0xFF,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x80,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x80,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x80,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0x80,0xFF,0x07,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x80,0xFF,0x07,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x80,0xFF,0x0F,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x0C,0x80,0xFF,0x0F,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x80,0xFF,0x0F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,
0x00,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xFF,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xFE,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0C,0x00,0xFC,0x0F,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x18,0x00,0xF8,0x0F,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x19,0x00,0xE0,0x07,0x30,
0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x39,0x00,0x00,0x06,0x60,0x43,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x00,0x00,0x07,0xC0,0xC7,0x01,0x00,0x00,0x00,0x00,0x00,0x63,0x03,0x80,0x0F,0xC0,0xC3,0x01,0x00,0x00,0x00,0x00,0x00,0xE6,0x07,0xC0,0x19,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xC6,0x1F,0xF0,0x70,0x00,0x03,0x00,0x00,0x00,
0x00,0x00,0x00,0x0C,0x1F,0x3C,0xE0,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0xFE,0x1F,0xC0,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x7C,0x38,0xF0,0xCF,0x80,0x01,0x0C,0x20,0x00,0x00,0x00,0x00,0x6C,0x30,0xC0,0xCE,0xF0,0x03,0x18,0x20,0x00,0x00,0x00,0x00,0x7C,0x00,0x60,0x9C,0xF9,0x03,0x18,0x00,0x00,0x00,0x00,0x00,0x38,0x00,
0xC0,0x1C,0x9B,0x03,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x38,0xF6,0x03,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x71,0x76,0x03,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x73,0x0F,0x06,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE3,0x1B,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE6,0x19,0x86,
0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC6,0x1B,0x8C,0x01,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x00,0xCC,0x1F,0x0C,0x03,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x00,0xF8,0x07,0x1C,0x06,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x38,0x0F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x33,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,
0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
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
  int c = 3;
  save_img(c*5, spaceman[0]);
  save_img(c*5+1, spaceman[1]);
  save_img(c*5+2, spaceman[2]);
  save_img(c*5+3, spaceman[3]);
  save_img(c*5+4, spaceman[4]);
  
}

void loop(void) {
  
  
}