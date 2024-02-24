/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:27:35 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/24 14:01:23 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	process_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->input);
	close(pipex->output);
	while (pipex->commands_paths[i])
	{
		free(pipex->commands_paths[i]);
		i++;
	}
	free(pipex->commands_paths);
}

void	fork_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->commands_arg[i])
	{
		free(pipex->commands_arg[i]);
		i++;
	}
	free(pipex->commands_arg);
	free(pipex->command);
}
