#pragma once

typedef struct {char c; int x, y, w, h, xo, yo, xa; u8* data;}charDesc_s;
typedef struct
{
	u8* data;
	charDesc_s* desc;
	u8 height;
	u8 color[3];
}font_s;

extern u8 RobotoData[];
extern u8 robotoSmallData[];
extern charDesc_s RobotoDesc[];
extern charDesc_s robotoSmallDesc[];
extern font_s robootoBlack;
extern font_s robootoBlackSmall;
extern font_s robootoWhite;