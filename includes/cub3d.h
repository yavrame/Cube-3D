/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:14:43 by pharmund          #+#    #+#             */
/*   Updated: 2022/10/13 17:14:48 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define GAME_NAME		"|--cub3D--|"
# define WIN_WIDTH		900
# define WIN_HEIGHT		610

# define PI	3.1415926535
# define WALL_SIZE		64
# define PLAYER_SIZE	32
# define FOV			60
# define MOVE_SPEED		2.0

# define NO				0
# define WE				1
# define SO				2
# define EA				3

/*KEYS*/
# ifdef LINUX_KEYS
#  define ESC	6537
#  define W		119
#  define A		97
#  define S		115
#  define D		100
#  define LEFT	65361
#  define RIGHT	65363
#  define PLUS	65451
#  define MIN	65453
# endif
# ifdef DARWIN_KEYS
#  define ESC	53
#  define W		13
#  define A		0
#  define S		1
#  define D		2
#  define LEFT	123
#  define RIGHT	124
#  define PLUS	24
#  define MIN	27
# endif

/*COLORS*/
# define RED	"\033[0;31m"
# define YELLOW	"\033[0;33m"
# define BREAK	"\033[0m"

# define BLUE_INT	1048575
# define PURPLE_INT	3093151
# define YELLOW_INT	15580928
# define GREY_INT	8295071

typedef struct s_values
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
}			t_values;

typedef struct s_keys
{
	int	esc;
	int	q;
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	down;
	int	up;
}		t_keys;

typedef struct s_move {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed_val;
	double	rot_speed_val;
	double	move_speed;
	double	rot_speed;
	double	camera_x;
	double	camera_y;
	double	intersect_dist_x;
	double	intersect_dist_y;
	int		map_x;
	int		map_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	perp_wall_dist;
	int		is_wall;
	int		side;
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		texture_num;
	int		tex_pos_x;
}			t_move;

typedef struct s_texture
{
	void	*img;
	int		w;
	int		h;
	int		bpp;
	int		endian;
	int		size_line;
	int		*addr;
}			t_texture;

typedef struct s_element {
	void	*north_txtr;
	void	*south_txtr;
	void	*west_txtr;
	void	*east_txtr;
	void	*floor_clr;
	void	*ceiling_clr;
}			t_element;

typedef struct s_map {
	char			**game_map;
	int				txtr_arr[4][WALL_SIZE * WALL_SIZE];
	int				height;
	int				width;
	int				player_x;
	int				player_y;
	int				player_dir;
	int				min;
	unsigned int	floor;
	unsigned int	ceiling;
}					t_map;

typedef struct s_data {
	void		*mlx_img;
	void		*mlx_win;
	void		*mlx;
	int			bpp;
	int			size_line;
	int			endian;
	char		*addr;
	t_values	vals;
	t_keys		keys;
	t_move		move;
	t_element	*elems;
	t_map		*map;
	t_texture	*txtrs;
}				t_data;

/*mlx.c*/
void			ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_mlx(t_data *data);

/*utils.c*/
size_t			ft_strlen_nl(char *str);
void			ft_init_data(t_data *data);
void			ft_exit_error(char *error);
void			ft_game_msg(char *msg);

// delete!!!
void			ft_printf_split(char **str);

/*clear.c*/
int				ft_free_exit(t_data *data);
int				ft_free_exit_msg(t_data *data, char *error);
void			ft_free_all(t_data *data);
void			ft_free_elems(t_data *data);

/*parsing.c*/
void			ft_parse_file(t_data *data, char *file);

/*parse_identifiers.c*/
int				ft_get_identifier(t_element *elem, char *line);
int				ft_check_identifiers(t_element *elem);

/*parse_colors.c*/
int				ft_set_color(char ***texture, const char *id, char *line);
int				ft_validate_color(char *color);
unsigned int	ft_convert_color(char *rgb);

/*parse_map.c*/
int				ft_parse_map(t_data *data, char *line, int fd, char *file);
char			**ft_map_cpy(int height, char **map);

/*check_map.c*/
int				ft_check_map(t_map *map);

/*render.c*/
int				ft_render(t_data *data);
void			ft_mlx_loop(t_data *data);

/*keys.c*/
int				ft_key_down(int key_code, t_data *data);
int				ft_key_up(int key_code, t_data *data);
int				ft_key_hooks(t_data *data);

/*draw.c*/
int				ft_key(int key, t_data *data);
void			ft_start_draw(t_data *data);
void			ft_draw_floor_ceiling(t_data *data);

/*draw_elements.c*/
void			ft_draw_bg_ceiling(t_data *data);
void			ft_draw_ray(t_data *data, t_move *mv, int x);

/*textures.c*/
int				ft_set_textures(t_data *data, t_texture *t);

/*move.c*/
void			ft_move_up(t_data *data, t_move *mv);
void			ft_move_down(t_data *data, t_move *mv);
void			ft_move_right(t_data *data, t_move *mv);
void			ft_move_left(t_data *data, t_move *mv);

/*rotate.c*/
void			ft_rotate_left(t_data *data, t_move *mv);
void			ft_rotate_right(t_data *data, t_move *mv);

/*raycasting.c*/
void			ft_calc_ray_pos_dir(t_move *mv, int x);
void			ft_calc_intersection_dist(t_move *mv);
void			ft_calc_step_first_intersect(t_move *mv);
void			ft_dda(t_move *mv, char **map);
void			ft_calc_wall_dist_and_ray_height(t_move *mv);

/*minimap.c*/
void			ft_draw_minimap(t_data *data);
void			ft_minimap_init(t_data *data);

#endif
