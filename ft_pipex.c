/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenaoui <mbenaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:59:05 by mbenaoui          #+#    #+#             */
/*   Updated: 2022/02/20 11:19:43 by mbenaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	creat_file(char *file, int n)
{
	if (n == 0)
	{
		if (access(file, F_OK) == 0)
			return (open(file, O_RDONLY, 000500));
		else
		{
			write(2, "pipex :", 7);
			write(2, " no such file or directory: ", 28);
			write(2, file, ft_stlen(file));
			return (1);
		}
	}
	else if (n == 1)
	{
		return (open(file, O_CREAT | O_RDWR | O_TRUNC, 0000644));
	}
	return (0);
}

char	*pathh(char *cmd, char **env)
{
	char	*cd;
	char	*tube;
	char	*ab;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	cd = env[i] + 5;
	while (cd && ft_strichr(cd, ':') > -1)
	{
		ab = ft_strndup(cd, ft_strichr(cd, ':'));
		tube = ft_strjoin(ab, cmd);
		free(ab);
		if (access(tube, F_OK) == 0)
			return (tube);
		free(tube);
		cd += ft_strichr(cd, ':') + 1;
	}
	return (cmd);
}

void	execc(char *cmd, char **env)
{
	char	**arg;
	char	*path;

	arg = ft_split(cmd, ' ');
	path = pathh(arg[0], env);
	execve(path, arg, env);
	write(2, "pipex: ", 7);
	write(2, ": command not found: ", 22);
	write(2, cmd, ft_strichr(cmd, '\0'));
	write(2, "\n", 1);
	exit (12);
}

void	redwrit(char *cmd, int fd, char **env)
{
	int	pid;
	int	pipefd[2];

	if (fd == 1)
		exit(1);
	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		execc(cmd, env);
	}
}

int	main(int ac, char **av, char **env)
{
	int	fd1;
	int	fd2;

	if (ac == 5)
	{
		fd1 = creat_file(av[1], 0);
		fd2 = creat_file(av[4], 1);
		dup2(fd1, 0);
		dup2(fd2, 1);
		redwrit(av[2], fd1, env);
		execc(av[3], env);
	}
	else
		write(2, "Invalid number of arguments.", 28);
	return (1);
}
