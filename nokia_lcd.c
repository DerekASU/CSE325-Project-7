/*
 * Proj 7
 * Derek Janzen (djanzen@asu.edu)
 * Jialiang Liu (jliu174@asu.edu)
 * CSE 325
 */
#include "nokia_lcd.h"

uint8_t g_font_table[][5] = {
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 32: Space
	{ 0x00, 0x00, 0x5F, 0x00, 0x00 }, // 33: !
	{ 0x00, 0x03, 0x00, 0x03, 0x00 }, // 34: "
	{ 0x14, 0x7F, 0x14, 0x7F, 0x14 }, // 35: #
	{ 0x24, 0x2A, 0x7F, 0x2A, 0x12 }, // 36: $
	{ 0x23, 0x13, 0x08, 0x64, 0x62 }, // 37: %
	{ 0x36, 0x49, 0x55, 0x22, 0x50 }, // 38: &
	{ 0x00, 0x00, 0x03, 0x00, 0x00 }, // 39: '
	{ 0x1C, 0x22, 0x41, 0x00, 0x00 }, // 40: (
	{ 0x00, 0x00, 0x41, 0x22, 0x1C }, // 41: )
	{ 0x0A, 0x04, 0x1F, 0x04, 0x0A }, // 42: *
	{ 0x08, 0x08, 0x3E, 0x08, 0x08 }, // 43: +
	{ 0x00, 0x50, 0x30, 0x00, 0x00 }, // 44: ,
	{ 0x08, 0x08, 0x08, 0x08, 0x08 }, // 45: -
	{ 0x00, 0x60, 0x60, 0x00, 0x00 }, // 46: .
	{ 0x20, 0x10, 0x08, 0x04, 0x02 }, // 47: /
	{ 0x3E, 0x51, 0x49, 0x45, 0x3E }, // 48: 0
	{ 0x00, 0x42, 0x7F, 0x40, 0x00 }, // 49: 1
	{ 0x42, 0x61, 0x51, 0x49, 0x46 }, // 50: 2
	{ 0x21, 0x41, 0x45, 0x4B, 0x31 }, // 51: 3
	{ 0x10, 0x18, 0x14, 0x12, 0x7F }, // 52: 4
	{ 0x27, 0x45, 0x45, 0x45, 0x39 }, // 53: 5
	{ 0x3E, 0x49, 0x49, 0x49, 0x30 }, // 54: 6
	{ 0x03, 0x71, 0x09, 0x05, 0x03 }, // 55: 7
	{ 0x36, 0x49, 0x49, 0x49, 0x36 }, // 56: 8
	{ 0x06, 0x49, 0x49, 0x49, 0x3E }, // 57: 9
	{ 0x00, 0x36, 0x36, 0x00, 0x00 }, // 58: :
	{ 0x00, 0x56, 0x36, 0x00, 0x00 }, // 59: ;
	{ 0x08, 0x14, 0x22, 0x41, 0x00 }, // 60: <
	{ 0x14, 0x14, 0x14, 0x14, 0x14 }, // 61: =
	{ 0x00, 0x41, 0x22, 0x14, 0x08 }, // 62: >
	{ 0x06, 0x01, 0x51, 0x09, 0x06 }, // 63: ?
	{ 0x32, 0x49, 0x79, 0x41, 0x3E }, // 64: @
	{ 0x7C, 0x0A, 0x09, 0x0A, 0x7C }, // 65: A
	{ 0x7F, 0x49, 0x49, 0x49, 0x36 }, // 66: B
	{ 0x3E, 0x41, 0x41, 0x41, 0x22 }, // 67: C
	{ 0x7F, 0x41, 0x41, 0x41, 0x3E }, // 68: D
	{ 0x7F, 0x49, 0x49, 0x49, 0x41 }, // 69: E
	{ 0x7F, 0x09, 0x09, 0x09, 0x01 }, // 70: F
	{ 0x3E, 0x41, 0x41, 0x51, 0x32 }, // 71: G
	{ 0x7F, 0x08, 0x08, 0x08, 0x7F }, // 72: H
	{ 0x00, 0x41, 0x7F, 0x41, 0x00 }, // 73: I
	{ 0x20, 0x40, 0x41, 0x3F, 0x01 }, // 74: J
	{ 0x7F, 0x08, 0x14, 0x22, 0x41 }, // 75: K
	{ 0x7F, 0x40, 0x40, 0x40, 0x40 }, // 76: L
	{ 0x7E, 0x01, 0x06, 0x01, 0x7E }, // 77: M
	{ 0x7F, 0x04, 0x08, 0x10, 0x7F }, // 78: N
	{ 0x3E, 0x41, 0x41, 0x41, 0x3E }, // 79: O
	{ 0x7F, 0x09, 0x09, 0x09, 0x06 }, // 80: P
	{ 0x3E, 0x41, 0x51, 0x21, 0x5E }, // 81: Q
	{ 0x7F, 0x09, 0x19, 0x29, 0x46 }, // 82: R
	{ 0x26, 0x49, 0x49, 0x49, 0x32 }, // 83: S
	{ 0x01, 0x01, 0x7F, 0x01, 0x01 }, // 84: T
	{ 0x3F, 0x40, 0x40, 0x40, 0x3F }, // 85: U
	{ 0x1F, 0x20, 0x40, 0x20, 0x1F }, // 86: V
	{ 0x3F, 0x40, 0x30, 0x40, 0x3F }, // 87: W
	{ 0x63, 0x14, 0x08, 0x14, 0x63 }, // 88: X
	{ 0x07, 0x08, 0x78, 0x08, 0x07 }, // 89: Y
	{ 0x61, 0x51, 0x49, 0x45, 0x43 }, // 90: Z
	{ 0x7F, 0x41, 0x41, 0x00, 0x00 }, // 91: [
	{ 0x02, 0x04, 0x08, 0x10, 0x20 }, // 92: "\"
	{ 0x00, 0x00, 0x41, 0x41, 0x7F }, // 93: ]
	{ 0x04, 0x02, 0x01, 0x02, 0x04 }, // 94: ^
	{ 0x40, 0x40, 0x40, 0x40, 0x40 }, // 95: _
	{ 0x01, 0x02, 0x04, 0x00, 0x00 }, // 96: `
	{ 0x20, 0x54, 0x54, 0x54, 0x78 }, // 97: a
	{ 0x7F, 0x48, 0x44, 0x44, 0x38 }, // 98: b
	{ 0x38, 0x44, 0x44, 0x44, 0x20 }, // 99: c
	{ 0x38, 0x44, 0x44, 0x48, 0x7F }, // 100: d
	{ 0x38, 0x54, 0x54, 0x54, 0x18 }, // 101: e
	{ 0x08, 0x7E, 0x09, 0x01, 0x02 }, // 102: f
	{ 0x08, 0x54, 0x54, 0x54, 0x3C }, // 103: g
	{ 0x7F, 0x08, 0x04, 0x04, 0x78 }, // 104: h
	{ 0x00, 0x48, 0x7D, 0x40, 0x00 }, // 105: i
	{ 0x20, 0x40, 0x44, 0x3D, 0x00 }, // 106: j
	{ 0x7F, 0x10, 0x28, 0x44, 0x00 }, // 107: k
	{ 0x00, 0x41, 0x7F, 0x40, 0x00 }, // 108: l
	{ 0x7C, 0x04, 0x78, 0x04, 0x78 }, // 109: m
	{ 0x7C, 0x08, 0x04, 0x04, 0x78 }, // 110: n
	{ 0x38, 0x44, 0x44, 0x44, 0x38 }, // 111: o
	{ 0x7C, 0x14, 0x14, 0x14, 0x08 }, // 112: p
	{ 0x08, 0x14, 0x14, 0x18, 0x7C }, // 113: q
	{ 0x7C, 0x08, 0x04, 0x04, 0x08 }, // 114: r
	{ 0x48, 0x54, 0x54, 0x54, 0x20 }, // 115: s
	{ 0x04, 0x3F, 0x44, 0x40, 0x20 }, // 116: t
	{ 0x3C, 0x40, 0x40, 0x20, 0x7C }, // 117: u
	{ 0x1C, 0x20, 0x40, 0x20, 0x1C }, // 118: v
	{ 0x3C, 0x40, 0x30, 0x40, 0x3C }, // 119: w
	{ 0x44, 0x28, 0x10, 0x28, 0x44 }, // 120: x
	{ 0x0C, 0x50, 0x50, 0x50, 0x3C }, // 121: y
	{ 0x44, 0x64, 0x54, 0x4C, 0x44 }, // 122: z
	{ 0x00, 0x08, 0x36, 0x41, 0x00 }, // 123: {
	{ 0x00, 0x00, 0x7F, 0x00, 0x00 }, // 124: |
	{ 0x00, 0x41, 0x36, 0x08, 0x00 }, // 125: }
	{ 0x10, 0x08, 0x08, 0x10, 0x08 }, // 126: ~
};
void nokia_lcd_cfg_dc(nokia_lcd_mode_t mode)
{
	if (mode == nokia_lcd_mode_cmd)
		set_pin_low('c', 2);
	else
		set_pin_high('c', 2);
}

