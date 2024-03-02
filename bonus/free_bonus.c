/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:44:05 by davgalle          #+#    #+#             */
/*   Updated: 2024/03/02 16:39:56 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

void	free_pipex(t_tipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->input);
	close(pipex->output);
	if (pipex->here_doc)
		unlink(".heredoc_temp");
	while (pipex->commands_paths[i])
	{
		free(pipex->commands_paths[i]);
		i++;
	}
	free(pipex->commands_paths);
	free(pipex->pipe);
}

void	pipe_free(t_tipex *pipex)
{
	close(pipex->input);
	close(pipex->output);
	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	free(pipex->pipe);
	ft_error_msg("Error!!");
	exit(1);
}

void	processes_free(t_tipex *pipex)
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
