#include "pipe_data.h"

void	free_job(t_cmd *job)
{
	t_cmd	*current;
	t_cmd	*tmp;

	current = job;
	while (current != NULL)
	{
		tmp = current->next;
		free(current->av);
		free(current->arg);
		free(current->eof);
		current = tmp;
	}
	free(job);
}
