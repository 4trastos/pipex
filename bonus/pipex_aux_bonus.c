/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:40:30 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/29 15:59:36 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin(char *one, char *two)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	new = (char *)malloc((ft_strlen(one) + ft_strlen(two)) + 1);
	if (!new)
		return (NULL);
	while (one[i] != '\0')
	{
		new[i] = one[i];
		i++;
	}
	j = 0;
	while (two[j] != '\0')
	{
		new[i] = two[j];
		j++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

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
