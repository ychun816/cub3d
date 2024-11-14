/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:24:25 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/14 15:01:04 by ahadj-ar         ###   ########.fr       */
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

typedef struct s_data
{
	char			*north_img;
	char			*south_img;
	char			*west_img;
	char			*east_img;
	char			*f_color;
	char			*c_color;
	int				c_value;
	int				f_value;
}					t_data;

typedef struct s_cube
{
	char			**map;
	struct s_data	*data;
}					t_cube;

// PARSING

int					parsing(char **av, t_cube *cube);
int					get_map(char *str, t_cube *cube);
int					get_line_length(char *str, int i);
int					get_rgb(char *color);
int					get_data(t_cube *cube);

// INIT

void				init_data(t_data *data);

// TOOLS

void				print_tab(char **tab);
int					ft_strlen(char *str);
int					ft_tablen(char **tab);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(char *str);
char				*ft_strndup(const char *s, int n);
char				*ft_strndup_start(const char *s, int n);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strtrim(char *str, char c);
void				ft_strrtrim(char *str, char c);
int					ft_atoi(const char *str);
char				**ft_split(char const *s, char c);

// CLEANUP AND ERRORS

void				cleanup(t_cube *cube);
void				free_tab(char **tab);

#endif