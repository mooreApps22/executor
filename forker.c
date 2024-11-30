#include "pipe_data.h"

void	execute_process(t_data *d, t_cmd *current)
{
	char	**cmdv;

	cmdv = malloc(sizeof(char *) * 3);
	cmdv[0] = current->av;
	cmdv[1] = current->arg;
	cmdv[2] = NULL;
	if (execve(cmdv[0], cmdv, d->envp) == -1)
	{
		perror("execve");
		exit(1);
	}
	ft_free_str_arr(cmdv);
}

pid_t	forker(t_data *d, t_cmd *current)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		redirect_input(d->input_fd);
		redirect_output(d->output_fd);
		execute_process(d, current);
	}
	return (pid);
}

void	new_process(t_data *d, t_cmd *current)
{
	pid_t	pid;

	pid = forker(d, current);
	waitpid(pid, NULL, 0); // works without this, but seems safer
}
