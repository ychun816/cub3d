/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:24:25 by ahadj-ar          #+#    #+#             */
/*   Updated: 2025/02/10 17:47:54 by yilin            ###   ########.fr       */
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
# include <math.h>
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

# define W_HEIGHT 720
# define W_WIDTH 1280

# define X_HEIGHT 64
# define X_WIDTH 64

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define MOVE_SPEED 0.1
# define ROTATE_SPEED 0.1

//// MINIMAP ////
# define MINIMAP_SIZE 100 // The max width/height of the minimap in pixels

//handle size,scale,x and y pos 
typedef struct s_minimap
{
	//If the map is larger, scale becomes smaller (each tile shrinks). If the map is small, scale remains large.
	double	scale;//The size of each map tile in pixels on the minimap.// Scale factor (1 map unit = X pixels)
	int	width;//in pixels
	int	height;//in pixels
	int	offset_y;
	int	offset_x;
}	t_minimap;

//init
int		minimap(t_cube *cube);
void	init_minimap_struct(t_minimap *map);

//put color, texture
void	set_minimap_content(t_data *data);
void	put_minimap_pixel(t_data *data, int map_x, int map_y, int color);//fill pixel for each unit
void	put_minimap_bg();//or border

//player pos
int	set_player_minimap();
int set_player_fov(x, y, );
//////////////////


enum		e_orientation
{
	NORTH,
	EAST,
	WEST,
	SOUTH,
};

typedef struct s_vec
{
	double	x;
	double	y;
	int		direction;
	//double dir_x? //Directional X component (for ray direction or movement)
	//double dir_y? //Directional Y component (for ray direction or movement)
}			t_vec;

typedef struct s_map
{
	int		x;
	int		y;
}			t_map;

typedef struct s_data
{
	char	*no_img;
	char	*so_img;
	char	*we_img;
	char	*ea_img;
	char	*f_line;
	char	*c_line;
	int		xpm_height;
	int		xpm_width;
	t_vec	p_pos;
	t_vec	p_dir;
	t_vec	cam_plane;
	t_vec	ray_dir;
	t_map	map;//t_map	*map;?? //added
	t_img	img;
	t_minimap *minimap;//add to link minimap
}			t_data;

typedef struct s_img
{
	int		*textures;
	void	*img;
	void	*wall;
	char	*addr;
	int		*north;
	int		*south;
	int		*west;
	int		*east;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_cube
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*no_xpm;
	void	*we_xpm;
	void	*so_xpm;
	void	*ea_xpm;
	int		c_value;
	int		f_value;
	t_img	*img;
	t_data	*data;
}			t_cube;

typedef struct s_cast
{
	int		x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		textnum;
	int		text_x;
	int		text_y;
	double	wall_x;
	double	step;
	double	text_pos;
}			t_cast;

// PARSING

int			parsing(char **av, t_cube *cube);
int			get_map(char *str, t_cube *cube);
int			get_line_length(char *str, int i);
int			get_rgb(char *color);
void		get_data(t_cube *cube);
int			check_map(t_cube *cube);
int			check_walls(char **map);

// FLOODFILL

int			floodcall(char **map, t_data *data);

// DISPLAY

int			display(t_cube *cube);
int			input(int keysim, t_cube *cube);
void		walls(t_cube *cube, t_cast *cast, double ray_len);
void		ft_pixel_put(t_img *pixel, int x, int y, int color);
int			set_minimap(t_cube *cube);

// MOVEMENTS
void		rotate_left(t_data *data);
void		rotate_right(t_data *data);
void		move_forward(t_cube *cube, t_data *data);
void		move_backward(t_cube *cube, t_data *data);
void		move_left(t_cube *cube, t_data *data);
void		move_right(t_cube *cube, t_data *data);

// INIT

void		init_struct(t_cube *cube, t_data *data, t_img *img);
void		init_mlx(t_cube *cube);

// TOOLS

void		print_tab(char **tab);
void		ft_putstr_fd(char *str, int fd);
int			ft_strlen(char *str);
int			ft_tablen(char **tab);
int			ft_is_valid_number(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(char *str);
char		*ft_strndup(const char *s, int n);
char		*ft_strndup_start(const char *s, int n);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_strtrim(char *str, char c);
void		ft_strrtrim(char *str, char c);
int			ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
int			first_char(char *str);
char		**copy_tab(char **tab);
int			valid_elements(char c);

// CLEANUP AND ERRORS

int			cleanup(t_cube *cube, int exit_code);
void		free_tab(char **tab);

#endif
