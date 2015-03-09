/*
** color.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb  7 15:56:35 2015 Antoine Zanardi
** Last update Mon Mar  9 10:37:02 2015 Antoine Zanardi
*/

#include	<math.h>
#include	"rtv1.h"
#include	"my.h"

void		check_seuil(t_color *seuil, t_color *color)
{
  if (color->red < seuil->red)
    color->red = seuil->red;
  if (color->green < seuil->green)
    color->green = seuil->green;
  if (color->blue < seuil->blue)
    color->blue = seuil->blue;
}

void		calc_seuil(t_color *seuil, t_color *color)
{
  seuil->red = (color->red * (25.0 / 100.0));
  seuil->green = (color->green * (25.0 / 100.0));
  seuil->blue = (color->blue * (25.0 / 100.0));
}

unsigned int	brillance(t_kist *k, double cos, t_light *light)
{
  t_color	color;
  t_color	seuil;

  color.red = ((unsigned char)(k->red * (1 - k->obj->bri) +
			       light->b_r * k->obj->bri));
  color.green = ((unsigned char)(k->green * (1 - k->obj->bri) +
				 light->b_g * k->obj->bri));
  color.blue = ((unsigned char)(k->blue * (1 - k->obj->bri) +
				light->b_b * k->obj->bri));
  calc_seuil(&seuil, &color);
  color.red = ((unsigned char)(color.red * cos));
  color.green = ((unsigned char)(color.green * cos));
  color.blue = ((unsigned char)(color.blue * cos));
  check_seuil(&seuil, &color);
  return (get_my_color(color.red, color.green, color.blue));
}
