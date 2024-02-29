/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:07:19 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/29 18:20:22 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

void	ft_createpipes(t_pipex *pipex)
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

char	ft_findpaths(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < check_args(&pipex, argv[1]))
		ft_error_msg("Error inputs!");;
	get_input(&pipex, argv);
	get_output(&pipex, argv[argc -1]);
	pipex.commands_numb = argc - 3 - pipex.here_doc;
	pipex.pipe_numb = 2 * (pipex.commands_numb - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_numb);
	if (!pipex.pipe)
		return (NULL);
	pipex.paths = ft_findpaths(envp);
	pipex.commmands_paths = ft_split(pipex.paths, ':');
	if (!pipex.commsnds_paths)
		free_pipex(&pipex);
	ft_createpipes(&pipex);
	pipex.idx = -1;
	while (pipex.idx < pipex.commands_numb)
	{
		processes(pipex, argv, envp);
		pipex.idx++;
	}
	end_processes(pipex);
	return (0);
}
