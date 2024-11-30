#include "pipe_data.h"
/*
t_cmd	*init_empty_cmd()
{
	t_cmd	*cmd;

	cmd	= malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->av = NULL;
	cmd->arg = NULL;
	cmd->eof = NULL;
	return (cmd);
}
*/
t_cmd	*init_job(char **av)
{
	t_cmd	*job;
	t_cmd	*new;

	av++;
	job = init_cmd(*av);
	av++;
	while (*av)
	{
		new = init_cmd(*av);
		add_to_job(&job, new);
		av++;
	}
	return (job);
}

t_data	*init_data(int ac, char **av, char **envp)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (NULL);
	d->ac = ac;
	d->envp = envp;
	d->input_fd = 0;
	d->output_fd = 1;
	d->job = init_job(av);
	return (d);
}
