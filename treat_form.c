/*
** treat_form.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb  4 10:01:49 2015 Antoine Zanardi
** Last update Wed Feb  4 17:40:40 2015 Antoine Zanardi
*/

#include	<math.h>
#include	"rtv1.h"
#include	"my.h"

void		treat_ball(t_vec vec, t_kist **kist, t_list *ball)
{
  t_eq		eq;
  double	k;
  double	k2;
  double	delta;

  eq.a = pow(vec.x, 2.0) + pow(vec.y, 2.0) + pow(vec.z, 2.0);
  eq.b = 2.0 * ((double)ball->x * vec.x + (double)ball->y * vec.y +
		(double)ball->z * vec.z);
  eq.c = pow(ball->x, 2.0) + pow(ball->y, 2.0) + pow(ball->z, 2.0) -
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
