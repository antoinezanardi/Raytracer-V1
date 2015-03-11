/*
** light.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Feb  5 17:15:24 2015 Antoine Zanardi
** Last update Wed Mar 11 10:14:55 2015 Antoine Zanardi
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

void		calc_pt_inter(t_vec *pt, t_vec *view, t_kist *k, t_vec *vec)
{
  pt->x = view->x + (double)k->k * vec->x;
  pt->y = view->y + (double)k->k * vec->y;
  pt->z = view->z + (double)k->k * vec->z;
}

void		calc_vec_dir(t_light *light, t_vec *pt, t_vec *vec_dir)
{
  vec_dir->x = light->x - pt->x;
  vec_dir->y = light->y - pt->y;
  vec_dir->z = light->z - pt->z;
}

void		init_the_light(t_light *light, t_light *light_s)
{
  light->x = 100.0;
  light->y = 0.0;
  light->z = 100.0;
  light->b_r = 255.0;
  light->b_g = 255.0;
  light->b_b = 255.0;
  light_s->x = 100.0;
  light_s->y = 100.0;
  light_s->z = 100.0;
  light_s->b_r = 255.0;
  light_s->b_g = 255.0;
  light_s->b_b = 255.0;
}

unsigned int	light_my_color(t_kist *k, t_vec vec, t_vec view, t_list **list)
{
  double	cos;
  t_vec		pt;
  t_vec		vec_dir;
  t_vec		normale;
  t_light	tab_light[2];
  unsigned int	color;
  int		compt_tab;

  color = 0;
  compt_tab = 0;
  init_the_light(&tab_light[0], &tab_light[1]);
  while (compt_tab < 2)
    {
      calc_pt_inter(&pt, &view, k, &vec);
      calc_vec_dir(&tab_light[compt_tab], &pt, &vec_dir);
      if (shadow_on(&vec_dir, list, &pt, k) == 1)
	color += brillance(k, 0.0, &tab_light[compt_tab]);
      else
	{
	  normale = check_normal(k, pt);
	  normalize(&normale);
	  normalize(&vec_dir);
	  cos = (normale.x * vec_dir.x + normale.y * vec_dir.y + normale.z * vec_dir.z);
	  if (cos < 0.00001)
	    cos = 0.000;
	  color += brillance(k, cos, &tab_light[compt_tab]);
	}
      compt_tab++;
    }
  return (color);
}
