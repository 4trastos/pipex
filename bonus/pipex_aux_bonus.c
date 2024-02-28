/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:40:30 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/28 18:46:33 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_error_msg(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit(1);
}

int		ft_strncmp(char *str, char *dst, int numb)
{
	int	i;

	i = 0;
	while ((str[i] != '\0' || dst[i] != '\0') && i < numb)
	{
		if (str[i] != dst[i])
			return ((char *)str[i] - (char *)dst[i]);
		i++;
	}
	return (0);
}
