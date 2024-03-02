/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:07:19 by davgalle          #+#    #+#             */
/*   Updated: 2024/03/02 14:40:10 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

void	end_processes(t_tipex pipex)
{
	close_pipex(&pipex);
	waitpid(-1, NULL, 0);
	free_pipex(&pipex);
}

void	close_pipex(t_tipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_numb))
	{
		close(pipex->pipe[i]);
		i++;
	}
}

void	ft_createpipes(t_tipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->commands_numb - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			free_pipex(pipex);
		i++;
	}
}

char	*ft_findpaths(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_tipex	pipex;

	if (argc < check_args(&pipex, argv[1]))
		ft_error_msg("Error inputs!");
	get_input(&pipex, argv);
	get_output(&pipex, argv, argc);
	pipex.commands_numb = argc - 3 - pipex.here_doc;
	pipex.pipe_numb = 2 * (pipex.commands_numb - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_numb);
	if (!pipex.pipe)
		return (0);
	pipex.paths = ft_findpaths(envp);
	pipex.commands_paths = ft_split(pipex.paths, ':');
	if (!pipex.commands_paths)
		pipe_free(&pipex);
	ft_createpipes(&pipex);
	pipex.idx = 0;
	while (pipex.idx < pipex.commands_numb)
	{
		processes(pipex, argv, envp);
		pipex.idx++;
	}
	end_processes(pipex);
	return (0);
}
