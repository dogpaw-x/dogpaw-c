#include <assert.h>
#include "board.h"

static void board_addpos(struct bit_board *b, uint8_t pos)
{
	assert(pos >= 0 && pos <= 0xff);
	b->row[pos & 0xf0] |= 0x1 << (pos & 0x0f);
}

static void board_or_pos(struct bit_board *dst, const struct bit_board *src)
{
	int i;

	for (i = 0; i < 16; i++)
		dst->row[i] |= src->row[i];
}

void board_init(void)
{
	board_addpos(&R_KING_POS, 0xc7);
	board_addpos(&R_ADVISOR_POS, 0xc6);
	board_addpos(&R_ADVISOR_POS, 0xc8);
	board_addpos(&R_BISHOP_POS, 0xc5);
	board_addpos(&R_BISHOP_POS, 0xc9);
	board_addpos(&R_KNIGHT_POS, 0xc4);
	board_addpos(&R_KNIGHT_POS, 0xca);
	board_addpos(&R_ROOK_POS, 0xc3);
	board_addpos(&R_ROOK_POS, 0xcb);
	board_addpos(&R_CANNON_POS, 0xa4);
	board_addpos(&R_CANNON_POS, 0xaa);
	board_addpos(&R_PAWN_POS, 0x93);
	board_addpos(&R_PAWN_POS, 0x95);
	board_addpos(&R_PAWN_POS, 0x97);
	board_addpos(&R_PAWN_POS, 0x99);
	board_addpos(&R_PAWN_POS, 0x9b);

	board_addpos(&B_KING_POS, 0x37);
	board_addpos(&B_ADVISOR_POS, 0x36);
	board_addpos(&B_ADVISOR_POS, 0x38);
	board_addpos(&B_BISHOP_POS, 0x35);
	board_addpos(&B_BISHOP_POS, 0x39);
	board_addpos(&B_KNIGHT_POS, 0x34);
	board_addpos(&B_KNIGHT_POS, 0x3a);
	board_addpos(&B_ROOK_POS, 0x33);
	board_addpos(&B_ROOK_POS, 0x3b);
	board_addpos(&B_CANNON_POS, 0x54);
	board_addpos(&B_CANNON_POS, 0x5a);
	board_addpos(&B_PAWN_POS, 0x63);
	board_addpos(&B_PAWN_POS, 0x65);
	board_addpos(&B_PAWN_POS, 0x67);
	board_addpos(&B_PAWN_POS, 0x69);
	board_addpos(&B_PAWN_POS, 0x6b);

	board_or_pos(&R_ALL_POS, &R_KING_POS);
	board_or_pos(&R_ALL_POS, &R_ADVISOR_POS);
	board_or_pos(&R_ALL_POS, &R_BISHOP_POS);
	board_or_pos(&R_ALL_POS, &R_KNIGHT_POS);
	board_or_pos(&R_ALL_POS, &R_ROOK_POS);
	board_or_pos(&R_ALL_POS, &R_CANNON_POS);
	board_or_pos(&R_ALL_POS, &R_PAWN_POS);

	board_or_pos(&B_ALL_POS, &B_KING_POS);
	board_or_pos(&B_ALL_POS, &B_ADVISOR_POS);
	board_or_pos(&B_ALL_POS, &B_BISHOP_POS);
	board_or_pos(&B_ALL_POS, &B_KNIGHT_POS);
	board_or_pos(&B_ALL_POS, &B_ROOK_POS);
	board_or_pos(&B_ALL_POS, &B_CANNON_POS);
	board_or_pos(&B_ALL_POS, &B_PAWN_POS);

	board_or_pos(&ALL_POS, &R_ALL_POS);
	board_or_pos(&ALL_POS, &B_ALL_POS);
}
