/* pipe.c
 * pipe stream to or from a process
 */

#include <stdio.h>
#include <stdlib.h>
int main(void)
{

	char have[20];
	FILE *fd = popen("uname -s", "r");
	fgets(have, sizeof(have), fd);
	printf("%s",have);
	pclose(fd);
	
	return EXIT_SUCCESS;
}
