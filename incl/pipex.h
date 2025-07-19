/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:07 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/29 19:44:59 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
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
# include <sys/wait.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		input;
	int		output;
	char	*paths;
	char	**commands_paths;
	char	**commands_arg;
	char	*command;			
}			t_pipex;

//** INIT **

int			main(int argc, char **argv, char **envp);

//** ERRORS **

void		ft_error_msg(char *msg);
void		process_free(t_pipex *pipex);
void		fork_free(t_pipex *pipex);

//** STRUCTURE FIELDS **

char		*ft_findpath(char **envp);
char		*get_command(char **paths, char *command_arg);
void		close_pipex(t_pipex *pipex);

//** AUXILIARS **

int			ft_strncmp(const char *src, const char *str, int numb);
char		*ft_strjoin(char *str1, char *str2);
int			ft_strlen(char *str);

//** SPLIT **

char		**ft_empty_split(void);
char		*ft_strdup_custom(const char *s, size_t n);
char		**ft_free_str(char **aux);
int			ft_countc(char const *s, char c);
char		**ft_split(char const *s, char c);

//** CHILDS **

void		process_one(t_pipex pipex, char **argv, char **envp);
void		process_two(t_pipex piepx, char **argv, char **envp);

#endif
