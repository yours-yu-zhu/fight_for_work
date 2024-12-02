#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define BUFFSIZE 4096

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s source target\n", prog_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int src_fd, dest_fd, n;
    char buf[BUFFSIZE];
    struct stat statbuf;
    char *dest_path;

    // Check for correct number of arguments
    if (argc != 3) {
        usage(argv[0]);
    }

    // Open source file
    if ((src_fd = open(argv[1], O_RDONLY)) < 0) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Check if target is a directory
    if (stat(argv[2], &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
        // Allocate memory for the new destination path (directory + filename)
        dest_path = malloc(strlen(argv[2]) + strlen(argv[1]) + 2);
        if (!dest_path) {
            perror("Error allocating memory");
            close(src_fd);
            exit(EXIT_FAILURE);
        }

        // Construct the destination path
        snprintf(dest_path, strlen(argv[2]) + strlen(argv[1]) + 2, "%s/%s", argv[2], strrchr(argv[1], '/') ? strrchr(argv[1], '/') + 1 : argv[1]);
    } else {
        // Destination is a file
        dest_path = argv[2];
    }

    // Open destination file
    if ((dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
        perror("Error opening/creating target file");
        close(src_fd);
        if (dest_path != argv[2]) {
            free(dest_path);
        }
        exit(EXIT_FAILURE);
    }

    // Copy data from source to destination
    while ((n = read(src_fd, buf, BUFFSIZE)) > 0) {
        if (write(dest_fd, buf, n) != n) {
            perror("Write error");
            close(src_fd);
            close(dest_fd);
            if (dest_path != argv[2]) {
                free(dest_path);
            }
            exit(EXIT_FAILURE);
        }
    }

    if (n < 0) {
        perror("Read error");
    }

    // Clean up and close files
    close(src_fd);
    close(dest_fd);

    if (dest_path != argv[2]) {
        free(dest_path);
    }

    return EXIT_SUCCESS;
}
