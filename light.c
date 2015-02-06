/*
** light.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Feb  5 17:15:24 2015 Antoine Zanardi
** Last update Fri Feb  6 15:27:40 2015 Antoine Zanardi
*/

#include	<math.h>
#include	"rtv1.h"
#include	"my.h"

void		normalize(t_vec *vec)
{
  double	norme;

  norme = sqrt(pow(vec->x, 2.0) + pow(vec->y, 2.0) + pow(vec->z, 2.0));
  vec->x /= norme;
  vec->y /= norme;
  vec->z /= norme;
}

unsigned int	light_my_color(t_kist *k, t_vec vec, t_vec view)
{
  double	cos;
  t_vec		pt;
  t_vec		light;
  t_vec		vec_dir;
  t_vec		normale;

  light.x = -200.0;
  light.y = 0.0;
  light.z = 100.0;
  pt.x = view.x + k->k * vec.x;
  pt.y = view.y + k->k * vec.y;
  pt.z = view.z + k->k * vec.z;
  vec_dir.x = light.x - pt.x;
  vec_dir.y = light.y - pt.y;
  vec_dir.z = light.z - pt.z;
  normale = check_normal(k, pt);
  normalize(&normale);
  normalize(&vec_dir);
  cos = (normale.x * vec_dir.x + normale.y * vec_dir.y + normale.z * vec_dir.z);
  if (cos > 0.00001)
    return (get_my_color(k->red * cos, k->green * cos, k->blue * cos));
  return (get_my_color(0, 0, 0));
}