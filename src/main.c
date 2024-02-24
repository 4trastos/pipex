/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:34:14 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/24 13:56:19 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	close_pipex(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

void	ft_error_msg(char *msg, char **str)
{
	int	i;

	i = 0;
	if (str)
		free(str);
	while(msg[i]  != '\0')
	{
		write(1, &msg[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	*ft_findpath(char **envp)
{
	while(ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 1)
		ft_error_msg("These arguments are necessary!: < archivo1 comando1  comando2 > archivo2", NULL);
	else if (argc != 5)
		ft_error_msg("Invalid number of arguments!", NULL);
	pipex.input = open(argv[1], O_RDONLY);
	if (pipex.input == -1)
		ft_error_msg("Error opening file", NULL);
	pipex.output = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.output == -1)
		ft_error_msg("Error opening file", NULL);
	if (pipe(pipex.tube) == -1)
		ft_error_msg("Could not create pipe", NULL);
	pipex.paths = ft_findpath(envp);
	pipex.commands_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		child_one(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid1 == 0)
		child_two(pipex, argv, envp);
	close_pipex(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	process_free(&pipex);
	return (0);
}
