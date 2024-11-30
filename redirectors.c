#include "pipe_data.h"

void	redirect_input(int old_fd)
{
	if (old_fd != 0)
	{
		dup2(old_fd, 0);
		close(old_fd);
	}
}

void	redirect_output(int old_fd)
{
	if (old_fd != 1)
	{
		dup2(old_fd, 1);
		close(old_fd);
	}
}
