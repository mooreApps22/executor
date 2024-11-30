#include "pipe_data.h"

int	open_heredoc(t_cmd *c) // char *current->eof
{
	int		fd;
	char	*buf;

	fd = open("tmp_heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	ft_putstr_fd("> ", 1);
	while ((buf = get_next_line(0)))
	{
		if (ft_strncmp(buf, c->eof, c->e_len) == 0 && buf[c->e_len] == '\n')
		{
			free(buf);
			break ;
		}
		ft_putstr_fd(buf, fd);
		free(buf);
		ft_putstr_fd("> ", 1);
	}
	close(fd);
	return (fd);
}

void	output_heredoc(int fd, int output_fd)
{
	char	*buf;

	fd = open("tmp_heredoc", O_RDONLY);
	if (fd < 0)
		return ;
	while ((buf = get_next_line(fd)))
	{
		ft_putstr_fd(buf, output_fd); // 1 will not always be the output_fd
		free(buf);
	}
	close(fd);
	unlink("tmp_heredoc");
}
