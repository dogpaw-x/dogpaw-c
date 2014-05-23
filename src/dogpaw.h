#ifndef _DOGPAW_H
#define _DOGPAW_H

#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "board_init_data.h"
#include "list.h"
#include "debug.h"

#define NUM_BOARD (32 + 3)  /* 32 个棋子 + 3 个位棋盘 */
#define ROW_BOARD 16

#define X(name, p1, p2, p3, p4, p5) name,
enum BOARD {
	BOARD_INIT_TABLE
};
#undef X

struct bit_board {
	uint16_t row[ROW_BOARD];
};

struct status_s {
	struct bit_board board[NUM_BOARD];
};

void board_init(struct bit_board board[NUM_BOARD]);

#endif
