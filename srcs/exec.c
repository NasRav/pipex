#include "pipex.h"

static void	cmd1(int *fd, char **argv, char **env)
{
	int		fd1;
	char	*path;
	char	**cmd_arr;

	close(fd[0]);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		perror(argv[1]);
		exit(0);
	}
	dup2(fd1, 0);
	close(fd1);
	dup2(fd[1], 1);
	close(fd[1]);
	cmd_arr = ft_split(argv[2], ' ');
	get_path(cmd_arr[0], env, &path);
	if (execve(path, cmd_arr, env) == -1)
	{
		perror(argv[2]);
		free_array(cmd_arr);
		free(path);
		exit(0);
	}
}

static	void	cmd2(int *fd, char **argv, char **env)
{
	int		fd2;
	char	*path;
	char	**cmd_arr;

	close(fd[1]);
	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd2 == -1)
	{
		perror(argv[4]);
		exit(0);
	}
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(fd2, 1);
	cmd_arr = ft_split(argv[3], ' ');
	get_path(cmd_arr[0], env, &path);
	if (execve(path, cmd_arr, env) == -1)
	{
		perror(argv[3]);
		free_array(cmd_arr);
		free(path);
		exit(0);
	}
}

void	exec_cmd(int *fd, char **argv, char **env)
{
	int	pid;
	int	status;

	pipe(fd);
	status = 0;
	pid = fork();
	if (pid == -1)
		perror("Fork");
	if (pid == 0)
		cmd1(fd, argv, env);
	else
	{
		pid = fork();
		if (pid == -1)
			perror("Fork");
		if (pid == 0)
			cmd2(fd, argv, env);
		else
		{
			close(fd[0]);
			close(fd[1]);
		}
	}
	waitpid(pid, &status, 0);
}
