/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:07 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/22 14:10:02 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

typedef struct s_pipex{
	int		tube[2];
	int		input;
	int		output;
	char	*path;
	char	**commands;
}			t_pipex;


//** INIT **

int	main(int argc, char **argv, char **envp);

//** ERRORS **

void	ft_error_msg(char *msg, char **str);

//** GET NEXT LINE **

char		*get_next_line(int fd);
size_t		ft_strlen(char *str);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *board, char *buffer);
char		*ft_strdup(char *s1);
char		*ft_new_line(char *board);
char		*ft_line(char *board);
char		*ft_read(int fd, char *board);

//** STRUCTURE FIELDS **

char		*ft_findpath(char **envp);

//** AUXILIARS **

int			ft_strncmp(const char *src, char *str, int numb);

//** SPLIT **

char		**ft_empty_split(void);
char		*ft_strdup_custom(const char *s, size_t n);
char		**ft_free_str(char **aux);
int			ft_countc(char const *s, char c);
char		**ft_split(char const *s, char c);

#endif
