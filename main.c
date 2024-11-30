#include "pipe_data.h"

void	piper(t_data *d, t_cmd *current)
{
	if (pipe(d->pipefd) == -1)	
	{
		perror("pipefd");
		exit(1);
	}
	d->output_fd = d->pipefd[1];
	new_process(d, current);
	close(d->pipefd[1]);
	d->input_fd = d->pipefd[0];
}

void	traverser(t_data *d)
{
	t_cmd	*current;

	current = d->job;
	d->input_fd = 0;
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			piper(d, current);
		}
		else
		{
			d->output_fd = 1;
			new_process(d, current);
		}
		current = current->next;
	}
	wait(NULL); // works without this, but seems safer
}

void	executor(t_data *d)
{
	if (!d)
		return ;
	traverser(d);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*d;

	d = NULL;
	d = init_data(ac, av, envp);
	if (!d)
		return (4);
	printf_job(d->job);
	executor(d);
	free_job(d->job);
	free(d);
}
