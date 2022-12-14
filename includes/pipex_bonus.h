/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:18:06 by ewurstei          #+#    #+#             */
/*   Updated: 2022/11/11 15:05:41 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "../libft/includes/libft.h"

enum	e_pipe_ends_name
{
	p_read,
	p_write
};

typedef struct s_cmd
{
	char	*path;
	char	*name;
	char	**options;
}	t_cmd;

typedef struct s_vault
{
	char	*paths;
	char	**path_names;
	char	**argv;
	int		nbr_cmd;
	int		argc;
	char	**envp;
	pid_t	pid;
	int		child_id;
	int		status;
	int		fd_in;
	int		fd_out;
	t_cmd	cmd;
	int		error_flag;
	int		**pipe_ends;
	int		heredoc;
	char	*limiter;
	int		end_hd;
	char	*gnl_stash;
}	t_vault;

/***** GNL FILES *****/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd, t_vault *data);
char	*ft_clean(char *string);
char	*ft_linetoprint(char *string);
char	*ft_search(char *string, char c);
size_t	ft_lenght(char *string);
char	*ft_join(char *stash, char *buffer);

/***** Initialisation *****/
void	launch_pipex(t_vault *data, char **argv, int argc, char **envp);
void	find_paths(t_vault *data);
void	find_prog(t_vault *data, int y);
void	cmd_path_check(t_vault *data);

/***** Logique *****/
void	piping(t_vault *data);
void	forking(t_vault *data);
int		dup_fds(t_vault *data, int y);
void	check_fd_in(t_vault *data);
void	check_fd_out(t_vault *data);
int		check_cmd(t_vault *data);
void	exit_on_error(t_vault *data, int error_code);
int		message(t_vault *data, char *str1, char *str2, int error_code);

/***** Exiting *****/
void	close_pipe_ends(t_vault *data);

/***** POUR DEBUG *****/
void	check_paths(t_vault *data);
void	check_options(t_vault *data);
void	check_argv(t_vault *data);

/***** SPECIFIC BONUS *****/
void	detect_heredoc(t_vault *data);

#endif