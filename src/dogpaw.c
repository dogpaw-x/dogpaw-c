#include "dogpaw.h"

int main(int argc, char **argv)
{
	struct status_s *status;

	status = calloc(1, sizeof(typeof(status)));
	board_init(status->board);

	free(status);
	return 0;
}
