/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:24:25 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/11/18 16:48:22 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
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

# define W_HEIGHT 800
# define W_WIDTH 1500

typedef struct s_data
{
	char			*north_img;
	char			*south_img;
	char			*west_img;
	char			*east_img;
	char			*f_line;
	char			*c_line;
	int				c_value;
	int				f_value;
	int				x_pos;
	int				y_pos;
}					t_data;

typedef struct s_cube
{
	char			**map;
	void			*mlx;
	void			*mlx_win;
	struct s_data	*data;
}					t_cube;

// PARSING

int					parsing(char **av, t_cube *cube);
int					get_map(char *str, t_cube *cube);
int					get_line_length(char *str, int i);
int					get_rgb(char *color);
void				get_data(t_cube *cube);
int					check_map(t_cube *cube);
int					check_walls(char **map);

// FLOODFILL

int					floodcall(char **map, t_data *data);

// DISPLAY

void				display(t_cube *cube);

// INIT

void				init_data(t_data *data);
void				init_cube(t_cube *cube, t_data *data);

// TOOLS

void				print_tab(char **tab);
void				ft_putstr_fd(char *str, int fd);
int					ft_strlen(char *str);
int					ft_tablen(char **tab);
int					ft_is_valid_number(const char *str);
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
int					first_char(char *str);
char				**copy_tab(char **tab);
int					valid_elements(char c);

// CLEANUP AND ERRORS

void				cleanup(t_cube *cube, int exit_code);
void				free_tab(char **tab);

#endif