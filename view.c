/*
** view.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Feb  6 15:56:00 2015 Antoine Zanardi
** Last update Fri Feb  6 16:10:29 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"rtv1.h"
#include	"my.h"

void		check_the_view(t_list **obj)
{
  t_list	*tmp;

  tmp = *obj;
  while (tmp != NULL)
    {
      if (my_strcmp("VIEW", tmp->forme, 0) == 0)
	return;
      tmp = tmp->next;
    }
  my_putstr_error(8, 0);
}

void		make_my_view(t_list **obj, t_list *view)
{
  //  check_the_view(obj, view);
}
