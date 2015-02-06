/*
** treat.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb  4 09:33:50 2015 Antoine Zanardi
** Last update Fri Feb  6 16:13:35 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"rtv1.h"
#include	"my.h"

t_vec		treat_vec(int x, int y)
{
  t_vec		vec;

  vec.x = LARG / 2.0;
  vec.y = (double)LARG / 2.0 - (double)x;
  vec.z = (double)HAUT / 2.0 - (double)y;
  return (vec);
}

unsigned int	calc_pix(t_fen fen, t_list **obj, t_kist **k_list)
{
  t_kist	k;
  t_vec		vec;
  t_vec		view;
  t_list	*tmp;

  view.x = -800.0;
  view.y = 0.0;
  view.z = 40.0;
  tmp = *obj;
  vec = treat_vec(fen.x, fen.y);
  while (tmp != NULL)
    {
      if (my_strcmp("SPHERE", tmp->forme, 0) == 0)
      	treat_ball(vec, k_list, tmp, view);
      else if (my_strcmp("PLAN", tmp->forme, 0) == 0)
	treat_plan(vec, k_list, tmp, view);
      else if (my_strcmp("CYLINDRE", tmp->forme, 0) == 0)
	treat_cy(vec, k_list, tmp, view);
      tmp = tmp->next;
    }
  if (*k_list != NULL)
    return (find_low_k(k_list, &k, vec, view));
  else
    return (0);
}

void		treat(t_windows *win, t_list **obj)
{
  t_kist	*k_list;
  t_fen		fen;
  t_list	view;
  int		color;

  fen.y = 0;
  make_my_view(obj, &view);
  while (fen.y < HAUT)
    {
      fen.x = 0;
      while (fen.x < LARG)
	{
	  k_list = NULL;
	  color = calc_pix(fen, obj, &k_list);
	  put_pix_picture(win, fen.x, fen.y, color);
	  fen.x++;
	}
      my_expose(win);
      fen.y++;
    }
}
