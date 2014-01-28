#ifndef _BOARD_H
#define _BOARD_H

#include <stdint.h>

struct bit_board {
	uint16_t row[16];
};

struct bit_board R_KING_POS;
struct bit_board R_ADVISOR_POS;
struct bit_board R_BISHOP_POS;
struct bit_board R_KNIGHT_POS;
struct bit_board R_ROOK_POS;
struct bit_board R_CANNON_POS;
struct bit_board R_PAWN_POS;

struct bit_board B_KING_POS;
struct bit_board B_ADVISOR_POS;
struct bit_board B_BISHOP_POS;
struct bit_board B_KNIGHT_POS;
struct bit_board B_ROOK_POS;
struct bit_board B_CANNON_POS;
struct bit_board B_PAWN_POS;

struct bit_board R_ALL_POS;
struct bit_board B_ALL_POS;
struct bit_board ALL_POS;

void board_init(void);

#endif
