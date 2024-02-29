/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:44:05 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/29 19:25:06 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_pipex(t_pipex &pipex)
{
	int	i;

	i = 0;
	close(pipex->input);
	close(pipex->output);
	if (pipex.here_doc)
		unlink(".heredoc_temp");
	while (pipex->commands_paths[i])
	{
		free(pipex->commands_paths[i]);
		i++;
	}
	free(pipex->commands_paths);
	free(pipex->pipe);
}
