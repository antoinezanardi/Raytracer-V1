/*
** shadow.c for shadow in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb  7 17:26:01 2015 Antoine Zanardi
** Last update Thu Mar  5 16:26:20 2015 Antoine Zanardi
*/

#include	<math.h>
#include	<stdlib.h>
#include	"rtv1.h"
#include	"my.h"

int		find_a_k(t_kist **list)
{
  t_kist	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->k >= 0.000001 && tmp->k <= 1.0)
	{
	  free(*list);
	  return (1);
	}
      tmp = tmp->next;
    }
  free(*list);
  return (0);
}

int		shadow_on(t_vec *dir, t_list **list, t_vec *pt, t_kist *k)
{
  t_list	*tmp;
  t_kist	*k_list;

  tmp = *list;
  k_list = NULL;
  while (tmp != NULL)
    {
      if (tmp != k->obj)
	{
	  if (my_strcmp("PLAN", tmp->forme, 0) == 0)
	    treat_plan(*dir, &k_list, tmp, *pt);
	  else if (my_strcmp("SPHERE", tmp->forme, 0) == 0)
	    treat_ball(*dir, &k_list, tmp, *pt);
	  else if (my_strcmp("CYLINDRE", tmp->forme, 0) == 0)
	    treat_cy(*dir, &k_list, tmp, *pt);
	  else if (my_strcmp("CONE", tmp->forme, 0) == 0)
	    treat_cone(*dir, &k_list, tmp, *pt);
	}
      tmp = tmp->next;
    }
  return (find_a_k(&k_list));
}
