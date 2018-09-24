#include <stdio.h>
#include <stdlib.h>
// #include <sys/types.h>
#include <sys/stat.h>
// #include <unistd.h>

// POSIX USE OF FSTATAT(3P)/stat

// int stat(const char *path, struct stat *buf);
// const char *path	The file descriptor of the file that is being inquired.
// struct stat *buf	A structure where data about the file will be stored.

// return value	Returns a negative value on failure.

int main(int argc, char **argv)
{
// 	if(argc != 2)
// 		return EXIT_FAILURE;

	struct stat fileStat;
	
// 	if(stat(argv[1],&fileStat) < 0)
	if(stat("stat.c",&fileStat) < 0)
		return EXIT_FAILURE;
	
// 	printf("%s summery:\n",argv[1]);
	printf("%s summery:\n","stat.c");
	printf("Size: \t\t\t%ld bytes\n",fileStat.st_size);
	printf("Number of Links: \t%lu\n",fileStat.st_nlink);
	printf("File inode: \t\t%lu\n",fileStat.st_ino);

	printf("The file %s a directory\n", (S_ISDIR(fileStat.st_mode)) ? "is" : "is not");
	printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
	
	return EXIT_SUCCESS;
}
