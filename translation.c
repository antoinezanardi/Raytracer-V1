/*
** movements.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Feb  5 10:00:52 2015 Antoine Zanardi
** Last update Fri Feb  6 16:36:55 2015 Antoine Zanardi
*/

#include	<math.h>
#include	"rtv1.h"
#include	"my.h"

void		translation(t_vec *view, t_list *forme)
{
  view->x = view->x - forme->x;
  view->y = view->y - forme->y;
  view->z = view->z - forme->z;
}

void		rotation_x(double *y, double *z, double angle)
{
  double	save_y;

  save_y = *y;
  *y = (*y) * cos(angle) + (*z) * -(sin(angle));
  *z = save_y * sin(angle) + (*z) * cos(angle);
}

void		rotation_y(double *x, double *z, double angle)
{
  double	save_x;

  save_x = *x;
  *x = *x * cos(angle) + (*z) * sin(angle);
  *z = -(sin(angle)) * (save_x) + cos(angle) * (*z);
}

void		rotation_z(double *x, double *y, double angle)
{
  double	save_x;

  save_x = *x;
  *x = (*x) * cos(angle) + (*y) * -(sin(angle));
  *y = save_x * sin(angle) + (*y) * cos(angle);
}

void		movement(t_vec *view, t_list *forme, t_vec *vec)
{
  rotation_x(&(vec->y), &(vec->z), D_R(forme->x_r));
  rotation_x(&(view->y), &(view->z), D_R(forme->x_r));
  rotation_y(&(vec->x), &(vec->z), D_R(forme->y_r));
  rotation_y(&(view->x), &(view->z), D_R(forme->y_r));
  rotation_z(&(vec->x), &(vec->y), D_R(forme->z_r));
  rotation_z(&(view->x), &(view->y), D_R(forme->z_r));
  translation(view, forme);
}
