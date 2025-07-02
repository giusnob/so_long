#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main (void)
{
	int		fd;
	char	*str;

	fd = open("file.txt", O_RDONLY);
	str =  get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
	return (0);
}