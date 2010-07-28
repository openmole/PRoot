#include <unistd.h> /* syscall(2), */
#include <stdio.h>  /* perror(3), fprintf(3), */
#include <limits.h> /* PATH_MAX, */
#include <stdlib.h> /* exit(3), */
#include <string.h> /* strlen(3), */
#include <sys/syscall.h> /* SYS_readlink, SYS_getcwd, */

int main(void)
{
	char path[PATH_MAX];
	int status;

	status = syscall(SYS_readlink, "/proc/self/cwd", path, PATH_MAX);
	if (status < 0) {
		perror("readlink()");
		exit(EXIT_FAILURE);
	}

	if (status != strlen(path)) {
		fprintf(stderr, "readlink() returned the wrong size %d != %d.\n", status, strlen(path));
		exit(EXIT_FAILURE);
	}

	status = syscall(SYS_getcwd, path, PATH_MAX);
	if (status < 0) {
		perror("getcwd()");
		exit(EXIT_FAILURE);
	}

	if (status != strlen(path) + 1) {
		fprintf(stderr, "getcwd() returned the wrong size %d != %d.\n", status, strlen(path));
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}