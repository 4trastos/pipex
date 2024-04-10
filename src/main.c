/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:34:14 by davgalle          #+#    #+#             */
/*   Updated: 2024/02/28 18:27:34 by davgalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	end_processes(t_pipex pipex)
{
	close_pipex(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	process_free(&pipex);
}

void	close_pipex(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

void	ft_error_msg(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(1);
}

char	*ft_findpath(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (*envp == NULL)
		ft_error_msg("Error: Missing environment variables");
	if (argc == 1)
		ft_error_msg("arguments are necessary!");
	if (argc != 5)
		ft_error_msg("Invalid number of arguments!");
	pipex.input = open(argv[1], O_RDONLY);
	if (pipex.input == -1)
		ft_error_msg("Error opening file");
	pipex.output = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.output == -1)
		ft_error_msg("Error opening file");
	if (pipe(pipex.tube) < 0)
		ft_error_msg("Could not create pipe");
	pipex.paths = ft_findpath(envp);
	pipex.commands_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		process_one(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		process_two(pipex, argv, envp);
	end_processes(pipex);
	return (0);
}
