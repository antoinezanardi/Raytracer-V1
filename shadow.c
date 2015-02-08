/*
** shadow.c for shadow in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb  7 17:26:01 2015 Antoine Zanardi
** Last update Sat Feb  7 19:54:31 2015 Antoine Zanardi
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
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

void		k_sphere(t_vec vec, t_kist **kist, t_list *ball, t_vec view)
{
  t_eq		eq;
  double	k;
  double	k2;
  double	delta;

  movement(&view, ball, &vec);
  eq.a = pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2);
  eq.b = 2.0 * (view.x * vec.x + view.y * vec.y + view.z * vec.z);
  eq.c = pow(view.x, 2.0) + pow(view.y, 2.0) + pow(view.z, 2.0) -
    pow((double)ball->ray, 2.0);
  delta = pow(eq.b, 2.0) - 4.0 * eq.a * eq.c;
  //  printf("x = %f\n y = %f\n z = %f\n", vec.x, vec.y, vec.z);
  if (delta > 0)
    {
      k = (-eq.b - sqrt(delta)) / (2.0 * eq.a);
      k2 = (-eq.b + sqrt(delta)) / (2.0 * eq.a);
      if (k <= k2 && k >= 0.0001)
	add_klist(kist, k, ball);
      else if (k2 >= 0.0001)
	add_klist(kist, k2, ball);
    }
}

void		k_plan(t_vec vec, t_kist **kist, t_list *plan, t_vec view)
{
  double	k;

  movement(&view, plan, &vec);
  if (vec.z <= -0.000001 || vec.z >= 0.000001)
    {
      k = -(view.z / vec.z);
      if (k >= 0.000001)
	add_klist(kist, k, plan);
    }
}

int		shadow_on(t_vec *dir, t_kist **list, t_light *light)
{
  t_vec		view;
  t_kist	*tmp;
  t_kist	*k_list;

  view.x = light->x;
  view.y = light->y;
  view.z = light->z;
  tmp = *list;
  k_list = NULL;
  while (tmp != NULL)
    {
      if (my_strcmp("SPHERE", tmp->obj->forme, 0) == 0)
	{
	  k_sphere(*dir, &k_list, tmp->obj, view);
	}
      else if (my_strcmp("PLAN", tmp->obj->forme, 0) == 0)
	{
	  k_plan(*dir, &k_list, tmp->obj, view);
	}
      else if (my_strcmp("CYLINDRE", tmp->obj->forme, 0) == 0)
	return (0);
      tmp = tmp->next;
    }
  return (find_a_k(&k_list));
}
