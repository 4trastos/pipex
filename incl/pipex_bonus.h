/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:43:29 by davgalle          #+#    #+#             */
/*   Updated: 2024/03/01 16:23:20 by davgalle         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_tipex
{
	pid_t	pid;
	int		idx;
	int		here_doc;
	int		input;
	int		output;
	int		commands_numb;
	int		pipe_numb;
	int		*pipe;
	char	*paths;
	char	**commands_paths;
	char	**commands_arg;
	char	*command;
}	t_tipex;

//** INIT ***

int		main(int argc, char **argv, char **envp);

//** ERRORS & CLOSING***

void	ft_error_msg(char *str);
void	close_pipex(t_tipex *pipex);
void	end_processes(t_tipex pipex);
void	free_pipex(t_tipex *pipex);

//** HERE_DOC ***

void	here_doc(char *argv, t_tipex *pipex);
void	get_input(t_tipex *pipex, char **argv);
void	get_output(t_tipex *pipex, char **argv, int argc);
int		check_args(t_tipex *pipex, char *argv);

//** CREATE PIPEX & PROCESS ***

char	*ft_findpaths(char **envp);
void	ft_createpipes(t_tipex *pipex);
void	processes(t_tipex, char **argv, char **envp);
char	*get_command(char **paths, char *arg);

//** AUXILIARS ***

int		ft_strncmp(char *str, char *dst, int numb);
char	*ft_strjoindav(char *one, char *two);

//** SPLIT ***

char	**ft_empty_split(void);
char	*ft_strdup_custom(const char *s, size_t n);
char	**ft_free_str(char **aux);
int		ft_countc(char const *s, char c);
char	**ft_split(char const *s, char c);

//** GET NEXT LINE ***

int			get_next_line(int fd, char *line);
size_t		ft_strlen(char *str);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *board, char *buffer);
char		*ft_strdup(char *s1);

#endif
