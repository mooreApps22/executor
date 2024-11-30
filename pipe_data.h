#ifndef PIPE_DATA_H
# define PIPE_DATA_H

#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include "libft/include/libft.h"

typedef struct s_data	t_data;
typedef struct s_cmd	t_cmd;

typedef struct s_data
{
	int		ac;
	char	**envp;
	int		input_fd;
	int		output_fd;
	int		pipefd[2];
	t_cmd	*job;	
}	t_data;

typedef struct s_cmd
{
	char	*av;
	char	*arg;
	char	*eof; // delimiter for heredoc
	int		e_len; // eof_len
	int		open_fd;
	int		append_fd;
	t_cmd	*next;
}	t_cmd;

void	free_job(t_cmd *job);

char	*check_null(char *av);
int		init_mem_int(char *av);
t_cmd	*init_cmd(char *av);
void	add_to_job(t_cmd **head_cmd, t_cmd *new_cmd);

t_cmd	*init_empty_cmd();
t_cmd	*init_job(char **av);
t_data	*init_data(int ac, char **av, char **envp);

void	printf_job(t_cmd *job);

void	redirect_input(int old_fd);
void	redirect_output(int old_fd);

pid_t	forker(t_data *d, t_cmd *current);
void	new_process(t_data *d, t_cmd *current);

int		open_heredoc(t_cmd *cur, int output_fd);
void	output_heredoc(int fd);

int		open_fd(char *arg);
int		append_fd(char *arg);

#endif

