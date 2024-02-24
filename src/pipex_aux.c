/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:35:49 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/24 13:56:44 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

char	*ft_strjoin(char *str1, char *str2)
{
	int 	i;
	int		j;
	char	*new;

	i = 0;
	new = malloc((ft_strlen(str1) + ft_strlen(str2)) + 1);
	if (!new)
		return (NULL);
	while (str1[i] != '\0')
	{
		new[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != '\0')
	{
		new[i] = str2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_command(char **paths, char *com_arg)
{
	char	*aux;
	char	*command;

	while (*paths)
	{
		aux = ft_strjoin(*paths, "/");
		command = ft_strjoin(aux, com_arg);
		free(aux);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

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

void	child_one(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[1], 1);
	close(pipex.tube[0]);
	dup2(pipex.input, 0);
	pipex.commands_paths = ft_split(argv[2], ' ');
	pipex.command = get_command(pipex.commands_paths, pipex.commands_arg[0]);
	if (!pipex.command)
	{
		fork_free(&pipex);
		ft_error_msg("Commands not found", NULL);
		exit(1);
	}
	execve(*pipex.commands_paths, pipex.commands_arg, envp);
}

void	child_two(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[0], 0);
	close(pipex.tube[1]);
	dup2(pipex.output, 1);
	pipex.commands_arg = ft_split(argv[3], ' ');
	pipex.command = get_command(pipex.commands_paths, pipex.commands_arg[0]);
	if (!pipex.command)
	{
		fork_free(&pipex);
		ft_error_msg("Commands not found", NULL);
		exit(1);
	}
	execve(*pipex.commands_paths, pipex.commands_arg, envp);
}
