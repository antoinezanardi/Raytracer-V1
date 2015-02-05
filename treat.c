/*
** treat.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb  4 09:33:50 2015 Antoine Zanardi
** Last update Thu Feb  5 17:11:37 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"rtv1.h"
#include	"my.h"

t_vec		treat_vec(int x, int y)
{
  t_vec		vec;

  vec.x = 100.0;
  vec.y = (double)LARG / 2.0 - (double)x;
  vec.z = (double)HAUT / 2.0 - (double)y;
  return (vec);
}

unsigned int	calc_pix(t_fen fen, t_kist *k, t_list **obj)
{
  t_vec		vec;
  t_vec		view;
  t_kist	*k_list;
  t_list	*tmp;

  view.x = -300.0;
  view.y = 0.0;
  view.z = 40.0;
  tmp = *obj;
  k_list = NULL;
  vec = treat_vec(fen.x, fen.y);
  while (tmp != NULL)
    {
      if (my_strcmp("SPHERE", tmp->forme, 0) == 0)
      	treat_ball(vec, &k_list, tmp, view);
      else if (my_strcmp("PLAN", tmp->forme, 0) == 0)
	treat_plan(vec, &k_list, tmp, view);
      tmp = tmp->next;
    }
  if (k_list != NULL)
    return (find_low_k(&k_list, k, vec, view));
  else
    return (0);
}

void		treat(t_windows *win, t_list **obj)
{
  t_kist	k;
  t_fen		fen;
  int		color;

  fen.y = 0;
  while (fen.y < HAUT)
    {
      fen.x = 0;
      while (fen.x < LARG)
	{
	  color = calc_pix(fen, &k, obj);
	  put_pix_picture(win, fen.x, fen.y, color);
	  fen.x++;
	}
      fen.y++;
    }
}
