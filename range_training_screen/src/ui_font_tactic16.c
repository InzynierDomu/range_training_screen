/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --font C:/Users/Lenovo/SquareLine/assets/borneox.regular.otf -o C:/Users/Lenovo/SquareLine/assets\ui_font_tactic16.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_TACTIC16
#define UI_FONT_TACTIC16 1
#endif

#if UI_FONT_TACTIC16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0x60,

    /* U+0022 "\"" */
    0xb4,

    /* U+0023 "#" */
    0x0, 0x83, 0x10, 0x62, 0x8, 0xcf, 0xfe, 0x22,
    0x3f, 0xf9, 0x88, 0x23, 0x4, 0x60, 0x88, 0x0,

    /* U+0024 "$" */
    0x4, 0x0, 0x81, 0xff, 0xa2, 0x4, 0x40, 0xff,
    0x81, 0x8, 0x21, 0xff, 0xc0, 0x80, 0x10, 0x0,

    /* U+0026 "&" */
    0x7f, 0xcc, 0x0, 0x80, 0x8, 0x4, 0xc0, 0x47,
    0xff, 0xc0, 0x48, 0x4, 0x80, 0x4c, 0x4, 0x7f,
    0xc0,

    /* U+0027 "'" */
    0xc0,

    /* U+0028 "(" */
    0x1e, 0x41, 0x4, 0x8, 0x10, 0x20, 0x40, 0x40,
    0x40, 0x78,

    /* U+0029 ")" */
    0xe0, 0x40, 0x81, 0x4, 0x10, 0x41, 0x8, 0x4e,
    0x0,

    /* U+002B "+" */
    0x8, 0x8, 0x8, 0x8, 0xff, 0x8, 0x8, 0x8,

    /* U+002C "," */
    0x70,

    /* U+002D "-" */
    0xff,

    /* U+002E "." */
    0xc0,

    /* U+0030 "0" */
    0x7f, 0x60, 0xe0, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x80, 0xe0, 0xdf, 0xc0,

    /* U+0031 "1" */
    0x3c, 0x92, 0x49, 0x24, 0x80,

    /* U+0032 "2" */
    0xfe, 0x1, 0x1, 0x1, 0x3, 0x6, 0x1c, 0x38,
    0x70, 0xe0, 0xff,

    /* U+0033 "3" */
    0xff, 0x80, 0x30, 0x4, 0x1, 0x0, 0xff, 0xe0,
    0xc, 0x1, 0x0, 0x40, 0x3f, 0xf8,

    /* U+0034 "4" */
    0x8, 0x6, 0x3, 0x0, 0x84, 0x61, 0x30, 0x4f,
    0xfc, 0x4, 0x1, 0x0, 0x40, 0x10,

    /* U+0035 "5" */
    0xff, 0x40, 0x20, 0x10, 0x8, 0x7, 0xf8, 0x6,
    0x1, 0x0, 0x80, 0xff, 0xc0,

    /* U+0036 "6" */
    0x7f, 0xe0, 0x20, 0x10, 0x8, 0x7, 0xfa, 0x7,
    0x1, 0x80, 0xe0, 0xdf, 0xc0,

    /* U+0037 "7" */
    0xff, 0xc0, 0xc, 0x1, 0x80, 0x60, 0x8, 0x3,
    0x0, 0xc0, 0x18, 0x6, 0x0, 0x80, 0x30, 0x0,

    /* U+0038 "8" */
    0x7f, 0xb0, 0x38, 0x6, 0x1, 0xc0, 0xdf, 0xec,
    0xe, 0x1, 0x80, 0x70, 0x37, 0xf8,

    /* U+0039 "9" */
    0x7f, 0x60, 0xe0, 0x30, 0x1c, 0xb, 0xfc, 0x2,
    0x1, 0x0, 0x80, 0x40, 0x20,

    /* U+003A ":" */
    0xcc,

    /* U+003B ";" */
    0x50, 0x14,

    /* U+003D "=" */
    0xff, 0x0, 0x0, 0xff,

    /* U+003F "?" */
    0xff, 0x40, 0xe0, 0x30, 0x10, 0x18, 0x78, 0x20,
    0x10, 0x0, 0x4, 0x2, 0x0,

    /* U+0040 "@" */
    0x7f, 0xa0, 0x18, 0x6, 0x7d, 0x91, 0x64, 0x59,
    0x1e, 0x7f, 0x80, 0x60, 0x7, 0xe0,

    /* U+0041 "A" */
    0x7f, 0xa0, 0x18, 0x6, 0x1, 0x80, 0x7f, 0xf8,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x4,

    /* U+0042 "B" */
    0xff, 0xa0, 0x38, 0x6, 0x1, 0x80, 0xff, 0xe8,
    0xe, 0x1, 0x80, 0x60, 0x3f, 0xf8,

    /* U+0043 "C" */
    0x7f, 0xf8, 0x2, 0x0, 0x40, 0x8, 0x1, 0x0,
    0x20, 0x4, 0x0, 0x80, 0x18, 0x1, 0xff, 0x80,

    /* U+0044 "D" */
    0xff, 0xa0, 0x38, 0x6, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x80, 0x60, 0x3f, 0xf8,

    /* U+0045 "E" */
    0x7f, 0xf8, 0x2, 0x0, 0x40, 0x8, 0x1, 0xfe,
    0x20, 0x4, 0x0, 0x80, 0x18, 0x1, 0xff, 0x80,

    /* U+0046 "F" */
    0x7f, 0xd8, 0x2, 0x0, 0x40, 0x8, 0x1, 0xfc,
    0x20, 0x4, 0x0, 0x80, 0x10, 0x2, 0x0, 0x0,

    /* U+0047 "G" */
    0x7f, 0xf0, 0x8, 0x2, 0x0, 0x80, 0x27, 0xe8,
    0xe, 0x1, 0x80, 0x70, 0x17, 0xfc,

    /* U+0048 "H" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0x80, 0x7f, 0xf8,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x4,

    /* U+0049 "I" */
    0xff, 0xe0,

    /* U+004A "J" */
    0x11, 0x11, 0x11, 0x11, 0x13, 0xe0,

    /* U+004B "K" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0x80, 0xff, 0xe8,
    0xe, 0x1, 0x80, 0x60, 0x18, 0x4,

    /* U+004C "L" */
    0x80, 0x10, 0x2, 0x0, 0x40, 0x8, 0x1, 0x0,
    0x20, 0x4, 0x0, 0x80, 0x18, 0x1, 0xff, 0x80,

    /* U+004D "M" */
    0xc0, 0x7c, 0x1f, 0xc7, 0xdc, 0xd9, 0xf3, 0x1c,
    0x60, 0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0x80,

    /* U+004E "N" */
    0xc0, 0x70, 0x1e, 0x6, 0xc1, 0x98, 0x63, 0x18,
    0x66, 0xd, 0x81, 0xe0, 0x38, 0xc,

    /* U+004F "O" */
    0x7f, 0xb0, 0x38, 0x6, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x80, 0x70, 0x37, 0xf8,

    /* U+0050 "P" */
    0xff, 0xa0, 0x38, 0x6, 0x1, 0x80, 0xff, 0xe8,
    0x2, 0x0, 0x80, 0x20, 0x8, 0x0,

    /* U+0051 "Q" */
    0x7f, 0x98, 0x1a, 0x1, 0x40, 0x28, 0x5, 0x0,
    0xa0, 0x14, 0x2, 0x83, 0x58, 0x39, 0xff, 0x0,
    0x10,

    /* U+0052 "R" */
    0xff, 0xa0, 0x38, 0x6, 0x1, 0x80, 0xff, 0xe8,
    0xe, 0x1, 0x80, 0x60, 0x18, 0x4,

    /* U+0053 "S" */
    0x7f, 0xf0, 0x8, 0x2, 0x0, 0xc0, 0x1f, 0xe0,
    0xc, 0x1, 0x0, 0x40, 0x3f, 0xf8,

    /* U+0054 "T" */
    0xff, 0xc1, 0x0, 0x40, 0x10, 0x4, 0x1, 0x0,
    0x40, 0x10, 0x4, 0x1, 0x0, 0x40,

    /* U+0055 "U" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x80, 0x70, 0x37, 0xf8,

    /* U+0056 "V" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0xc0, 0x90, 0x24,
    0x8, 0x84, 0x21, 0xc, 0xc1, 0xe0,

    /* U+0057 "W" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0x80, 0x60, 0x18,
    0xc6, 0x79, 0x9e, 0x7c, 0xf7, 0x38,

    /* U+0058 "X" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0xc0, 0xdf, 0xec,
    0xe, 0x1, 0x80, 0x60, 0x18, 0x4,

    /* U+0059 "Y" */
    0x80, 0x30, 0x6, 0x0, 0xc0, 0x1c, 0x6, 0x7f,
    0x81, 0x0, 0x20, 0x4, 0x0, 0x80, 0x10, 0x0,

    /* U+005A "Z" */
    0xff, 0xc0, 0x18, 0x6, 0x1, 0x80, 0x60, 0x18,
    0x7, 0x1, 0xc0, 0x70, 0x1c, 0x3, 0xff, 0x80,

    /* U+005B "[" */
    0xf8, 0x88, 0x88, 0x88, 0x88, 0xf0,

    /* U+005D "]" */
    0xf1, 0x11, 0x11, 0x11, 0x11, 0xf0,

    /* U+005F "_" */
    0xff, 0x80,

    /* U+0061 "a" */
    0x7f, 0xa0, 0x18, 0x6, 0x1, 0x80, 0x7f, 0xf8,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x4,

    /* U+0062 "b" */
    0xff, 0xa0, 0x38, 0x6, 0x1, 0x80, 0xff, 0xe8,
    0xe, 0x1, 0x80, 0x60, 0x3f, 0xf8,

    /* U+0063 "c" */
    0x7f, 0xf8, 0x2, 0x0, 0x40, 0x8, 0x1, 0x0,
    0x20, 0x4, 0x0, 0x80, 0x18, 0x1, 0xff, 0x80,

    /* U+0064 "d" */
    0xff, 0xa0, 0x38, 0x6, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x80, 0x60, 0x3f, 0xf8,

    /* U+0065 "e" */
    0x7f, 0xf8, 0x2, 0x0, 0x40, 0x8, 0x1, 0xfe,
    0x20, 0x4, 0x0, 0x80, 0x18, 0x1, 0xff, 0x80,

    /* U+0066 "f" */
    0x7f, 0xd8, 0x2, 0x0, 0x40, 0x8, 0x1, 0xfc,
    0x20, 0x4, 0x0, 0x80, 0x10, 0x2, 0x0, 0x0,

    /* U+0067 "g" */
    0x7f, 0xf0, 0x8, 0x2, 0x0, 0x80, 0x27, 0xe8,
    0xe, 0x1, 0x80, 0x70, 0x17, 0xfc,

    /* U+0068 "h" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0x80, 0x7f, 0xf8,
    0x6, 0x1, 0x80, 0x60, 0x18, 0x4,

    /* U+0069 "i" */
    0xff, 0xe0,

    /* U+006A "j" */
    0x11, 0x11, 0x11, 0x11, 0x13, 0xe0,

    /* U+006B "k" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0x80, 0xff, 0xe8,
    0xe, 0x1, 0x80, 0x60, 0x18, 0x4,

    /* U+006C "l" */
    0x80, 0x10, 0x2, 0x0, 0x40, 0x8, 0x1, 0x0,
    0x20, 0x4, 0x0, 0x80, 0x18, 0x1, 0xff, 0x80,

    /* U+006D "m" */
    0xc0, 0x7c, 0x1f, 0xc7, 0xdc, 0xd9, 0xf3, 0x1c,
    0x60, 0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0x80,

    /* U+006E "n" */
    0xc0, 0x70, 0x1e, 0x6, 0xc1, 0x98, 0x63, 0x18,
    0x66, 0xd, 0x81, 0xe0, 0x38, 0xc,

    /* U+006F "o" */
    0x7f, 0xb0, 0x38, 0x6, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x80, 0x70, 0x37, 0xf8,

    /* U+0070 "p" */
    0xff, 0xa0, 0x38, 0x6, 0x1, 0x80, 0xff, 0xe8,
    0x2, 0x0, 0x80, 0x20, 0x8, 0x0,

    /* U+0071 "q" */
    0x7f, 0x98, 0x1a, 0x1, 0x40, 0x28, 0x5, 0x0,
    0xa0, 0x14, 0x2, 0x83, 0x58, 0x39, 0xff, 0x0,
    0x10,

    /* U+0072 "r" */
    0xff, 0xa0, 0x38, 0x6, 0x1, 0x80, 0xff, 0xe8,
    0xe, 0x1, 0x80, 0x60, 0x18, 0x4,

    /* U+0073 "s" */
    0x7f, 0xf0, 0x8, 0x2, 0x0, 0xc0, 0x1f, 0xe0,
    0xc, 0x1, 0x0, 0x40, 0x3f, 0xf8,

    /* U+0074 "t" */
    0xff, 0xc1, 0x0, 0x40, 0x10, 0x4, 0x1, 0x0,
    0x40, 0x10, 0x4, 0x1, 0x0, 0x40,

    /* U+0075 "u" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0x80, 0x60, 0x18,
    0x6, 0x1, 0x80, 0x70, 0x37, 0xf8,

    /* U+0076 "v" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0xc0, 0x90, 0x24,
    0x8, 0x84, 0x21, 0xc, 0xc1, 0xe0,

    /* U+0077 "w" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0x80, 0x60, 0x18,
    0xc6, 0x79, 0x9e, 0x7c, 0xf7, 0x38,

    /* U+0078 "x" */
    0x80, 0x60, 0x18, 0x6, 0x1, 0xc0, 0xdf, 0xec,
    0xe, 0x1, 0x80, 0x60, 0x18, 0x4,

    /* U+0079 "y" */
    0x80, 0x30, 0x6, 0x0, 0xc0, 0x1c, 0x6, 0x7f,
    0x81, 0x0, 0x20, 0x4, 0x0, 0x80, 0x10, 0x0,

    /* U+007A "z" */
    0xff, 0xc0, 0x18, 0x6, 0x1, 0x80, 0x60, 0x18,
    0x7, 0x1, 0xc0, 0x70, 0x1c, 0x3, 0xff, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 92, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 48, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 68, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 4, .adv_w = 198, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 188, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 212, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 40, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 54, .adv_w = 125, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 64, .adv_w = 125, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 143, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 81, .adv_w = 46, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 82, .adv_w = 144, .box_w = 8, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 83, .adv_w = 39, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 176, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 73, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 159, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 189, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 127, .adv_w = 174, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 164, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 154, .adv_w = 164, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 199, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 190, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 162, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 42, .box_w = 1, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 49, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 213, .adv_w = 146, .box_w = 8, .box_h = 4, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 217, .adv_w = 168, .box_w = 9, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 230, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 244, .adv_w = 190, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 272, .adv_w = 191, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 190, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 179, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 318, .adv_w = 176, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 184, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 48, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 82, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 178, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 204, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 416, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 444, .adv_w = 183, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 458, .adv_w = 194, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 475, .adv_w = 189, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 489, .adv_w = 179, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 164, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 190, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 531, .adv_w = 175, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 545, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 559, .adv_w = 189, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 573, .adv_w = 175, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 172, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 605, .adv_w = 97, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 611, .adv_w = 97, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 617, .adv_w = 165, .box_w = 9, .box_h = 1, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 619, .adv_w = 190, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 633, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 647, .adv_w = 191, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 663, .adv_w = 190, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 677, .adv_w = 179, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 176, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 709, .adv_w = 184, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 737, .adv_w = 48, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 739, .adv_w = 82, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 745, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 759, .adv_w = 178, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 775, .adv_w = 204, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 791, .adv_w = 192, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 805, .adv_w = 188, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 819, .adv_w = 183, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 833, .adv_w = 194, .box_w = 11, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 850, .adv_w = 189, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 864, .adv_w = 179, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 878, .adv_w = 164, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 892, .adv_w = 190, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 906, .adv_w = 175, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 920, .adv_w = 191, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 934, .adv_w = 189, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 948, .adv_w = 175, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 964, .adv_w = 172, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 1, 2, 3, 4, 0, 5, 6,
    7, 8, 0, 9, 10, 11, 12, 0,
    13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 0, 25, 0, 26,
    27, 28, 29, 30, 31, 32, 33, 34,
    35, 36, 37, 38, 39, 40, 41, 42,
    43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 0, 55, 0, 56
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 64, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 64, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 58,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 2,
    3, 4, 5, 6, 7, 8, 4, 9,
    0, 0, 0, 0, 0, 10, 11, 12,
    13, 14, 15, 16, 17, 17, 18, 19,
    20, 17, 17, 13, 21, 22, 23, 24,
    25, 18, 26, 27, 19, 28, 29, 0,
    0, 0, 10, 11, 12, 13, 14, 15,
    16, 17, 17, 18, 19, 20, 17, 17,
    13, 21, 22, 23, 24, 25, 18, 26,
    27, 19, 28, 29
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 1,
    2, 3, 0, 4, 5, 4, 6, 7,
    8, 9, 10, 11, 6, 12, 13, 14,
    15, 15, 0, 16, 0, 17, 0, 18,
    0, 18, 17, 18, 0, 0, 19, 0,
    20, 0, 0, 18, 0, 18, 0, 0,
    21, 20, 22, 23, 0, 24, 25, 0,
    26, 27, 17, 0, 18, 0, 18, 17,
    18, 0, 0, 19, 0, 20, 0, 0,
    18, 0, 18, 0, 0, 21, 20, 22,
    23, 0, 24, 25
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, -7, -10,
    -9, -2, 0, -14, -1, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -4, -3, -3, 0, -10, -1,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, -6, 0, -4, -11,
    -2, -14, -4, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, -6,
    -9, 0, -6, -3, -14, -2, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, -12, -12, -10, 0, -6, -15,
    -6, -12, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, -7, -8, -4,
    -5, 0, -8, -3, -12, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    -7, -8, -4, -5, -5, -8, -3, -12,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, -11, -3, -13, -2,
    0, -5, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -7, -3,
    -5, -3, 0, -14, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, -3,
    0, 0, 0, 0, -3, 0, 0, -2,
    -8, -6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    -2, 0, -2, 0, 0, 0, -2, -8,
    0, 0, -13, 0, 0, -19, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -5, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -9, -8,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, 0, -3, 0,
    -3, 0, 0, 0, -3, -9, 0, 0,
    -10, 0, 0, -10, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -13, 0, -18, -10, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -14, 0, -3, -3, -27, 0, 0, 0,
    0, 0, 0, 0, -18, 0, -3, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, 0, 0, -3, -8, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, -4,
    -2, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -1,
    0, -18, -15, 0, 0, -18, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -18, 0, -3, 0, 0, -35, -27, 0,
    -34, 0, 0, 0, 0, -2, -5, -19,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, 0, 0, 0, -25, 0,
    0, 0, 0, 0, 0, -5, -19, -4,
    -5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -7, 0,
    -2, 0, -3, -7, -2, -3, -1, 0,
    0, 0, 0, -4, -1, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, -3, 0,
    0, 0, 0, -1, 0, 0, -3, 0,
    -4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -13, 0, -14, -14, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -14, 0,
    -3, -3, -26, 0, 0, 0, 0, 0,
    0, 0, -14, 0, -4, 0, -12, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -5, 0, 0, 0, -18, 0, 0,
    0, 0, 0, 0, 0, -11, 0, -1,
    -4, -5, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    0, 0, -2, 0, -14, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -5,
    0, 0, 0, -22, 0, 0, 0, 0,
    0, 0, 0, -14, 0, -10, 0, 0,
    -12, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 29,
    .right_class_cnt     = 27,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_tactic16 = {
#else
lv_font_t ui_font_tactic16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 12,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_TACTIC16*/

