#include "dogpaw.h"

static void board_addpos(struct bit_board *b, uint8_t pos)
{
	if (pos == 0)
		return;
	b->row[pos & 0xf0] |= 0x1 << (pos & 0x0f);
}

static void board_or_pos(struct bit_board *dst, const struct bit_board *src)
{
	int i;

	for (i = 0; i < 16; i++)
		dst->row[i] |= src->row[i];
}

void board_init(struct bit_board board[NUM_BOARD])
{
#define X(name, p1, p2, p3, p4, p5) \
	board_addpos(&board[name], p1); \
	board_addpos(&board[name], p2); \
	board_addpos(&board[name], p3); \
	board_addpos(&board[name], p4); \
	board_addpos(&board[name], p5); \

	BOARD_INIT_TABLE
#undef X
	board_or_pos(&board[R_ALL_POS], &board[R_KING_POS]);
	board_or_pos(&board[R_ALL_POS], &board[R_ADVISOR_POS]);
	board_or_pos(&board[R_ALL_POS], &board[R_BISHOP_POS]);
	board_or_pos(&board[R_ALL_POS], &board[R_KNIGHT_POS]);
	board_or_pos(&board[R_ALL_POS], &board[R_ROOK_POS]);
	board_or_pos(&board[R_ALL_POS], &board[R_CANNON_POS]);
	board_or_pos(&board[R_ALL_POS], &board[R_PAWN_POS]);

	board_or_pos(&board[B_ALL_POS], &board[B_KING_POS]);
	board_or_pos(&board[B_ALL_POS], &board[B_ADVISOR_POS]);
	board_or_pos(&board[B_ALL_POS], &board[B_BISHOP_POS]);
	board_or_pos(&board[B_ALL_POS], &board[B_KNIGHT_POS]);
	board_or_pos(&board[B_ALL_POS], &board[B_ROOK_POS]);
	board_or_pos(&board[B_ALL_POS], &board[B_CANNON_POS]);
	board_or_pos(&board[B_ALL_POS], &board[B_PAWN_POS]);

	board_or_pos(&board[ALL_POS], &board[R_ALL_POS]);
	board_or_pos(&board[ALL_POS], &board[B_ALL_POS]);
}
