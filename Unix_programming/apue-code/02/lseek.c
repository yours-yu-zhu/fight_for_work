/* This file is part of the sample code and exercises
 * used by the class "Advanced Programming in the UNIX
 * Environment" taught by Jan Schaumann
 * <jschauma@netmeister.org> at Stevens Institute of
 * Technology.
 *
 * This file is in the public domain.
 *
 * You don't have to, but if you feel like
 * acknowledging where you got this code, you may
 * reference me by name, email address, or point
 * people to the course website:
 * https://stevens.netmeister.org/631/
 */

/*
 * This trivial program verifies whether or not STDIN is seekable.  Test
 * on a regular file, on a pipe or a fifo.
 */

#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(void) {
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1 )
		printf("cannot seek\n");
	else
		printf("seek OK\n");

	return EXIT_SUCCESS;
}