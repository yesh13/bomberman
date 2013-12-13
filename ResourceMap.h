#if !defined(RESORCEMAP_H)
#define RESORCEMAP_H

#define BMP_CHARACTER	0x00000000
#define BMP_BLOCK		0x00010000
#define BMP_BLANK		0x00010000
#define BMP_STONE		0x00010100
#define BMP_BOX			0x00010201
#define BMP_ROCK		0x00010300
#define BMP_ITEM		0x00010400
#define BMP_BOMB		0x00010500
#define BMP_EDGE		0x00010301

long GetResID(long Type);

#endif
