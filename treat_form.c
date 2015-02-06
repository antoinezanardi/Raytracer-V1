/*
** treat_form.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb  4 10:01:49 2015 Antoine Zanardi
** Last update Fri Feb  6 14:15:50 2015 Antoine Zanardi
*/

#include	<math.h>
#include	"rtv1.h"
#include	"my.h"

void		treat_cy(t_vec vec, t_kist **kist, t_list *cy, t_vec view)
{
  t_eq		eq;
  double	k;
  double	k2;
  double	delta;

  movement(&view, cy, &vec);
  eq.a = pow(vec.x, 2) + pow(vec.y, 2);
  eq.b = 2.0 * (view.x * vec.x + view.y * vec.y);
  eq.c = pow(view.x, 2.0) + pow(view.y, 2.0) - pow((double)cy->ray, 2.0);
  delta = pow(eq.b, 2.0) - 4.0 * eq.a * eq.c;
  if (delta > 0)
    {
      k = (-eq.b - sqrt(delta)) / (2.0 * eq.a);
      k2 = (-eq.b + sqrt(delta)) / (2.0 * eq.a);
      if (k <= k2 && k >= 0.0001)
	add_klist(kist, k, cy);
      else if (k2 >= 0.0001)
	add_klist(kist, k2, cy);
    }
}

void		treat_plan(t_vec vec, t_kist **kist, t_list *plan, t_vec view)
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

void		treat_ball(t_vec vec, t_kist **kist, t_list *ball, t_vec view)
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
