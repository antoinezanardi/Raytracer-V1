/*
** rtv1.h for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 11:03:03 2015 Antoine Zanardi
** Last update Wed Feb  4 17:27:01 2015 Antoine Zanardi
*/

#ifndef		RTV1_H_
# define	RTV1_H_

# define	HAUT		600
# define	LARG		800
# define	BUFFER_SIZE	4096

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
  int		x;
  int		y;
  int		z;
  int		ray;
  char		*forme;
  char		*color;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef	struct	s_kist
{
  double	k;
  unsigned char	red;
  unsigned char	green;
  unsigned char	blue;
  struct s_kist *next;
  struct s_kist	*prev;
}		t_kist;

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

typedef	struct	s_fen
{
  int		x;
  int		y;
}		t_fen;

char		*pick_nb(char *, int *);
unsigned int	get_my_color(unsigned char, unsigned char, unsigned char);
unsigned int	find_low_k(t_kist **, t_kist *);
unsigned int	calc_pix(t_fen, t_kist *, t_list **);
int		my_strcmp(char *, char *, int);
int		add_top_list(t_list **, int);
int		add_bot_list(t_list **, int);
int		form_to_list(char *, int *, t_list **);
int		correct_form(char *, int);
int		put_pix_picture(t_windows *, int, int, int);
int		add_klist(t_kist **, double, char *);
void		treat(t_windows *, t_list **);
void		param_to_list(char *, t_list **);
void		coor_to_elem(char *, int *, t_list *, char);
void		color_to_elem(char *, int *, t_list *);
void		my_show_list(t_list *);
void		str_is_num(char *, int *);
void		str_is_color(char *, int *);
void		correct_shape(char *, int *);
void		correct_plan(char *, int *);
void		correct_view(char *, int *);
void		pass_spaces(char *, int *);
void		parsing(char *, t_list **);
void		my_putstr_error(int, int);
void		treat_ball(t_vec, t_kist **, t_list *);
t_vec		treat_vec(int, int);

#endif		/* !RTV1_H_ */
