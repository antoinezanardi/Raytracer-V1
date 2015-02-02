/*
** rtv1.h for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 11:03:03 2015 Antoine Zanardi
** Last update Mon Feb  2 17:56:32 2015 Antoine Zanardi
*/

#ifndef		RTV1_H_
# define	RTV1_H_

# define	HAUT		600
# define	LARG		800
# define	BUFFER_SIZE	240000

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

int		my_strcmp(char *, char *, int);
void		str_is_num(char *, int *);
void		str_is_color(char *, int *);
void		correct_shape(char *, int *);
void		pass_spaces(char *, int *);
void		parsing(char *);
void		my_putstr_error(int, int);

#endif		/* !RTV1_H_ */
