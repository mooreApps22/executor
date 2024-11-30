#include "pipe_data.h"

char	*check_null(char *av)
{
	if (ft_strncmp(av, "NULL", 4) == 0)
		return (NULL);
	return (ft_strdup(av));
}

int		init_mem_int(char *av)
{
	if (ft_strncmp(av, "NULL", 4) == 0)
		return (-1);
	return (ft_atoi(av));
}

t_cmd	*init_cmd(char *av)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
	{
		perror("malloc");
		return (NULL);
	}
	char **mems = ft_split(av, ' ');
	new_cmd->av = ft_strdup(mems[0]);
	new_cmd->arg = ft_strdup(mems[1]);
	new_cmd->eof = check_null(mems[2]);
	if (new_cmd->eof)
		new_cmd->e_len = ft_strlen(new_cmd->eof);
	new_cmd->open_fd = init_mem_int(mems[3]);
	new_cmd->append_fd = init_mem_int(mems[4]);
	new_cmd->next = NULL;
	ft_free_str_arr(mems);
	return (new_cmd);
}

void	add_to_job(t_cmd **head_cmd, t_cmd *new_cmd)
{
	t_cmd	*current;

	if (*head_cmd == NULL)
		*head_cmd = new_cmd;
	else
	{
		current = *head_cmd;
		while (current->next != NULL)
			current = current->next;
		current->next = new_cmd;
	}
}
