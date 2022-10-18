/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:17:51 by ewurstei          #+#    #+#             */
/*   Updated: 2022/10/06 20:17:51 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd(t_vault *data)
{
	if (ft_strchr(data->cmd.options[0], '/') != NULL)
		return (1);
	return (0);
}

int	message(char *str1, char *str2, char *str3, int error_code)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putendl_fd(str3, 2);
	return (error_code);
}

int	check_error(void)
{
	if (errno != 0)
		perror("Error");
	return (errno);
}

void	check_fd_in(t_vault *data)
{
	char	*line;

	data->fd_in = open(data->argv[1], O_RDONLY);
	if (data->fd_in == -1)
		message("fd error", "", "", 0);
	line = get_next_line(data->fd_in);
	if (!line)
		message("fd empty", "", "", 0);
	free(line);
	close(data->fd_in);
	data->fd_in = open(data->argv[1], O_RDONLY);
}

void	check_fd_out(t_vault *data)
{
	data->fd_out = open(data->argv[data->argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!data->fd_out)
		message("fd error", "", "", 0);
}
/***** POUR DEBUG ****
void	check_paths(t_vault *data)
{
	size_t	x;

	x = 0;
	while (data->path_names[x])
	{
		fprintf(stderr, "Path_name #%zu : %s\n", x, data->path_names[x]);
		x++;
	}
	return ;
}

void	check_options(t_vault *data)
{
	size_t	x;

	x = 0;
	while (data->cmd.options[x])
	{
		fprintf(stderr, "Options #%zu : %s\n", x, data->cmd.options[x]);
		x++;
	}
	return ;
}

void	check_argv(t_vault *data)
{
	size_t	x;

	x = 0;
	while (data->argv[x])
	{
		fprintf(stderr, "Args #%zu : %s\n", x, data->argv[x]);
		x++;
	}
	return ;
}
*/

