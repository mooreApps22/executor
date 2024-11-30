
#include "pipe_data.h"

int	open_fd(char *arg)
{
	int	fd;	

	fd = open(arg, O_RDWR | O_CREAT, 0666);
	if (fd == -1)
		return (-1);
	return (fd);
}

int	append_fd(char *arg)
{
	int	fd;	

	fd = open(arg, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (fd == -1)
		return (-1);
	return (fd);
}
