#include "move.h"

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
