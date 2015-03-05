/*
** treat.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb  4 09:33:50 2015 Antoine Zanardi
** Last update Thu Mar  5 17:11:48 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"rtv1.h"
#include	"my.h"

t_vec		treat_vec(int x, int y, t_list oeil)
{
  t_vec		vec;

  vec.x = (double)LARG / 2.0;
  vec.y = (double)LARG / 2.0 - (double)x;
  vec.z = (double)HAUT / 2.0 - (double)y;
  rotation_x(&(vec.y), &(vec.z), D_R(oeil.x_r));
  rotation_y(&(vec.x), &(vec.z), D_R(oeil.y_r));
  rotation_z(&(vec.x), &(vec.y), D_R(oeil.z_r));
  return (vec);
}

unsigned int	calc_pix(t_fen fen, t_list **obj, t_kist **k_list, t_list oeil)
{
  t_kist	k;
  t_vec		vec;
  t_vec		view;
  t_list	*tmp;

  convert_view(oeil, &view);
  tmp = *obj;
  vec = treat_vec(fen.x, fen.y, oeil);
  while (tmp != NULL)
    {
      if (my_strcmp("SPHERE", tmp->forme, 0) == 0)
	treat_ball(vec, k_list, tmp, view);
      else if (my_strcmp("PLAN", tmp->forme, 0) == 0)
	treat_plan(vec, k_list, tmp, view);
      else if (my_strcmp("CYLINDRE", tmp->forme, 0) == 0)
	treat_cy(vec, k_list, tmp, view);
      else if (my_strcmp("CONE", tmp->forme, 0) == 0)
	treat_cone(vec, k_list, tmp, view);
      tmp = tmp->next;
    }
  if (*k_list == NULL)
      return (0);
  k = find_low_k(k_list);
  return (light_my_color(&k, vec, view, obj));
}

void		treat(t_windows *win, t_list **obj)
{
  t_kist	*k_list;
  t_fen		fen;
  t_list	view;
  int		color;

  fen.y = 0;
  view = make_my_view(obj);
  while (fen.y < HAUT)
    {
      fen.x = 0;
      while (fen.x < LARG)
	{
	  k_list = NULL;
	  color = (int)calc_pix(fen, obj, &k_list, view);
	  put_pix_picture(win, fen.x, fen.y, color);
	  fen.x++;
	  free(k_list);
	}
      my_expose(win);
      fen.y++;
    }
}
