/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:07:38 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/29 19:23:19 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_bonus.h"

void	here_doc(char *argv, t_pipex pipex)
{
	int		file;
	char	*line;

	file = open(".heredoc_temp", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file == -1)
		ft_error_msg("Error opening here_doc!");
	while (1)
	{
		write(1, "heredoc< ", 9);
		if (get_next_line(0, &line) < 0)
			exit(1);
		if (!ft_strncmp(argv, line, ft_trlen(argv + 1)))
			break;
		write(file, line, ft_strlen(line));
		write(file, "\n", 1);
		free(line);
	}
	free(line);
	close(file);
	pipex->input = open(".heredoc_temp", O_RDONLY);
	if (pipex->input == -1)
	{
		unlink(".heredoc_temp");
		ft_error_msg("Error opening file");
	}
}
