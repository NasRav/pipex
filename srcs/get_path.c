#include "pipex.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}

static char	*get_path_from_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i]);
		++i;
	}
	return (0);
}

void	get_path(char *cmd, char **env, char **f_path)
{
	char	**path_arr;
	char	*path;
	char	*path_cmd;
	int		i;
	int		fd;

	i = 0;
	path_arr = ft_split(ft_strchr(get_path_from_env(env), '/'), ':');
	while (path_arr[i])
	{
		path = ft_strjoin(path_arr[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		free(path);
		fd = open(path_cmd, O_RDONLY);
		if (fd >= 0)
		{
			*f_path = path_cmd;
			free_array(path_arr);
			close(fd);
			return ;
		}
		free(path_cmd);
		i++;
	}
	free_array(path_arr);
}
