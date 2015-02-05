/*
** normal.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Feb  5 17:48:02 2015 Antoine Zanardi
** Last update Thu Feb  5 18:26:11 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"rtv1.h"
#include	"my.h"

t_vec		normal_sphere(t_vec pt)
{
  t_vec		normale;
  t_vec		sphere;

  sphere.x = 0.0;
  sphere.y = 0.0;
  sphere.z = 300.0;
  normale.x = sphere.x - pt.x;
  normale.y = sphere.y - pt.y;
  normale.z = sphere.z - pt.z;
  return (normale);
}

t_vec		check_normal(t_kist *k, t_vec pt)
{
  if (my_strcmp("SPHERE", k->forme, 0) == 0)
    return (normal_sphere(pt));
}
