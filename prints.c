#include "pipe_data.h"

void	printf_job(t_cmd *job)
{
	t_cmd	*current;

	current = job;
	if (current)
		printf("CURRENT\n");
	while (current != NULL)
	{
		printf("Av:\t%s\n", current->av);
		printf("Arg:\t%s\n", current->arg);
		printf("Eof:\t%s\n", current->eof);
		printf("Open_fd:\t%d\n", current->open_fd);
		printf("Append_fd:\t%d\n\n", current->append_fd);
		current = current->next;
	}
}
