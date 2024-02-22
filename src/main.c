/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:34:14 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/22 14:14:23 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

char	*ft_findpath(char **envp)
{
	while(ft_strncpm("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = NULL;
	if (argc == 1)
		ft_error_msg("These arguments are necessary!: < archivo1 comando1  comando2 > archivo2", NULL);
	else if (argc != 5)
		ft_error_msg("Invalid number of arguments!", NULL);
	pipex->input = open(argv[1], O_RDONLY);
	if (pipex->input == -1)
		ft_error_msg("Error opening file", NULL);
	pipex->output = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->output == -1)
		ft_error_msg("Error opening file", NULL);
	if (pipe(pipex->tube) == -1)
		ft_error_msg("Could not create pipe", NULL);
	pipex->path = ft_findpath(envp);
	pipex->commands = ft_split(pipex->path, ':');
	return (0);
}
