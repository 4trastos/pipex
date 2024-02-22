/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:35:49 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/22 13:47:55 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex_h"

int	ft_strncmp(const char *src, const char *str, int numb)
{
	int	i;

	i = 0;
	while((src[i] != '\0' || str[i] != '\0') && i < numb)
	{
		if (src[i] != str[i])
			return ((const unsigned char)src[i] - (const unsigned char)str[i]);
		i++;
	}
	return (0);
}
