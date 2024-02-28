/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:43:29 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/28 19:43:07 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pit_t	pid2;
	int		tube[2];
	int		input;
	int		output;
	int		commands_numb;
	int		pipe_numb;
	int		*pipe;
	char	*paths;
	char	**commands_paths;
	char	**commands_arg;
	char	*command;
}	t_pipex;

//** INIT ***

int	main(int argc, char **argv, char **envp);

//** ERRORS ***

void	ft_error_msg(char *str);

//** COMPLETTE STRUCT //

char	*ft_findpaths(char **envp);

//** AUXILIARS ***

int		ft_strncmp(char *str, char *dst, int numb);
int		ft_strlen(char *str);

//** SPLIT ***

char		**ft_empty_split(void);
char		*ft_strdup_custom(const char *s, size_t n);
char		**ft_free_str(char **aux);
int			ft_countc(char const *s, char c);
char		**ft_split(char const *s, char c);
