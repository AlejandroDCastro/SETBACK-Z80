#include "lineadepinxos.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2017
// Palette uses hardware values.
const u8 linea_pin_pal[16] = { 0x54, 0x44, 0x55, 0x5c, 0x4c, 0x56, 0x57, 0x5e, 0x40, 0x5f, 0x4e, 0x52, 0x53, 0x4a, 0x43, 0x4b };

// Tile linea_pin_sp: 100x10 pixels, 50x10 bytes.
const u8 linea_pin_sp[50 * 10] = {
	0x05, 0x00, 0x0f, 0x0a, 0x05, 0x05, 0x00, 0x0f, 0x0a, 0x05, 0x05, 0x00, 0x0f, 0x0a, 0x05, 0x05, 0x00, 0x0f, 0x0a, 0x05, 0x05, 0x00, 0x0f, 0x0a, 0x05, 0x05, 0x00, 0x0f, 0x0a, 0x05, 0x05, 0x00, 0x0f, 0x0a, 0x05, 0x05, 0x00, 0x0f, 0x0a, 0x05, 0x05, 0x00, 0x0f, 0x0a, 0x05, 0x05, 0x00, 0x0f, 0x0a, 0x05,
	0x05, 0x05, 0x5b, 0x0a, 0x00, 0x05, 0x05, 0x5b, 0x0a, 0x00, 0x05, 0x05, 0x5b, 0x0a, 0x00, 0x05, 0x05, 0x5b, 0x0a, 0x00, 0x05, 0x05, 0x5b, 0x0a, 0x00, 0x05, 0x05, 0x5b, 0x0a, 0x00, 0x05, 0x05, 0x5b, 0x0a, 0x00, 0x05, 0x05, 0x5b, 0x0a, 0x00, 0x05, 0x05, 0x5b, 0x0a, 0x00, 0x05, 0x05, 0x5b, 0x0a, 0x00,
	0x00, 0x05, 0xf3, 0x0f, 0x00, 0x00, 0x05, 0xf3, 0x0f, 0x00, 0x00, 0x05, 0xf3, 0x0f, 0x00, 0x00, 0x05, 0xf3, 0x0f, 0x00, 0x00, 0x05, 0xf3, 0x0f, 0x00, 0x00, 0x05, 0xf3, 0x0f, 0x00, 0x00, 0x05, 0xf3, 0x0f, 0x00, 0x00, 0x05, 0xf3, 0x0f, 0x00, 0x00, 0x05, 0xf3, 0x0f, 0x00, 0x00, 0x05, 0xf3, 0x0f, 0x00,
	0x00, 0x5b, 0xf3, 0xa7, 0x00, 0x00, 0x5b, 0xf3, 0xa7, 0x00, 0x00, 0x5b, 0xf3, 0xa7, 0x00, 0x00, 0x5b, 0xf3, 0xa7, 0x00, 0x00, 0x5b, 0xf3, 0xa7, 0x00, 0x00, 0x5b, 0xf3, 0xa7, 0x00, 0x00, 0x5b, 0xf3, 0xa7, 0x00, 0x00, 0x5b, 0xf3, 0xa7, 0x00, 0x00, 0x5b, 0xf3, 0xa7, 0x00, 0x00, 0x5b, 0xf3, 0xa7, 0x00,
	0x00, 0x5b, 0xf3, 0xa7, 0x0a, 0x00, 0x5b, 0xf3, 0xa7, 0x0a, 0x00, 0x5b, 0xf3, 0xa7, 0x0a, 0x00, 0x5b, 0xf3, 0xa7, 0x0a, 0x00, 0x5b, 0xf3, 0xa7, 0x0a, 0x00, 0x5b, 0xf3, 0xa7, 0x0a, 0x00, 0x5b, 0xf3, 0xa7, 0x0a, 0x00, 0x5b, 0xf3, 0xa7, 0x0a, 0x00, 0x5b, 0xf3, 0xa7, 0x0a, 0x00, 0x5b, 0xf3, 0xa7, 0x0a,
	0x0f, 0x5b, 0xb2, 0xf3, 0x0a, 0x0f, 0x5b, 0xb2, 0xf3, 0x0a, 0x0f, 0x5b, 0xb2, 0xf3, 0x0a, 0x0f, 0x5b, 0xb2, 0xf3, 0x0a, 0x0f, 0x5b, 0xb2, 0xf3, 0x0a, 0x0f, 0x5b, 0xb2, 0xf3, 0x0a, 0x0f, 0x5b, 0xb2, 0xf3, 0x0a, 0x0f, 0x5b, 0xb2, 0xf3, 0x0a, 0x0f, 0x5b, 0xb2, 0xf3, 0x0a, 0x0f, 0x5b, 0xb2, 0xf3, 0x0a,
	0x5b, 0xf3, 0xb2, 0xf3, 0x0f, 0x5b, 0xf3, 0xb2, 0xf3, 0x0f, 0x5b, 0xf3, 0xb2, 0xf3, 0x0f, 0x5b, 0xf3, 0xb2, 0xf3, 0x0f, 0x5b, 0xf3, 0xb2, 0xf3, 0x0f, 0x5b, 0xf3, 0xb2, 0xf3, 0x0f, 0x5b, 0xf3, 0xb2, 0xf3, 0x0f, 0x5b, 0xf3, 0xb2, 0xf3, 0x0f, 0x5b, 0xf3, 0xb2, 0xf3, 0x0f, 0x5b, 0xf3, 0xb2, 0xf3, 0x0f,
	0x5b, 0xf3, 0x30, 0x71, 0xa7, 0x5b, 0xf3, 0x30, 0x71, 0xa7, 0x5b, 0xf3, 0x30, 0x71, 0xa7, 0x5b, 0xf3, 0x30, 0x71, 0xa7, 0x5b, 0xf3, 0x30, 0x71, 0xa7, 0x5b, 0xf3, 0x30, 0x71, 0xa7, 0x5b, 0xf3, 0x30, 0x71, 0xa7, 0x5b, 0xf3, 0x30, 0x71, 0xa7, 0x5b, 0xf3, 0x30, 0x71, 0xa7, 0x5b, 0xf3, 0x30, 0x71, 0xa7,
	0x05, 0xb2, 0x30, 0x71, 0x0a, 0x05, 0xb2, 0x30, 0x71, 0x0a, 0x05, 0xb2, 0x30, 0x71, 0x0a, 0x05, 0xb2, 0x30, 0x71, 0x0a, 0x05, 0xb2, 0x30, 0x71, 0x0a, 0x05, 0xb2, 0x30, 0x71, 0x0a, 0x05, 0xb2, 0x30, 0x71, 0x0a, 0x05, 0xb2, 0x30, 0x71, 0x0a, 0x05, 0xb2, 0x30, 0x71, 0x0a, 0x05, 0xb2, 0x30, 0x71, 0x0a,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03
};

