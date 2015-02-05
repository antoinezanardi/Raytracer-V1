/*
** v_to_elem.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Feb  3 17:08:23 2015 Antoine Zanardi
** Last update Thu Feb  5 09:54:53 2015 Antoine Zanardi
*/

#include	"my.h"
#include	"rtv1.h"

void		coor_to_elem(char *str, int *compt_str, t_list *elem, char mde)
{
  pass_spaces(str, compt_str);
  if (mde == 'x')
    elem->x = my_getnbr(pick_nb(str, compt_str));
  else if (mde == 'y')
    elem->y = my_getnbr(pick_nb(str, compt_str));
  else if (mde == 'z')
    elem->z = my_getnbr(pick_nb(str, compt_str));
  else if (mde == 'r')
    elem->ray = my_getnbr(pick_nb(str, compt_str));
  else if (mde == 'a')
    elem->x_r = my_getnbr(pick_nb(str, compt_str));
  else if (mde == 'b')
    elem->y_r = my_getnbr(pick_nb(str, compt_str));
  else if (mde == 'c')
    elem->z_r = my_getnbr(pick_nb(str, compt_str));
  (*compt_str)++;
  pass_spaces(str, compt_str);
}

void		color_to_elem(char *str, int *compt_str, t_list *elem)
{
  pass_spaces(str, compt_str);
  if (my_strcmp("BLACK", str, *compt_str) == 0)
    elem->color = "BLACK";
  else if (my_strcmp("WHITE", str, *compt_str) == 0)
    elem->color = "WHITE";
  else if (my_strcmp("RED", str, *compt_str) == 0)
    elem->color = "RED";
  else if (my_strcmp("GREEN", str, *compt_str) == 0)
    elem->color = "GREEN";
  else if (my_strcmp("BLUE", str, *compt_str) == 0)
    elem->color = "BLUE";
  else if (my_strcmp("YELLOW", str, *compt_str) == 0)
    elem->color = "YELLOW";
  else if (my_strcmp("PURPLE", str, *compt_str) == 0)
    elem->color = "PURPLE";
  else if (my_strcmp("GREY", str, *compt_str) == 0)
    elem->color = "GREY";
  while (str[*compt_str] >= 'A' && str[*compt_str] <= 'Z')
    *compt_str = *compt_str + 1;
  pass_spaces(str, compt_str);
}
