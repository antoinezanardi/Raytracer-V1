/*
** view.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb  6 15:56:00 2015 Antoine Zanardi
** Last update Sun Feb  8 16:35:29 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"rtv1.h"
#include	"my.h"

void		check_the_view(t_list **obj)
{
  int		bool;
  t_list	*tmp;

  tmp = *obj;
  bool = 0;
  while (tmp != NULL)
    {
      if (bool == 1 && my_strcmp("VIEW", tmp->forme, 0) == 0)
	 my_putstr_error(9, 0);
      else if (bool == 0 && my_strcmp("VIEW", tmp->forme, 0) == 0)
	bool = 1;
      tmp = tmp->next;
    }
  if (bool == 0)
    my_putstr_error(8, 0);
}

void		convert_view(t_list oeil, t_vec *view)
{
  view->x = (double)oeil.x;
  view->y = (double)oeil.y;
  view->z = (double)oeil.z;
}

t_list		make_my_view(t_list **obj)
{
  t_list	null;
  t_list	*tmp;

  tmp = *obj;
  while (tmp != NULL)
    {
      if (my_strcmp("VIEW", tmp->forme, 0) == 0)
	return (*tmp);
      tmp = tmp->next;
    }
  return (null);
}
