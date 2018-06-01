

/*
 *
 * Comic_Sans_MS_13
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : Comic_Sans_MS_13.h
 * Date                : 01.10.2016
 * Font size in bytes  : 7291
 * Font width          : 10
 * Font height         : 13
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#ifdef __AVR__
#include <avr/pgmspace.h>
#elif defined (ESP8266)
#include <pgmspace.h>
#else
#define PROGMEM
#endif

#ifndef COMIC_SANS_MS_13_H
#define COMIC_SANS_MS_13_H

#define COMIC_SANS_MS_13_WIDTH 10
#define COMIC_SANS_MS_13_HEIGHT 13

const static uint8_t Comic_Sans_MS_13[] PROGMEM = {
    0x1C, 0x7B, // size
    0x0A, // width
    0x0D, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x00, 0x02, 0x05, 0x09, 0x08, 0x0A, 0x08, 0x02, 0x04, 0x03, 
    0x06, 0x06, 0x02, 0x05, 0x02, 0x06, 0x05, 0x06, 0x06, 0x05, 
    0x07, 0x05, 0x05, 0x06, 0x05, 0x05, 0x02, 0x03, 0x04, 0x05, 
    0x04, 0x06, 0x0B, 0x07, 0x06, 0x07, 0x07, 0x07, 0x06, 0x08, 
    0x07, 0x06, 0x08, 0x07, 0x06, 0x0A, 0x08, 0x09, 0x05, 0x0B, 
    0x06, 0x07, 0x08, 0x07, 0x08, 0x0C, 0x09, 0x08, 0x07, 0x04, 
    0x05, 0x04, 0x05, 0x08, 0x03, 0x06, 0x05, 0x05, 0x06, 0x06, 
    0x06, 0x05, 0x05, 0x02, 0x04, 0x06, 0x02, 0x08, 0x05, 0x05, 
    0x05, 0x05, 0x05, 0x05, 0x06, 0x05, 0x06, 0x08, 0x06, 0x06, 
    0x05, 0x04, 0x02, 0x04, 0x07, 0x04, 
    
    // font data
    0x7E, 0x7E, 0x18, 0x18, // 33
    0x1E, 0x1E, 0x00, 0x1E, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
    0xC0, 0xCC, 0xFC, 0xFF, 0xCF, 0xFC, 0xFF, 0xCF, 0xCC, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, // 35
    0x18, 0x3C, 0x36, 0xFF, 0xFF, 0x36, 0xF6, 0xE0, 0x18, 0x18, 0x18, 0x78, 0x78, 0x18, 0x08, 0x08, // 36
    0x1C, 0x3E, 0x36, 0xFE, 0x7C, 0xDC, 0xE6, 0x60, 0xE0, 0xC0, 0x00, 0x00, 0x18, 0x08, 0x00, 0x08, 0x18, 0x18, 0x18, 0x08, // 37
    0xC0, 0xE0, 0x3C, 0x3E, 0xF6, 0xCE, 0xEC, 0x60, 0x08, 0x18, 0x18, 0x18, 0x18, 0x08, 0x18, 0x10, // 38
    0x1E, 0x1E, 0x00, 0x00, // 39
    0xF0, 0xFC, 0x0E, 0x06, 0x18, 0x78, 0xE0, 0x80, // 40
    0x0E, 0xFC, 0xF0, 0xE0, 0x78, 0x18, // 41
    0x24, 0x3C, 0x1E, 0x1E, 0x3C, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 42
    0x60, 0x60, 0xF8, 0xF8, 0x60, 0x60, 0x00, 0x00, 0x08, 0x08, 0x00, 0x00, // 43
    0x00, 0x00, 0x60, 0x30, // 44
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, // 45
    0x00, 0x00, 0x18, 0x18, // 46
    0x00, 0x80, 0xC0, 0x70, 0x1E, 0x06, 0x30, 0x38, 0x08, 0x00, 0x00, 0x00, // 47
    0xF8, 0xFE, 0x06, 0xFE, 0xFC, 0x00, 0x18, 0x18, 0x18, 0x00, // 48
    0x0C, 0x0C, 0xFE, 0xFE, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, // 49
    0x8C, 0xCC, 0x66, 0x26, 0x3E, 0x1C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, // 50
    0x8C, 0x26, 0x26, 0xFE, 0xDC, 0x08, 0x18, 0x18, 0x18, 0x08, // 51
    0xC0, 0xE0, 0xD0, 0xCC, 0xFE, 0xFE, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, // 52
    0xBE, 0x3E, 0x36, 0xF6, 0xE6, 0x08, 0x18, 0x18, 0x18, 0x08, // 53
    0xF0, 0xF8, 0x3E, 0xF6, 0xE2, 0x08, 0x18, 0x18, 0x18, 0x08, // 54
    0x06, 0x06, 0xE6, 0xF6, 0x1E, 0x06, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, // 55
    0xCC, 0xFE, 0x36, 0xFE, 0xCC, 0x08, 0x18, 0x18, 0x18, 0x08, // 56
    0x3C, 0x7E, 0xE6, 0xFE, 0x7C, 0x00, 0x18, 0x18, 0x08, 0x00, // 57
    0x30, 0x30, 0x18, 0x18, // 58
    0x00, 0x30, 0x30, 0x60, 0x30, 0x00, // 59
    0x40, 0xE0, 0xB0, 0x10, 0x00, 0x00, 0x08, 0x08, // 60
    0x98, 0x98, 0x98, 0x98, 0x98, 0x08, 0x08, 0x08, 0x08, 0x08, // 61
    0x10, 0xB0, 0xE0, 0x40, 0x08, 0x08, 0x00, 0x00, // 62
    0x0C, 0x4E, 0x66, 0x26, 0x3C, 0x1C, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, // 63
    0xF8, 0xFC, 0x8E, 0x37, 0x73, 0x6B, 0x3B, 0x63, 0x66, 0x7E, 0x3C, 0x00, 0x08, 0x18, 0x38, 0x30, 0x30, 0x30, 0x38, 0x18, 0x00, 0x00, // 64
    0x00, 0xC0, 0xF0, 0xDC, 0xFE, 0xF0, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, // 65
    0xFE, 0xFE, 0x26, 0x26, 0xFC, 0xDC, 0x18, 0x18, 0x18, 0x18, 0x08, 0x08, // 66
    0xE0, 0xF8, 0x1C, 0x0E, 0x06, 0x86, 0x8E, 0x08, 0x18, 0x18, 0x18, 0x18, 0x08, 0x08, // 67
    0xFE, 0xFE, 0x04, 0x0C, 0x98, 0xF8, 0xF0, 0x08, 0x18, 0x18, 0x18, 0x18, 0x08, 0x00, // 68
    0xFE, 0xFE, 0x36, 0x36, 0x36, 0x36, 0x36, 0x08, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, // 69
    0xFE, 0xFE, 0x36, 0x36, 0x36, 0x36, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, // 70
    0xE0, 0xF8, 0x1C, 0x4E, 0x66, 0xE6, 0xEC, 0xE0, 0x08, 0x18, 0x18, 0x18, 0x18, 0x08, 0x08, 0x00, // 71
    0xFE, 0xFE, 0x60, 0x60, 0x60, 0xFE, 0xFE, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, // 72
    0x06, 0x06, 0xFE, 0xFE, 0x06, 0x06, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, // 73
    0x80, 0x80, 0x06, 0x06, 0xFE, 0xFE, 0x06, 0x06, 0x08, 0x18, 0x30, 0x30, 0x38, 0x18, 0x00, 0x00, // 74
    0xFE, 0xFE, 0x70, 0xF8, 0x9C, 0x0E, 0x06, 0x18, 0x18, 0x00, 0x00, 0x08, 0x18, 0x18, // 75
    0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, // 76
    0x80, 0xF0, 0x7E, 0x7E, 0xF0, 0xC0, 0xF8, 0x3E, 0xFE, 0xC0, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x18, 0x18, // 77
    0xFE, 0xFC, 0x18, 0x30, 0xC0, 0x80, 0xFE, 0xFE, 0x18, 0x18, 0x00, 0x00, 0x00, 0x08, 0x18, 0x18, // 78
    0xF0, 0xFC, 0x8C, 0x06, 0x06, 0x06, 0x86, 0xFC, 0x78, 0x00, 0x08, 0x18, 0x18, 0x18, 0x18, 0x08, 0x08, 0x00, // 79
    0xFE, 0xFE, 0x66, 0x7E, 0x3C, 0x18, 0x18, 0x00, 0x00, 0x00, // 80
    0xF0, 0xF8, 0x1C, 0x0E, 0x86, 0x86, 0x06, 0x06, 0x0C, 0xFC, 0xF0, 0x00, 0x18, 0x18, 0x30, 0x38, 0x38, 0x38, 0x38, 0x78, 0xF8, 0xC0, // 81
    0xFE, 0xFE, 0xC6, 0xCE, 0x7C, 0x38, 0x18, 0x18, 0x00, 0x08, 0x18, 0x18, // 82
    0x80, 0x98, 0x3C, 0x36, 0x36, 0xF6, 0xE0, 0x08, 0x18, 0x18, 0x18, 0x18, 0x08, 0x00, // 83
    0x06, 0x06, 0x06, 0xFE, 0xFE, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, // 84
    0xFE, 0xFE, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x08, 0x18, 0x18, 0x18, 0x08, 0x00, // 85
    0x0E, 0xFE, 0xF0, 0x00, 0xE0, 0xFC, 0x3E, 0x06, 0x00, 0x00, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, // 86
    0x06, 0x7E, 0xF8, 0xC0, 0xF0, 0x3E, 0x7E, 0xF0, 0x80, 0xF8, 0x3E, 0x06, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, // 87
    0x06, 0x8E, 0xDC, 0xF8, 0x70, 0xF8, 0xDC, 0x8E, 0x06, 0x18, 0x18, 0x08, 0x00, 0x00, 0x00, 0x08, 0x18, 0x18, // 88
    0x06, 0x0E, 0x3C, 0xF0, 0xE0, 0x78, 0x1E, 0x06, 0x00, 0x00, 0x18, 0x18, 0x08, 0x00, 0x00, 0x00, // 89
    0x06, 0xC6, 0xE6, 0x36, 0x1E, 0x06, 0x06, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, // 90
    0xFE, 0xFE, 0x06, 0x06, 0xF8, 0xF8, 0xC0, 0xC0, // 91
    0x06, 0x1C, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x18, 0x30, // 92
    0x06, 0x06, 0xFE, 0xFE, 0xC0, 0xC0, 0xF8, 0xF8, // 93
    0x04, 0x06, 0x03, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // 95
    0x01, 0x07, 0x06, 0x00, 0x00, 0x00, // 96
    0xC0, 0xE0, 0x30, 0x30, 0xF0, 0xF0, 0x08, 0x18, 0x18, 0x18, 0x18, 0x18, // 97
    0xFE, 0xFE, 0x30, 0xF0, 0xE0, 0x18, 0x18, 0x18, 0x18, 0x08, // 98
    0xC0, 0xF0, 0x30, 0x30, 0x20, 0x08, 0x18, 0x18, 0x18, 0x08, // 99
    0xE0, 0xF0, 0x30, 0x30, 0xFE, 0xFE, 0x08, 0x18, 0x18, 0x18, 0x18, 0x18, // 100
    0xE0, 0xF0, 0xB0, 0x70, 0x70, 0xA0, 0x08, 0x18, 0x18, 0x18, 0x18, 0x08, // 101
    0x30, 0x30, 0xFC, 0xFE, 0x36, 0x36, 0x00, 0x00, 0x38, 0x38, 0x00, 0x00, // 102
    0xE0, 0xF0, 0x30, 0xF0, 0xE0, 0xC8, 0xD8, 0xD8, 0xF8, 0x78, // 103
    0xFE, 0xFE, 0x30, 0xF0, 0xF0, 0x18, 0x18, 0x00, 0x18, 0x18, // 104
    0xF6, 0xF6, 0x18, 0x18, // 105
    0x00, 0x00, 0xF6, 0xF6, 0xF0, 0xC0, 0xF8, 0x78, // 106
    0xFE, 0xFE, 0xC0, 0xE0, 0xB0, 0x10, 0x18, 0x18, 0x00, 0x08, 0x18, 0x18, // 107
    0xFE, 0xFE, 0x18, 0x18, // 108
    0xF0, 0xF0, 0x20, 0xF0, 0xF0, 0x30, 0xF0, 0xF0, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, // 109
    0xF0, 0xF0, 0x20, 0xF0, 0xE0, 0x18, 0x18, 0x00, 0x18, 0x18, // 110
    0xE0, 0xF0, 0x30, 0xF0, 0xE0, 0x08, 0x18, 0x18, 0x18, 0x08, // 111
    0xF0, 0xF0, 0x30, 0xF0, 0xE0, 0xF8, 0xF8, 0x18, 0x18, 0x08, // 112
    0xC0, 0xE0, 0x30, 0xF0, 0xF0, 0x08, 0x18, 0x18, 0xF8, 0xF8, // 113
    0xF0, 0xF0, 0x30, 0x70, 0x70, 0x18, 0x18, 0x00, 0x00, 0x00, // 114
    0x60, 0x70, 0x70, 0xB0, 0xB0, 0x18, 0x18, 0x18, 0x18, 0x08, // 115
    0x30, 0x30, 0xFC, 0xFC, 0x30, 0x30, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, // 116
    0xF0, 0xF0, 0x00, 0xF0, 0xF0, 0x08, 0x18, 0x18, 0x18, 0x18, // 117
    0x30, 0xF0, 0xC0, 0xC0, 0xF0, 0x30, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, // 118
    0xF0, 0xF0, 0x80, 0x70, 0xF0, 0x80, 0xF0, 0x30, 0x00, 0x18, 0x08, 0x00, 0x18, 0x18, 0x00, 0x00, // 119
    0x10, 0x30, 0xE0, 0xE0, 0x30, 0x10, 0x10, 0x18, 0x08, 0x08, 0x18, 0x10, // 120
    0x30, 0xF0, 0x80, 0xE0, 0xF0, 0x30, 0xC0, 0xF8, 0x38, 0x08, 0x00, 0x00, // 121
    0x30, 0xB0, 0xF0, 0x70, 0x30, 0x10, 0x18, 0x18, 0x18, 0x18, // 122
    0x40, 0xFC, 0xBE, 0x06, 0x00, 0x38, 0xF8, 0xC0, // 123
    0xFE, 0xFE, 0xF8, 0xF8, // 124
    0x06, 0xBE, 0xFC, 0x40, 0xC0, 0xF8, 0x38, 0x00, // 125
    0x60, 0x30, 0x10, 0x30, 0x40, 0x60, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
    0xFF, 0x01, 0x01, 0xFF, 0x18, 0x10, 0x10, 0x18 // 127
    
};

#endif
