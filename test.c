#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int main ()
{
//	char buff[100];
	int fd;
	int chars_read;
	fd =open("file.txt",O_RDONLY);
/*	while (chars_read=read(fd,buff,10))
	{
		buff[chars_read]='\0';
		printf("buff -> %s\n",buff);
	}*/
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	return 0;
}
