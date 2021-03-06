#include "move.h"

/* 红帅可移动位置 */
struct bit_board R_KING_MOVEABLE = {
	{
		0, 0, 0,
		0, 0, 0,
		0, 0,
		0, 0,
		1<<6|1<<7|1<<8, 1<<6|1<<7|1<<8, 1<<6|1<<7|1<<8,
		0, 0, 0
	},
};

/* 黑将可移动位置 */
struct bit_board B_KING_MOVEABLE = {
	{
		0, 0, 0,
		1<<6|1<<7|1<<8, 1<<6|1<<7|1<<8, 1<<6|1<<7|1<<8,
		0, 0,
		0, 0,
		0, 0, 0,
		0, 0, 0
	},
};

/* 红士可移动位置 */
struct bit_board R_ADVISOR_MOVEABLE = {
	{
		0, 0, 0,
		0, 0, 0,
		0, 0,
		0, 0,
		1<<6|1<<8, 1<<7, 1<<6|1<<8,
		0, 0, 0
	},
};

/* 黑士可移动位置 */
struct bit_board B_ADVISOR_MOVEABLE = {
	{
		0, 0, 0,
		1<<6|1<<8, 1<<7, 1<<6|1<<8,
		0, 0,
		0, 0,
		0, 0, 0,
		0, 0, 0
	},
};
