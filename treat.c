/*
** treat.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb  4 09:33:50 2015 Antoine Zanardi
** Last update Wed Feb  4 17:28:02 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"rtv1.h"
#include	"my.h"

t_vec		treat_vec(int x, int y)
{
  t_vec		vec;

  vec.x = 100;
  vec.y = (double)LARG / (double)2 - (double)x;
  vec.z = (double)HAUT / (double)2 - (double)y;
  return (vec);
}

unsigned int	calc_pix(t_fen fen, t_kist *k, t_list **obj)
{
  t_vec		vec;
  t_kist	*k_list;
  t_list	*tmp;

  tmp = *obj;
  k_list = NULL;
  vec = treat_vec(fen.x, fen.y);
  while (tmp != NULL)
    {
      if (my_strcmp("SPHERE", tmp->forme, 0) == 0)
	treat_ball(vec, &k_list, tmp);
      tmp = tmp->next;
    }
  if (k_list != NULL)
    return (find_low_k(&k_list, k));
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
