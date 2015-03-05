/*
** color.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb  7 15:56:35 2015 Antoine Zanardi
** Last update Thu Mar  5 16:30:09 2015 Antoine Zanardi
*/

#include	<math.h>
#include	"rtv1.h"
#include	"my.h"

unsigned int	treat_the_color(t_kist *k, double cos, t_light *light)
{
  t_color	color;

  color.red = ((unsigned char)(k->red * (1 - k->obj->bri) +
			       light->b_r * k->obj->bri));
  color.green = ((unsigned char)(k->green * (1 - k->obj->bri) +
				 light->b_g * k->obj->bri));
  color.blue = ((unsigned char)(k->blue * (1 - k->obj->bri) +
				light->b_b * k->obj->bri));
  color.red = ((unsigned char)(color.red * cos));
  color.green = ((unsigned char)(color.green * cos));
  color.blue = ((unsigned char)(color.blue * cos));
  return (get_my_color(color.red, color.green, color.blue));
}
