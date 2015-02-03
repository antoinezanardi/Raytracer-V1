/*
** rtv1.h for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 11:03:03 2015 Antoine Zanardi
** Last update Tue Feb  3 18:14:25 2015 Antoine Zanardi
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

char		*pick_nb(char *, int *);
int		my_strcmp(char *, char *, int);
int		add_top_list(t_list **, int);
int		add_bot_list(t_list **, int);
int		form_to_list(char *, int *, t_list **);
int		correct_form(char *, int);
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

#endif		/* !RTV1_H_ */
