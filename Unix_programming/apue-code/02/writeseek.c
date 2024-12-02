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
 * If you create a new file, write, say,
 * 10 bytes of data, and then seek to the
 * end of the file, where do you end up? Why?
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define WFILE "/tmp/rw"
#define DLEN 10

int
main() {
	int fd, n;
	char data[DLEN];
	bzero(data, DLEN);

	if ((fd = open(WFILE, O_RDWR | O_CREAT | O_EXCL, 0700)) == -1) {
		fprintf(stderr, "Unable to open '%s': %s\n",
				WFILE, strerror(errno));
		exit(EXIT_FAILURE);
	}

	if (write(fd, data, DLEN) != DLEN) {
		fprintf(stderr, "Unable to write: %s\n",
					strerror(errno));
			exit(EXIT_FAILURE);
	}

	if ((n = lseek(fd, 0, SEEK_END)) == 0) {
		fprintf(stderr, "Unable to seek: %s\n",
				strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("Seeked to offset %d\n", n);

	(void)close(fd);
	return EXIT_SUCCESS;
}
