/*
** normal.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Feb  5 17:48:02 2015 Antoine Zanardi
** Last update Sun Feb  8 16:21:58 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"rtv1.h"
#include	"my.h"

t_vec		normal_cy(t_vec pt, t_kist *k)
{
  t_vec		normale;

  rotation_x(&normale.y, &normale.z, D_R(k->obj->x_r));
  rotation_y(&normale.x, &normale.z, D_R(k->obj->y_r));
  rotation_z(&normale.x, &normale.y, D_R(k->obj->z_r));
  normale.x = pt.x - (double)k->obj->x;
  normale.y = pt.y - (double)k->obj->y;
  normale.z = 0;
  return (normale);
}

t_vec		normal_sphere(t_vec pt, t_kist *k)
{
  t_vec		normale;

  normale.x = pt.x - (double)k->obj->x;
  normale.y = pt.y - (double)k->obj->y;
  normale.z = pt.z - (double)k->obj->z;
  return (normale);
}

t_vec		normal_cone(t_vec pt, t_kist *k)
{
  t_vec		normale;

  rotation_x(&normale.y, &normale.z, D_R(k->obj->x_r));
  rotation_y(&normale.x, &normale.z, D_R(k->obj->y_r));
  rotation_z(&normale.x, &normale.y, D_R(k->obj->z_r));
  normale.x = pt.x - (double)k->obj->x;
  normale.y = pt.y - (double)k->obj->y;
  normale.z = pt.z - (double)k->obj->z;
  normale.z = normale.z * -0.5;
  return (normale);
}

t_vec		normal_plan(t_kist *k)
{
  t_vec		normale;

  normale.x = 0.0;
  normale.y = 0.0;
  normale.z = 100.0;
  rotation_x(&normale.y, &normale.z, D_R(k->obj->x_r));
  rotation_y(&normale.x, &normale.z, D_R(k->obj->y_r));
  rotation_z(&normale.x, &normale.y, D_R(k->obj->z_r));
  normale.x = normale.x - (double)k->obj->x;
  normale.y = normale.y - (double)k->obj->y;
  normale.z = normale.z - (double)k->obj->z;
  return (normale);
}

t_vec		check_normal(t_kist *k, t_vec pt)
{
  t_vec		null;

  if (my_strcmp("SPHERE", k->obj->forme, 0) == 0)
    return (normal_sphere(pt, k));
  else if (my_strcmp("PLAN", k->obj->forme, 0) == 0)
    return (normal_plan(k));
  else if (my_strcmp("CYLINDRE", k->obj->forme, 0) == 0)
    return (normal_cy(pt, k));
  else if (my_strcmp("CONE", k->obj->forme, 0) == 0)
    return (normal_cone(pt, k));
  return (null);
}
