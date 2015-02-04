/*
** treat_form.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb  4 10:01:49 2015 Antoine Zanardi
** Last update Wed Feb  4 21:42:28 2015 Antoine Zanardi
*/

#include	<math.h>
#include	"rtv1.h"
#include	"my.h"

void		treat_plan(t_vec vec, t_kist **kist, t_list *plan, t_vec view)
{
  double	k;

  if (vec.z == 0.0000001)
    add_klist(kist, 0.0, plan->color);
  else
    {
      k = -((view.z - (double)plan->z) / vec.z);
      if (k >= 0)
	add_klist(kist, k, plan->color);
    }
}

void		treat_ball(t_vec vec, t_kist **kist, t_list *ball, t_vec view)
{
  t_eq		eq;
  double	k;
  double	k2;
  double	delta;

  eq.a = pow(vec.x, 2.0) + pow(vec.y, 2.0) + pow(vec.z, 2.0);
  eq.b = 2.0 * (XB * vec.x + YB * vec.y + ZB * vec.z);
  eq.c = pow(XB, 2.0) + pow(YB, 2.0) + pow(ZB, 2.0) -
    pow(ball->ray, 2.0);
  delta = pow(eq.b, 2.0) - 4.0 * eq.a * eq.c;
  if (delta == 0)
    {
      k = -eq.b / 2.0 * eq.a;
      add_klist(kist, k, ball->color);
    }
  else if (delta > 0)
    {
      k = (-eq.b - sqrt(delta)) / 2.0 * eq.a;
      k2 = (-eq.b + sqrt(delta)) / 2.0 * eq.a;
      if (k <= k2)
	add_klist(kist, k, ball->color);
      else
	add_klist(kist, k2, ball->color);
    }
}
