/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:07:19 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/28 19:43:01 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

char	ft_findpaths(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 1)
		ft_error_msg("Arguments are necessary!");
	if (argc != 6)
		ft_error_msg("number of incorrect arguments!");
	pipex.input = open(argv[1], O_RDONLY);
	if (pipex.input == -1)
		ft_error_msg("Error opening first fd!");
	pipex.output = open(argv[argc -1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.output == -1)
		ft_error_msg("Error opening or creating second fd!");
	pipex.commands_numb = argc - 3;
	pipex.pipe_numb = 2 * (pipex.commands_numb - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_numb);
	if (!pipex.pipe)
		return (NULL);
	pipex.paths = ft_findpaths(envp);
	pipex.commmands_paths = ft_split(pipex.paths, ':');
	if (!pipex.commsnds_paths)
		free_pipex(&pipex);
	return (0);
}
