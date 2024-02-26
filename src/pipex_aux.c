/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:35:49 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/26 18:02:55 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
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

int	ft_strncmp(const char *src, const char *str, int numb)
{
	int	i;

	i = 0;
	while ((src[i] != '\0' || str[i] != '\0') && i < numb)
	{
		if (src[i] != str[i])
			return ((const unsigned char)src[i] - (const unsigned char)str[i]);
		i++;
	}
	return (0);
}

char	*get_command(char **paths, char *command_arg)
{
	char	*aux;
	char	*exe;

	while (*paths)
	{
		aux = ft_strjoin(*paths, "/");
		exe = ft_strjoin(aux, command_arg);
		free(aux);
		if (access(exe, F_OK) == 0)
			return (exe);
		free(exe);
		paths++;
	}
	return (NULL);
}

void	process_one(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[1], 1);
	close(pipex.tube[0]);
	dup2(pipex.input, 0);
	pipex.commands_arg = ft_split(argv[2], ' ');
	pipex.command = get_command(pipex.commands_paths, pipex.commands_arg[0]);
	if (!pipex.command)
	{
		fork_free(&pipex);
		ft_error_msg("Commands not found");
		exit(1);
	}
	execve(pipex.command, pipex.commands_arg, envp);
}

void	process_two(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[0], 0);
	close(pipex.tube[1]);
	dup2(pipex.output, 1);
	pipex.commands_arg = ft_split(argv[3], ' ');
	pipex.command = get_command(pipex.commands_paths, pipex.commands_arg[0]);
	if (!pipex.command)
	{
		fork_free(&pipex);
		ft_error_msg("Commands not found");
		exit(1);
	}
	execve(pipex.command, pipex.commands_arg, envp);
}
