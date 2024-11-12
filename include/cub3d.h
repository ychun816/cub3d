/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:24:25 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/12 16:14:11 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <linux/limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_cube
{
	char	**map;
}			t_cube;

// PARSING

int			parsing(char **av, t_cube *cube);
int			get_map(char *str, t_cube *cube);
int			get_line_length(char *str, int i);

// TOOLS
int			ft_strlen(char *str);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(char *str);
char		*ft_strndup(const char *s, int n);
char		*ft_strjoin(char *s1, char *s2);

// CLEANUP AND ERRORS
void		cleanup(t_cube *cube);
void		free_tab(char **tab);
#endif