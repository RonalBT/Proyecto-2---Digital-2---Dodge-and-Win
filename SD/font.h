#ifndef _FONT_H_
#define _FONT_H_

#ifndef _ENERGIA_H_
#include <Energia.h>
#endif

#define fontXSizeSmal 8
#define fontYSizeSmal 12
#define fontXSizeBig 16
#define fontYSizeBig 16
#define fontXSizeNum 32
#define fontYSizeNum 50

#define fontdatatype const uint8_t
#define fontdatatype16 const uint16_t

// Font Size  : 8x12   1140 bytes

fontdatatype smallFont[1140] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // <Space>
  0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x20, 0x00, 0x00, // !
  0x00, 0x28, 0x50, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "
  0x00, 0x00, 0x28, 0x28, 0xFC, 0x28, 0x50, 0xFC, 0x50, 0x50, 0x00, 0x00, // #
  0x00, 0x20, 0x78, 0xA8, 0xA0, 0x60, 0x30, 0x28, 0xA8, 0xF0, 0x20, 0x00, // $
  0x00, 0x00, 0x48, 0xA8, 0xB0, 0x50, 0x28, 0x34, 0x54, 0x48, 0x00, 0x00, // %
  0x00, 0x00, 0x20, 0x50, 0x50, 0x78, 0xA8, 0xA8, 0x90, 0x6C, 0x00, 0x00, // &
  0x00, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '
  0x00, 0x04, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x04, 0x00, // (
  0x00, 0x40, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x40, 0x00, // )
  0x00, 0x00, 0x00, 0x20, 0xA8, 0x70, 0x70, 0xA8, 0x20, 0x00, 0x00, 0x00, // *
  0x00, 0x00, 0x20, 0x20, 0x20, 0xF8, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, // +
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x80, // ,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, // .
  0x00, 0x08, 0x10, 0x10, 0x10, 0x20, 0x20, 0x40, 0x40, 0x40, 0x80, 0x00, // /
  0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, // 0
  0x00, 0x00, 0x20, 0x60, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00, // 1
  0x00, 0x00, 0x70, 0x88, 0x88, 0x10, 0x20, 0x40, 0x80, 0xF8, 0x00, 0x00, // 2
  0x00, 0x00, 0x70, 0x88, 0x08, 0x30, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, // 3
  0x00, 0x00, 0x10, 0x30, 0x50, 0x50, 0x90, 0x78, 0x10, 0x18, 0x00, 0x00, // 4
  0x00, 0x00, 0xF8, 0x80, 0x80, 0xF0, 0x08, 0x08, 0x88, 0x70, 0x00, 0x00, // 5
  0x00, 0x00, 0x70, 0x90, 0x80, 0xF0, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, // 6
  0x00, 0x00, 0xF8, 0x90, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, // 7
  0x00, 0x00, 0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, // 8
  0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x78, 0x08, 0x48, 0x70, 0x00, 0x00, // 9
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, // :
  0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, // ;
  0x00, 0x04, 0x08, 0x10, 0x20, 0x40, 0x20, 0x10, 0x08, 0x04, 0x00, 0x00, // <
  0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, // =
  0x00, 0x40, 0x20, 0x10, 0x08, 0x04, 0x08, 0x10, 0x20, 0x40, 0x00, 0x00, // >
  0x00, 0x00, 0x70, 0x88, 0x88, 0x10, 0x20, 0x20, 0x00, 0x20, 0x00, 0x00, // ?
  0x00, 0x00, 0x70, 0x88, 0x98, 0xA8, 0xA8, 0xB8, 0x80, 0x78, 0x00, 0x00, // @
  0x00, 0x00, 0x20, 0x20, 0x30, 0x50, 0x50, 0x78, 0x48, 0xCC, 0x00, 0x00, // A
  0x00, 0x00, 0xF0, 0x48, 0x48, 0x70, 0x48, 0x48, 0x48, 0xF0, 0x00, 0x00, // B
  0x00, 0x00, 0x78, 0x88, 0x80, 0x80, 0x80, 0x80, 0x88, 0x70, 0x00, 0x00, // C
  0x00, 0x00, 0xF0, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0xF0, 0x00, 0x00, // D
  0x00, 0x00, 0xF8, 0x48, 0x50, 0x70, 0x50, 0x40, 0x48, 0xF8, 0x00, 0x00, // E
  0x00, 0x00, 0xF8, 0x48, 0x50, 0x70, 0x50, 0x40, 0x40, 0xE0, 0x00, 0x00, // F
  0x00, 0x00, 0x38, 0x48, 0x80, 0x80, 0x9C, 0x88, 0x48, 0x30, 0x00, 0x00, // G
  0x00, 0x00, 0xCC, 0x48, 0x48, 0x78, 0x48, 0x48, 0x48, 0xCC, 0x00, 0x00, // H
  0x00, 0x00, 0xF8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xF8, 0x00, 0x00, // I
  0x00, 0x00, 0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x90, 0xE0, 0x00, // J
  0x00, 0x00, 0xEC, 0x48, 0x50, 0x60, 0x50, 0x50, 0x48, 0xEC, 0x00, 0x00, // K
  0x00, 0x00, 0xE0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x44, 0xFC, 0x00, 0x00, // L
  0x00, 0x00, 0xD8, 0xD8, 0xD8, 0xD8, 0xA8, 0xA8, 0xA8, 0xA8, 0x00, 0x00, // M
  0x00, 0x00, 0xDC, 0x48, 0x68, 0x68, 0x58, 0x58, 0x48, 0xE8, 0x00, 0x00, // N
  0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, // O
  0x00, 0x00, 0xF0, 0x48, 0x48, 0x70, 0x40, 0x40, 0x40, 0xE0, 0x00, 0x00, // P
  0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x88, 0xE8, 0x98, 0x70, 0x18, 0x00, // Q
  0x00, 0x00, 0xF0, 0x48, 0x48, 0x70, 0x50, 0x48, 0x48, 0xEC, 0x00, 0x00, // R
  0x00, 0x00, 0x78, 0x88, 0x80, 0x60, 0x10, 0x08, 0x88, 0xF0, 0x00, 0x00, // S
  0x00, 0x00, 0xF8, 0xA8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00, // T
  0x00, 0x00, 0xCC, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x30, 0x00, 0x00, // U
  0x00, 0x00, 0xCC, 0x48, 0x48, 0x50, 0x50, 0x30, 0x20, 0x20, 0x00, 0x00, // V
  0x00, 0x00, 0xA8, 0xA8, 0xA8, 0x70, 0x50, 0x50, 0x50, 0x50, 0x00, 0x00, // W
  0x00, 0x00, 0xD8, 0x50, 0x50, 0x20, 0x20, 0x50, 0x50, 0xD8, 0x00, 0x00, // X
  0x00, 0x00, 0xD8, 0x50, 0x50, 0x20, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00, // Y
  0x00, 0x00, 0xF8, 0x90, 0x10, 0x20, 0x20, 0x40, 0x48, 0xF8, 0x00, 0x00, // Z
  0x00, 0x38, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x38, 0x00, // [
  0x00, 0x40, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x10, 0x08, 0x00, 0x00, // <Backslash>
  0x00, 0x70, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x70, 0x00, // ]
  0x00, 0x20, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ^
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, // _
  0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x48, 0x38, 0x48, 0x3C, 0x00, 0x00, // a
  0x00, 0x00, 0xC0, 0x40, 0x40, 0x70, 0x48, 0x48, 0x48, 0x70, 0x00, 0x00, // b
  0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x48, 0x40, 0x40, 0x38, 0x00, 0x00, // c
  0x00, 0x00, 0x18, 0x08, 0x08, 0x38, 0x48, 0x48, 0x48, 0x3C, 0x00, 0x00, // d
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x48, 0x78, 0x40, 0x38, 0x00, 0x00, // e
  0x00, 0x00, 0x1C, 0x20, 0x20, 0x78, 0x20, 0x20, 0x20, 0x78, 0x00, 0x00, // f
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x48, 0x30, 0x40, 0x78, 0x44, 0x38, // g
  0x00, 0x00, 0xC0, 0x40, 0x40, 0x70, 0x48, 0x48, 0x48, 0xEC, 0x00, 0x00, // h
  0x00, 0x00, 0x20, 0x00, 0x00, 0x60, 0x20, 0x20, 0x20, 0x70, 0x00, 0x00, // i
  0x00, 0x00, 0x10, 0x00, 0x00, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0xE0, // j
  0x00, 0x00, 0xC0, 0x40, 0x40, 0x5C, 0x50, 0x70, 0x48, 0xEC, 0x00, 0x00, // k
  0x00, 0x00, 0xE0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xF8, 0x00, 0x00, // l
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xA8, 0xA8, 0xA8, 0xA8, 0x00, 0x00, // m
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x48, 0x48, 0x48, 0xEC, 0x00, 0x00, // n
  0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x48, 0x48, 0x48, 0x30, 0x00, 0x00, // o
  0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x48, 0x48, 0x48, 0x70, 0x40, 0xE0, // p
  0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x48, 0x48, 0x48, 0x38, 0x08, 0x1C, // q
  0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0x60, 0x40, 0x40, 0xE0, 0x00, 0x00, // r
  0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x40, 0x30, 0x08, 0x78, 0x00, 0x00, // s
  0x00, 0x00, 0x00, 0x20, 0x20, 0x70, 0x20, 0x20, 0x20, 0x18, 0x00, 0x00, // t
  0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0x48, 0x48, 0x48, 0x3C, 0x00, 0x00, // u
  0x00, 0x00, 0x00, 0x00, 0x00, 0xEC, 0x48, 0x50, 0x30, 0x20, 0x00, 0x00, // v
  0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0xA8, 0x70, 0x50, 0x50, 0x00, 0x00, // w
  0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0x50, 0x20, 0x50, 0xD8, 0x00, 0x00, // x
  0x00, 0x00, 0x00, 0x00, 0x00, 0xEC, 0x48, 0x50, 0x30, 0x20, 0x20, 0xC0, // y
  0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x10, 0x20, 0x20, 0x78, 0x00, 0x00, // z
  0x00, 0x18, 0x10, 0x10, 0x10, 0x20, 0x10, 0x10, 0x10, 0x10, 0x18, 0x00, // {
  0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, // |
  0x00, 0x60, 0x20, 0x20, 0x20, 0x10, 0x20, 0x20, 0x20, 0x20, 0x60, 0x00, // }
  0x40, 0xA4, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // ~
};

