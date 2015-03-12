#include <3ds.h>
#include "font.h"

font_s robootoBlack =
{
	RobotoData,
	RobotoDesc,
	24,
	(u8[]){0x00,0x00,0x00}
};

font_s robootoBlackSmall =
{
	robotoSmallData,
	robotoSmallDesc,
	18,
	(u8[]){0x40,0x40,0x40}
};

font_s robootoWhite =
{
	RobotoData,
	RobotoDesc,
	24,
	(u8[]){0xFF,0xFF,0xFF}
};