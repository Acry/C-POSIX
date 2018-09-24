/* stat.c
 * use of fstat
 */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(void)
{

	struct stat fileStat;
	
	if(stat("stat.c",&fileStat) < 0)
		return EXIT_FAILURE;
	
	printf("%s summery:\n","stat.c");
	printf("Size: \t\t\t%ld bytes\n",fileStat.st_size);
	printf("Number of Links: \t%lu\n",fileStat.st_nlink);
	printf("File inode: \t\t%lu\n",fileStat.st_ino);

	printf("The file %s a directory\n", (S_ISDIR(fileStat.st_mode)) ? "is" : "is not");
	printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
	
	return EXIT_SUCCESS;
}