fontdatatype16 bigFont[1520] = {
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, //  <Space>
  0x0000, 0x0000, 0x0700, 0x0F80, 0x0F80, 0x0F80, 0x0F80, 0x0F80, 0x0700, 0x0700, 0x0000, 0x0000, 0x0700, 0x0700, 0x0700, 0x0000, // !
  0x0000, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0630, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // "
  0x0000, 0x0C30, 0x0C30, 0x0C30, 0x7FFE, 0x7FFE, 0x0C30, 0x0C30, 0x0C30, 0x0C30, 0x7FFE, 0x7FFE, 0x0C30, 0x0C30, 0x0C30, 0x0000, // #
  0x0000, 0x0240, 0x0240, 0x0FF8, 0x1FF8, 0x1A40, 0x1A40, 0x1FF0, 0x0FF8, 0x0258, 0x0258, 0x1FF8, 0x1FF0, 0x0240, 0x0240, 0x0000, // $
  0x0000, 0x0000, 0x0000, 0x0E10, 0x0E30, 0x0E70, 0x00E0, 0x01C0, 0x0380, 0x0700, 0x0E70, 0x0C70, 0x0870, 0x0000, 0x0000, 0x0000, // %
  0x0000, 0x0000, 0x0F00, 0x1980, 0x1980, 0x1980, 0x0F00, 0x0F08, 0x0F98, 0x19F8, 0x18F0, 0x18E0, 0x19F0, 0x0F98, 0x0000, 0x0000, // &
  0x0000, 0x0000, 0x0700, 0x0700, 0x0700, 0x0E00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // '
  0x0000, 0x0000, 0x00F0, 0x01C0, 0x0380, 0x0700, 0x0E00, 0x0E00, 0x0E00, 0x0E00, 0x0700, 0x0380, 0x01C0, 0x00F0, 0x0000, 0x0000, // (
  0x0000, 0x0000, 0x0F00, 0x0380, 0x01C0, 0x00E0, 0x0070, 0x0070, 0x0070, 0x0070, 0x00E0, 0x01C0, 0x0380, 0x0F00, 0x0000, 0x0000, // )
  0x0000, 0x0000, 0x0180, 0x1188, 0x0990, 0x07E0, 0x07E0, 0x3FFC, 0x3FFC, 0x07E0, 0x07E0, 0x0990, 0x1188, 0x0180, 0x0000, 0x0000, // *
  0x0000, 0x0000, 0x0000, 0x0000, 0x0180, 0x0180, 0x0180, 0x0FF0, 0x0FF0, 0x0180, 0x0180, 0x0180, 0x0000, 0x0000, 0x0000, 0x0000, // +
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0700, 0x0700, 0x0700, 0x0E00, 0x0000, // ,
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1FF8, 0x1FF8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // -
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0700, 0x0700, 0x0700, 0x0000, 0x0000, // ,
  0x0000, 0x0000, 0x0002, 0x0006, 0x000E, 0x001C, 0x0038, 0x0070, 0x00E0, 0x01C0, 0x0380, 0x0700, 0x0E00, 0x1C00, 0x0000, 0x0000, // /

  0x0000, 0x0000, 0x0FF0, 0x1C38, 0x1C78, 0x1CF8, 0x1CF8, 0x1DB8, 0x1DB8, 0x1F38, 0x1F38, 0x1E38, 0x1C38, 0x0FF0, 0x0000, 0x0000, // 0
  0x0000, 0x0000, 0x0180, 0x0180, 0x0380, 0x1F80, 0x1F80, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x1FF0, 0x0000, 0x0000, // 1
  0x0000, 0x0000, 0x0FE0, 0x1C70, 0x1C38, 0x0038, 0x0070, 0x00E0, 0x01C0, 0x0380, 0x0700, 0x0E38, 0x1C38, 0x1FF8, 0x0000, 0x0000, // 2
  0x0000, 0x0000, 0x0FE0, 0x1C70, 0x1C38, 0x0038, 0x0070, 0x03C0, 0x03C0, 0x0070, 0x0038, 0x1C38, 0x1C70, 0x0FE0, 0x0000, 0x0000, // 3
  0x0000, 0x0000, 0x00E0, 0x01E0, 0x03E0, 0x06E0, 0x0CE0, 0x18E0, 0x1FF8, 0x1FF8, 0x00E0, 0x00E0, 0x00E0, 0x03F8, 0x0000, 0x0000, // 4
  0x0000, 0x0000, 0x1FF8, 0x1C00, 0x1C00, 0x1C00, 0x1C00, 0x1FE0, 0x1FF0, 0x0078, 0x0038, 0x1C38, 0x1C70, 0x0FE0, 0x0000, 0x0000, // 5
  0x0000, 0x0000, 0x03E0, 0x0700, 0x0E00, 0x1C00, 0x1C00, 0x1FF0, 0x1FF8, 0x1C38, 0x1C38, 0x1C38, 0x1C38, 0x0FF0, 0x0000, 0x0000, // 6
  0x0000, 0x0000, 0x1FFC, 0x1C1C, 0x1C1C, 0x1C1C, 0x001C, 0x0038, 0x0070, 0x00E0, 0x01C0, 0x0380, 0x0380, 0x0380, 0x0000, 0x0000, // 7
  0x0000, 0x0000, 0x0FF0, 0x1C38, 0x1C38, 0x1C38, 0x1F38, 0x07E0, 0x07E0, 0x1CF8, 0x1C38, 0x1C38, 0x1C38, 0x0FF0, 0x0000, 0x0000, // 8
  0x0000, 0x0000, 0x0FF0, 0x1C38, 0x1C38, 0x1C38, 0x1C38, 0x1FF8, 0x0FF8, 0x0038, 0x0038, 0x0070, 0x00E0, 0x07C0, 0x0000, 0x0000, // 9
  0x0000, 0x0000, 0x0000, 0x0000, 0x0380, 0x0380, 0x0380, 0x0000, 0x0000, 0x0380, 0x0380, 0x0380, 0x0000, 0x0000, 0x0000, 0x0000, // :
  0x0000, 0x0000, 0x0000, 0x0000, 0x0380, 0x0380, 0x0380, 0x0000, 0x0000, 0x0380, 0x0380, 0x0380, 0x0700, 0x0000, 0x0000, 0x0000, // ;
  0x0000, 0x0070, 0x00E0, 0x01C0, 0x0380, 0x0700, 0x0E00, 0x1C00, 0x1C00, 0x0E00, 0x0700, 0x0380, 0x01C0, 0x00E0, 0x0070, 0x0000, // <
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x3FFC, 0x3FFC, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // =
  0x0000, 0x1C00, 0x0E00, 0x0700, 0x0380, 0x01C0, 0x00E0, 0x0070, 0x0070, 0x00E0, 0x01C0, 0x0380, 0x0700, 0x0E00, 0x1C00, 0x0000, // >
  0x0000, 0x03C0, 0x0FF0, 0x1E78, 0x1838, 0x0038, 0x0070, 0x00E0, 0x01C0, 0x01C0, 0x0000, 0x0000, 0x01C0, 0x01C0, 0x01C0, 0x0000, // ?

  0x0000, 0x0FF8, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C1C, 0x1CFC, 0x1CFC, 0x1CFC, 0x1CFC, 0x1C00, 0x1C00, 0x1C00, 0x1FF0, 0x07F8, 0x0000, // @
  0x0000, 0x0000, 0x03C0, 0x07E0, 0x0E70, 0x1C38, 0x1C38, 0x1C38, 0x1C38, 0x1FF8, 0x1C38, 0x1C38, 0x1C38, 0x1C38, 0x0000, 0x0000, // A
  0x0000, 0x0000, 0x1FF0, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0FF0, 0x0FF0, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x1FF0, 0x0000, 0x0000, // B
  0x0000, 0x0000, 0x07F0, 0x0E38, 0x1C38, 0x1C00, 0x1C00, 0x1C00, 0x1C00, 0x1C00, 0x1C00, 0x1C38, 0x0E38, 0x07F0, 0x0000, 0x0000, // C
  0x0000, 0x0000, 0x1FE0, 0x0E70, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0E70, 0x1FE0, 0x0000, 0x0000, // D
  0x0000, 0x0000, 0x1FF8, 0x0E18, 0x0E08, 0x0E00, 0x0E30, 0x0FF0, 0x0FF0, 0x0E30, 0x0E00, 0x0E08, 0x0E18, 0x1FF8, 0x0000, 0x0000, // E
  0x0000, 0x0000, 0x1FF8, 0x0E18, 0x0E08, 0x0E00, 0x0E30, 0x0FF0, 0x0FF0, 0x0E30, 0x0E00, 0x0E00, 0x0E00, 0x1F00, 0x0000, 0x0000, // F
  0x0000, 0x0000, 0x07F0, 0x0E38, 0x1C38, 0x1C38, 0x1C00, 0x1C00, 0x1C00, 0x1CF8, 0x1C38, 0x1C38, 0x0E38, 0x07F8, 0x0000, 0x0000, // G
  0x0000, 0x0000, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1FF0, 0x1FF0, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x0000, 0x0000, // H
  0x0000, 0x0000, 0x0FE0, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0FE0, 0x0000, 0x0000, // I
  0x0000, 0x0000, 0x01FC, 0x0070, 0x0070, 0x0070, 0x0070, 0x0070, 0x0070, 0x3870, 0x3870, 0x3870, 0x3870, 0x0FE0, 0x0000, 0x0000, // J
  0x0000, 0x0000, 0x1E38, 0x0E38, 0x0E70, 0x0EE0, 0x0FC0, 0x0F80, 0x0F80, 0x0FC0, 0x0EE0, 0x0E70, 0x0E38, 0x1E38, 0x0000, 0x0000, // K
  0x0000, 0x0000, 0x1F00, 0x0E00, 0x0E00, 0x0E00, 0x0E00, 0x0E00, 0x0E00, 0x0E00, 0x0E08, 0x0E18, 0x0E38, 0x1FF8, 0x0000, 0x0000, // L
  0x0000, 0x0000, 0x1C1C, 0x1E3C, 0x1F7C, 0x1FFC, 0x1FFC, 0x1DDC, 0x1C9C, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C1C, 0x0000, 0x0000, // M
  0x0000, 0x0000, 0x1C1C, 0x1C1C, 0x1E1C, 0x1F1C, 0x1F9C, 0x1DDC, 0x1CFC, 0x1C7C, 0x1C3C, 0x1C1C, 0x1C1C, 0x1C1C, 0x0000, 0x0000, // N
  0x0000, 0x0000, 0x03E0, 0x07F0, 0x0E38, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C1C, 0x0E38, 0x07F0, 0x03E0, 0x0000, 0x0000, // O

  0x0000, 0x0000, 0x1FF0, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0FF0, 0x0FF0, 0x0E00, 0x0E00, 0x0E00, 0x0E00, 0x1F00, 0x0000, 0x0000, // P
  0x0000, 0x0000, 0x03E0, 0x0F78, 0x0E38, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C7C, 0x1CFC, 0x0FF8, 0x0FF8, 0x0038, 0x00FC, 0x0000, // Q
  0x0000, 0x0000, 0x1FF0, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0FF0, 0x0FF0, 0x0E70, 0x0E38, 0x0E38, 0x0E38, 0x1E38, 0x0000, 0x0000, // R
  0x0000, 0x0000, 0x0FF0, 0x1C38, 0x1C38, 0x1C38, 0x1C00, 0x0FE0, 0x07F0, 0x0038, 0x1C38, 0x1C38, 0x1C38, 0x0FF0, 0x0000, 0x0000, // S
  0x0000, 0x0000, 0x1FFC, 0x19CC, 0x11C4, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x07F0, 0x0000, 0x0000, // T
  0x0000, 0x0000, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x0FE0, 0x0000, 0x0000, // U
  0x0000, 0x0000, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x0EE0, 0x07C0, 0x0380, 0x0000, 0x0000, // V
  0x0000, 0x0000, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C9C, 0x1C9C, 0x1C9C, 0x0FF8, 0x0FF8, 0x0770, 0x0770, 0x0000, 0x0000, // W
  0x0000, 0x0000, 0x1C70, 0x1C70, 0x1C70, 0x0EE0, 0x07C0, 0x0380, 0x0380, 0x07C0, 0x0EE0, 0x1C70, 0x1C70, 0x1C70, 0x0000, 0x0000, // X
  0x0000, 0x0000, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x0EE0, 0x07C0, 0x0380, 0x0380, 0x0380, 0x0380, 0x0FE0, 0x0000, 0x0000, // Y
  0x0000, 0x0000, 0x1FF8, 0x1C38, 0x1838, 0x1070, 0x00E0, 0x01C0, 0x0380, 0x0700, 0x0E08, 0x1C18, 0x1C38, 0x1FF8, 0x0000, 0x0000, // Z
  0x0000, 0x0000, 0x07F0, 0x0700, 0x0700, 0x0700, 0x0700, 0x0700, 0x0700, 0x0700, 0x0700, 0x0700, 0x0700, 0x07F0, 0x0000, 0x0000, // [
  0x0000, 0x0000, 0x1000, 0x1800, 0x1C00, 0x0E00, 0x0700, 0x0380, 0x01C0, 0x00E0, 0x0070, 0x0038, 0x001C, 0x0007, 0x0000, 0x0000, // <Backslash>
  0x0000, 0x0000, 0x07F0, 0x0070, 0x0070, 0x0070, 0x0070, 0x0070, 0x0070, 0x0070, 0x0070, 0x0070, 0x0070, 0x07F0, 0x0000, 0x0000, // ]
  0x0000, 0x0180, 0x03C0, 0x07E0, 0x0E70, 0x1C38, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // ^
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7FFF, 0x7FFF, // _

  0x0000, 0x0000, 0x1C00, 0x1C00, 0x0700, 0x0700, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, // '
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0FE0, 0x0070, 0x0070, 0x0FF0, 0x1C70, 0x1C70, 0x1C70, 0x0FD8, 0x0000, 0x0000, // a
  0x0000, 0x0000, 0x1E00, 0x0E00, 0x0E00, 0x0E00, 0x0FF0, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x1BF0, 0x0000, 0x0000, // b
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0FE0, 0x1C70, 0x1C70, 0x1C00, 0x1C00, 0x1C70, 0x1C70, 0x0FE0, 0x0000, 0x0000, // c
  0x0000, 0x0000, 0x00F8, 0x0070, 0x0070, 0x0070, 0x0FF0, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x0FD8, 0x0000, 0x0000, // d
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0FE0, 0x1C70, 0x1C70, 0x1FF0, 0x1C00, 0x1C70, 0x1C70, 0x0FE0, 0x0000, 0x0000, // e
  0x0000, 0x0000, 0x03E0, 0x0770, 0x0770, 0x0700, 0x0700, 0x1FE0, 0x1FE0, 0x0700, 0x0700, 0x0700, 0x0700, 0x1FC0, 0x0000, 0x0000, // f
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0FD8, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x0FF0, 0x07F0, 0x0070, 0x1C70, 0x0FE0, // g
  0x0000, 0x0000, 0x1E00, 0x0E00, 0x0E00, 0x0E00, 0x0EF0, 0x0F38, 0x0F38, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x1E38, 0x0000, 0x0000, // h
  0x0000, 0x0000, 0x01C0, 0x01C0, 0x01C0, 0x0000, 0x0FC0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x0FF8, 0x0000, 0x0000, // i
  0x0000, 0x0000, 0x0070, 0x0070, 0x0070, 0x0000, 0x03F0, 0x0070, 0x0070, 0x0070, 0x0070, 0x0070, 0x0070, 0x1C70, 0x0CF0, 0x07E0, // j
  0x0000, 0x0000, 0x1E00, 0x0E00, 0x0E00, 0x0E00, 0x0E38, 0x0E70, 0x0EE0, 0x0FC0, 0x0EE0, 0x0E70, 0x0E38, 0x1E38, 0x0000, 0x0000, // k
  0x0000, 0x0000, 0x0FC0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x0FF8, 0x0000, 0x0000, // l
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1FF8, 0x1C9C, 0x1C9C, 0x1C9C, 0x1C9C, 0x1C9C, 0x1C9C, 0x1C9C, 0x0000, 0x0000, // m
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1FE0, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x0000, 0x0000, // n
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0FE0, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x0FE0, 0x0000, 0x0000, // o

  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1BF0, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0FF0, 0x0E00, 0x0E00, 0x1F00, // p
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1FB0, 0x38E0, 0x38E0, 0x38E0, 0x38E0, 0x38E0, 0x1FE0, 0x00E0, 0x00E0, 0x01F0, // q
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1EF0, 0x0FF8, 0x0F38, 0x0E00, 0x0E00, 0x0E00, 0x0E00, 0x1F00, 0x0000, 0x0000, // r
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0FE0, 0x1C30, 0x1C30, 0x0F80, 0x03E0, 0x1870, 0x1870, 0x0FE0, 0x0000, 0x0000, // s
  0x0000, 0x0000, 0x0000, 0x0100, 0x0300, 0x0700, 0x1FF0, 0x0700, 0x0700, 0x0700, 0x0700, 0x0770, 0x0770, 0x03E0, 0x0000, 0x0000, // t
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x0FD8, 0x0000, 0x0000, // u
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x1C70, 0x0EE0, 0x07C0, 0x0380, 0x0000, 0x0000, // v
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1C1C, 0x1C1C, 0x1C1C, 0x1C9C, 0x1C9C, 0x0FF8, 0x0770, 0x0770, 0x0000, 0x0000, // w
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1CE0, 0x1CE0, 0x0FC0, 0x0780, 0x0780, 0x0FC0, 0x1CE0, 0x1CE0, 0x0000, 0x0000, // x
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x0E38, 0x07F0, 0x03E0, 0x00E0, 0x01C0, 0x1F80, // y
  0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1FE0, 0x18E0, 0x11C0, 0x0380, 0x0700, 0x0E20, 0x1C60, 0x1FE0, 0x0000, 0x0000, // z
  0x0000, 0x0000, 0x01F8, 0x0380, 0x0380, 0x0380, 0x0700, 0x1C00, 0x1C00, 0x0700, 0x0380, 0x0380, 0x0380, 0x01F8, 0x0000, 0x0000, // {
  0x0000, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x0000, // |
  0x0000, 0x0000, 0x1F80, 0x01C0, 0x01C0, 0x01C0, 0x00E0, 0x0038, 0x0038, 0x00E0, 0x01C0, 0x01C0, 0x01C0, 0x1F80, 0x0000, 0x0000, // }
  0x0000, 0x0000, 0x1F1C, 0x3B9C, 0x39DC, 0x38F8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000  // ~
};

#endif
