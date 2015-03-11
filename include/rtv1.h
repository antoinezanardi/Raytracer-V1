/*
** rtv1.h for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 11:03:03 2015 Antoine Zanardi
** Last update Wed Mar 11 09:25:54 2015 Antoine Zanardi
*/

#ifndef		RTV1_H_
# define	RTV1_H_

# define	HAUT		720
# define	LARG		1280
# define	BUFFER_SIZE	4096
# define	PI		3.14159265
# define	D_R(nb)		((3.14 * (double)nb) / 180.0)
# define	XB		(view.x - ball->x)
# define	YB		(view.y - ball->y)
# define	ZB		(view.z - ball->z)

typedef	struct	s_windows
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*data;
  int		bpp;
  int		line;
  int		endian;
}		t_windows;

typedef	struct	s_list
{
  double	x;
  double	y;
  double	z;
  double	ray;
  double	x_r;
  double	y_r;
  double	z_r;
  double	bri;
  char		*forme;
  char		*color;
  struct s_list	*next;
}		t_list;

typedef	struct	s_kist
{
  long double	k;
  unsigned char	red;
  unsigned char	green;
  unsigned char	blue;
  struct s_list	*obj;
  struct s_kist *next;
  struct s_kist	*prev;
}		t_kist;

typedef	struct	s_color
{
  unsigned char	red;
  unsigned char	green;
  unsigned char	blue;
}		t_color;

typedef	struct	s_vec
{
  double	x;
  double	y;
  double	z;
}		t_vec;

typedef	struct	s_eq
{
  double	a;
  double	b;
  double	c;
}		t_eq;

typedef	struct	s_light
{
  double	x;
  double	y;
  double	z;
  double	b_r;
  double	b_g;
  double	b_b;
}		t_light;

typedef	struct	s_fen
{
  int		x;
  int		y;
}		t_fen;

void		rotation_x(double *, double *, double);
void		rotation_y(double *, double *, double);
void		rotation_z(double *, double *, double);
void		treat(t_windows *, t_list **);
void		param_to_list(char *, t_list **);
void		coor_to_elem(char *, int *, t_list *, char);
void		color_to_elem(char *, int *, t_list *);
void		double_to_elem(char *, int *, t_list *);
void		my_show_list(t_list *);
void		str_is_low_nb(char *, int *);
void		str_is_num(char *, int *);
void		str_is_color(char *, int *);
void		correct_shape(char *, int *);
void		correct_plan(char *, int *);
void		correct_view(char *, int *);
void		pass_spaces(char *, int *);
void		parsing(char *, t_list **);
void		my_putstr_error(int, int);
void		treat_plan(t_vec, t_kist **, t_list *, t_vec);
void		treat_ball(t_vec, t_kist **, t_list *, t_vec);
void		treat_cy(t_vec, t_kist **, t_list *, t_vec);
void		treat_cone(t_vec, t_kist **, t_list *, t_vec);
void		movement(t_vec *, t_list *, t_vec *);
void		check_the_view(t_list **);
void		convert_view(t_list, t_vec *);
void		normalize(t_vec *);
void		calc_pt_inter(t_vec *, t_vec *, t_kist *, t_vec *);
void		calc_vec_dir(t_light *, t_vec *, t_vec *);
//void		init_the_light(t_light *);
void		translation(t_vec *, t_list *);
void		convert_my_color(t_kist *, char *);
void		correct_file(char *);
void		init_list(t_list **, int, char **);
void		init_my_mlx(t_windows *);
void		check_seuil(t_color *, t_color *);
void		calc_seuil(t_color *, t_color *);
char		*pick_nb(char *, int *);
char		*pick_decimal(char *, int);
int		my_expose(t_windows *);
int		escape_hook(int);
int		my_putstr_error2(int, int);
int		my_notice(void);
int		my_exemple(void);
int		view_to_list(char *, int *, t_list **);
int		plan_to_list(char *, int *, t_list **);
int		my_expose(t_windows *);
int		my_strcmp(char *, char *, int);
int		add_top_list(t_list **, int);
int		add_bot_list(t_list **, int);
int		form_to_list(char *, int *, t_list **);
int		correct_form(char *, int);
int		put_pix_picture(t_windows *, int, int, int);
int		add_klist(t_kist **, double, t_list *);
int		shadow_on(t_vec *, t_list **, t_vec *, t_kist *);
int		find_a_k(t_kist **);
int		count_decimal(char *, int);
unsigned int	get_my_color(unsigned char, unsigned char, unsigned char);
unsigned int	calc_pix(t_fen, t_list **, t_kist **, t_list);
unsigned int	light_my_color(t_kist *, t_vec, t_vec, t_list **);
unsigned int	brillance(t_kist *, double, t_light *);
double		my_get_double(char *, int);
t_list		make_my_view(t_list **);
t_vec		check_normal(t_kist *, t_vec);
t_vec		treat_vec(int, int, t_list);
t_vec		normal_cy(t_vec, t_kist *);
t_vec		normal_sphere(t_vec, t_kist *);
t_vec		normal_cone(t_vec, t_kist *);
t_vec		normal_plan(t_kist *);
t_kist		find_low_k(t_kist **);

#endif		/* !RTV1_H_ */
