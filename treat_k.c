/*
** treat_k.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb  4 13:38:57 2015 Antoine Zanardi
** Last update Wed Feb  4 23:47:05 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"rtv1.h"
#include	"my.h"

void		convert_my_color(t_kist *elem, char *color)
{
  elem->red = 0;
  elem->green = 0;
  elem->blue = 0;
  if (my_strcmp("RED", color, 0) == 0)
    elem->red = 255;
  else if (my_strcmp("GREEN", color, 0) == 0)
    elem->green = 255;
  else if (my_strcmp("BLUE", color, 0) == 0)
    elem->blue = 255;
  else if (my_strcmp("WHITE", color, 0) == 0)
    {
      elem->red = 255;
      elem->green = 255;
      elem->blue = 255;
    }
  else if (my_strcmp("YELLOW", color, 0) == 0)
    {
      elem->red = 255;
      elem->green = 255;
    }
}

unsigned int	find_low_k(t_kist **list, t_kist *k_low)
{
  t_kist	*tmp;
  int		bool;

  tmp = *list;
  bool = 0;
  while (tmp != NULL)
    {
      if (bool == 1 && tmp->k < k_low->k)
	k_low = tmp;
      else if (tmp->k > 0.0 && bool == 0)
	{
	  k_low = tmp;
	  bool = 1;
	}
      tmp = tmp->next;
    }
  return (get_my_color(k_low->red, k_low->green, k_low->blue));
}

int		add_klist(t_kist **list, double k, char *color)
{
  t_kist	*elem;

  if ((elem = malloc(sizeof(t_kist))) == NULL)
    return (0);
  elem->k = k;
  convert_my_color(elem, color);
  elem->next = *list;
  elem->prev = NULL;
  if (*list != NULL)
    (*list)->prev = elem;
  *list = elem;
  return (0);
}
