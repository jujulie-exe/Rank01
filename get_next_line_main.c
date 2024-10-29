
#include "get_next_line.h"

int	main()
{
	int fd;


	fd = open("stdio.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	printf("%s\n", get_next_line(fd));
	return (0);
}
