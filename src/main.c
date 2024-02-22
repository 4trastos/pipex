/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:34:14 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/22 10:02:48 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = NULL;
	if (argc == 1)
		ft_error_msg("These arguments are necessary!: < archivo1 comando1  comando2 > archivo2", NULL);
	else if (argc != 5)
		ft_error_msg("Invalid number of arguments!", NULL);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		ft_error_msg("Error opening file", NULL);
	pipex->outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
		ft_error_msg("Error opening file", NULL);
	return (0);
}