void nokia_lcd_cfg_reset(nokia_lcd_reset_t state)
{
	if (state == nokia_lcd_reset_asserted)
		set_pin_low('b', 3);
	else
		set_pin_high('b', 3);
}

void nokia_lcd_clr()
{
	nokia_lcd_tx(0, 0b00100000);
	nokia_lcd_set_xy(0, 0);
	for (int i=0; i<6*84; i++)
		nokia_lcd_tx(1, 0b00000000);
}

void nokia_lcd_disp_char(char ch)
{
	nokia_lcd_tx(1, 0x00);
	for (int i=0; i<5; i++)
	{
		nokia_lcd_tx(1, g_font_table[ch - 32][i]);
	}
	nokia_lcd_tx(1, 0x00);
}

void nokia_lcd_disp_char_xy(int x, int y, char ch)
{
	nokia_lcd_set_xy_char(x, y);
	nokia_lcd_disp_char(ch);
}

void nokia_lcd_init()
{
	nokia_lcd_cfg_reset(nokia_lcd_reset_asserted);
	for (int i=0; i<5; i++){}
	nokia_lcd_cfg_reset(nokia_lcd_reset_deasserted);
	nokia_lcd_tx(0, 0b00100001);
	nokia_lcd_tx(0, 0xB8);
	nokia_lcd_tx(0, 0b00000100);
	nokia_lcd_tx(0, 0b00010011);
	nokia_lcd_tx(0, 0b00100000);
	nokia_lcd_tx(0, 0b00001100);
	
}

void nokia_lcd_set_x(int x)
{
	nokia_lcd_tx(0, 0x80 | (uint8_t)x);
}

void nokia_lcd_set_x_char(int x)
{
	nokia_lcd_set_x(7 * x);
}

void nokia_lcd_set_xy(int x, int y)
{
	nokia_lcd_set_x(x);
	nokia_lcd_set_y(y);
}

void nokia_lcd_set_xy_char(int x, int y)
{
	nokia_lcd_set_x_char(x);
	nokia_lcd_set_y_char(y);
}

void nokia_lcd_set_y(int y)
{
	nokia_lcd_tx(0, 0x40 | (uint8_t)y);
}

void nokia_lcd_set_y_char(int y)
{
	nokia_lcd_set_y(y);
}

void nokia_lcd_tx(nokia_lcd_mode_t mode, uint8_t data)
{
	nokia_lcd_cfg_dc(mode);
	spi1_tx(data);
}
