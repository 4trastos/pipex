/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:07 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/21 20:54:37 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_pipex{
	char	*file1;
	char	*file2;
}			t_pipex;


//** INIT **

int	main(int argc, char **argv);

//** ERRORS **

void	ft_error_msg(char *msg, char **str);

#endif
