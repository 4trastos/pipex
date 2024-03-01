/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:56:50 by davgalle          #+#    #+#             */
/*   Updated: 2024/03/01 17:45:47 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

char	*get_command(char **path, char *arg)
{
	char	*aux;
	char	*exe;
	while (*path)
	{
		aux = ft_strjoindav(*path, "/");
		exe = ft_strjoindav(aux, arg);
		free(aux);
		if (access(exe, 0) == 0)
			return (exe);
		free(exe);
		path++;
	}
	return (NULL);
}

void	sub_dup2(int zero, int one)
{
	dup2(zero, 0);
	dup2(one, 1);
}

void	close_pipes(t_tipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_numb))
	{
		close(pipex->pipe[i]);
		i++;
	}
}

void	processes(t_tipex pipex, char **argv, char **envp)
{
	pipex.pid = fork();
	if (pipex.pid == 0)
	{
		if (pipex.idx == 0)
			sub_dup2(pipex.input, pipex.pipe[1]);
		else if (pipex.idx == pipex.commands_numb - 1)
			sub_dup2(pipex.pipe[2 * pipex.idx - 2], pipex.output);
		else
			sub_dup2(pipex.pipe[2 * pipex.idx - 2], pipex.pipe[2 * pipex.idx + 1]);
		close_pipes(&pipex);
		pipex.commands_arg = ft_split(argv[2 + pipex.here_doc + pipex.idx], ' ');
		pipex.command = get_command(pipex.commands_paths, pipex.commands_arg[0]);
		if (pipex.command == NULL)
		{
			free_pipex(&pipex);
			ft_error_msg("The command does not exist");
			exit(1);
		}
		execve(pipex.command, pipex.commands_arg, envp);
	}
}
