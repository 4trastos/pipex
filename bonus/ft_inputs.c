/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:31:07 by davgalle          #+#    #+#             */
/*   Updated: 2024/03/02 18:13:54 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

int	check_args(t_tipex *pipex, char *argv)
{
	if (argv && !ft_strncmp("here_doc", argv, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

void	get_input(t_tipex *pipex, char **argv)
{
	if (pipex->here_doc == 1)
		here_doc(argv[2], pipex);
	else
	{
		pipex->input = open(argv[1], O_RDONLY);
		if (pipex->input == -1)
			ft_error_msg("Error opening file");
	}
}

void	get_output(t_tipex *pipex, char **argv, int argc)
{
	if (pipex->here_doc == 1)
		pipex->output = open(argv[argc -1], O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		pipex->output = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->output == -1)
		ft_error_msg("Error opening file");
}
