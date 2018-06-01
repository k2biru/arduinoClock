

/*
 *
 * minimalis
 *
 * created with FontCreator
 * written by F. Maximilian Thiele
 *
 * http://www.apetech.de/fontCreator
 * me@apetech.de
 *
 * File Name           : minimalis.h
 * Date                : 01.02.2017
 * Font size in bytes  : 1502
 * Font width          : 3
 * Font height         : -5
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

#ifndef MINIMALIS_H
#define MINIMALIS_H

#define MINIMALIS_WIDTH 3
#define MINIMALIS_HEIGHT -5

const static uint8_t minimalis[] PROGMEM = {
    0x05, 0xDE, // size
    0x03, // width
    0x05, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x02, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x02, 0x02, 
    0x03, 0x03, 0x02, 0x03, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x02, 0x03, 0x03, 
    0x03, 0x03, 0x05, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
    0x03, 0x01, 0x03, 0x03, 0x03, 0x05, 0x04, 0x03, 0x03, 0x03, 
    0x03, 0x03, 0x03, 0x03, 0x03, 0x05, 0x05, 0x03, 0x03, 0x02, 
    0x03, 0x02, 0x03, 0x03, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 
    0x03, 0x03, 0x03, 0x01, 0x03, 0x03, 0x02, 0x05, 0x03, 0x03, 
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x05, 0x05, 0x03, 
    0x03, 0x03, 0x01, 0x03, 0x04, 0x02, 
    
    // font data
    0x00, 0x00, // 32
    0xB8, // 33
    0x18, 0x00, 0x18, // 34
    0xF8, 0x50, 0xF8, // 35
    0x10, 0xA8, 0x40, // 36
    0x98, 0x20, 0xC8, // 37
    0x50, 0xA8, 0xD0, // 38
    0x08, // 39
    0x88, 0x70, // 40
    0x70, 0x88, // 41
    0x10, 0x18, 0x10, // 42
    0x20, 0x70, 0x20, // 43
    0x80, 0x40, // 44
    0x20, 0x20, 0x20, // 45
    0x80, // 46
    0xC0, 0x20, 0x18, // 47
    0xF8, 0x88, 0xF8, // 48
    0x88, 0xF8, 0x80, // 49
    0xE8, 0xA8, 0xB8, // 50
    0xA8, 0xA8, 0xF8, // 51
    0x38, 0x20, 0xF8, // 52
    0xB8, 0xA8, 0xE8, // 53
    0xF8, 0xA8, 0xE8, // 54
    0x08, 0xE8, 0x18, // 55
    0xF8, 0xA8, 0xF8, // 56
    0xB8, 0xA8, 0xF8, // 57
    0x50, // 58
    0x50, 0x80, // 59
    0x20, 0x50, 0x50, // 60
    0x50, 0x50, 0x50, // 61
    0x50, 0x50, 0x20, // 62
    0x10, 0xC8, 0x30, // 63
    0x70, 0xA8, 0xD8, 0xA8, 0x10, // 64
    0xF8, 0x48, 0xF8, // 65
    0xF8, 0xA8, 0x50, // 66
    0x70, 0x88, 0x88, // 67
    0xF8, 0x88, 0x70, // 68
    0xF8, 0xA8, 0x88, // 69
    0xF8, 0x28, 0x08, // 70
    0x70, 0x88, 0xE8, // 71
    0xF8, 0x20, 0xF8, // 72
    0xF8, // 73
    0xC0, 0x80, 0xF8, // 74
    0xF8, 0x20, 0xD0, // 75
    0xF8, 0x80, 0x80, // 76
    0xF8, 0x10, 0x20, 0x10, 0xF8, // 77
    0xF8, 0x10, 0x20, 0xF8, // 78
    0x70, 0x88, 0x70, // 79
    0xF8, 0x28, 0x38, // 80
    0x70, 0x88, 0xF0, // 81
    0xF8, 0x28, 0xD8, // 82
    0x98, 0xA8, 0xC8, // 83
    0x08, 0xF8, 0x08, // 84
    0xF8, 0x80, 0xF8, // 85
    0x78, 0x80, 0x78, // 86
    0x78, 0x80, 0x40, 0x80, 0x78, // 87
    0x88, 0x50, 0x20, 0x50, 0x88, // 88
    0x38, 0xE0, 0x38, // 89
    0xC8, 0xA8, 0x98, // 90
    0xF8, 0x88, // 91
    0x18, 0x20, 0xC0, // 92
    0x88, 0xF8, // 93
    0x18, 0x08, 0x18, // 94
    0x80, 0x80, 0x80, // 95
    0x18, 0x18, // 96
    0xE8, 0xA8, 0xF8, // 97
    0xF8, 0xA0, 0xE0, // 98
    0xF0, 0x90, 0x90, // 99
    0xE0, 0xA0, 0xF8, // 100
    0xF8, 0xA8, 0xB8, // 101
    0x20, 0xF8, 0x28, // 102
    0xB8, 0xA8, 0xF8, // 103
    0xF8, 0x20, 0xE0, // 104
    0xE8, // 105
    0x40, 0x80, 0xE8, // 106
    0xF8, 0x40, 0xA0, // 107
    0xF8, 0x80, // 108
    0xE0, 0x20, 0x60, 0x20, 0xE0, // 109
    0xE0, 0x20, 0xE0, // 110
    0xE0, 0xA0, 0xE0, // 111
    0xF0, 0x50, 0x70, // 112
    0x70, 0x50, 0xF0, // 113
    0xF0, 0x10, 0x10, // 114
    0x90, 0xA8, 0x48, // 115
    0x10, 0xF8, 0x90, // 116
    0xF0, 0x80, 0xF0, // 117
    0x70, 0x80, 0x70, // 118
    0xF0, 0x90, 0x48, 0x88, 0x70, // 119
    0x88, 0x50, 0x20, 0x50, 0x88, // 120
    0xB8, 0xA0, 0xF8, // 121
    0xC8, 0xA8, 0x98, // 122
    0x20, 0xF8, 0x88, // 123
    0xF8, // 124
    0x88, 0xF8, 0x20, // 125
    0x30, 0x10, 0x20, 0x30, // 126
    0x00, 0x00 // 127
    
};

#endif
