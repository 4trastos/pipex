/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:07 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/26 16:22:33 by davgalle         ###   ########.fr       */
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

typedef struct s_pipex
{
	pid_t	pid1;				// Almacena el PID del primer proceso creado.
	pid_t	pid2;				// Almacena el PID del segundo proceso creado.
	int		tube[2];			// Array para almacenar los descriptores de archivo del tubo (pipe).
	int		input;
	int		output;
	char	*paths;    			 //Array para almacenar los directorios de los comandos.	
	char	**commands_paths;	// Doble puntero de los comandos encontrados en el sistema.
	char	**commands_arg;		// Doble puntero de los comandos pasados como argumentos.
	char	*command;			// Comando que se va a ejecutar.
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