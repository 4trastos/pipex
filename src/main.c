/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:34:14 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/21 20:56:33 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

int	main(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = NULL;
	(void)argv;
	if (argc == 1)
		ft_error_msg("These arguments are necessary: < archivo1 comando1  comando2 > archivo2!", NULL);
	else if (argc != 5)
		ft_error_msg("Invalid number of arguments!", NULL);
	else

	return (0);
}
