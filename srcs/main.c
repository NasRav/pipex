#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd[2];

	if (argc != 5)
	{
		ft_putendl_fd("Wrong number of arguments", 1);
		return (0);
	}
	exec_cmd(fd, argv, env);
	return (0);
}
