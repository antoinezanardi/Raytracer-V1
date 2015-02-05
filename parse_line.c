/*
** parse_line.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 17:08:36 2015 Antoine Zanardi
** Last update Thu Feb  5 09:46:03 2015 Antoine Zanardi
*/

#include	"rtv1.h"

void		str_is_num(char *str, int *compt_str)
{
  if (str[*compt_str] == '-')
    *compt_str = *compt_str + 1;
  if (str[*compt_str] == '\0' || str[*compt_str] == ',')
    my_putstr_error(5, *compt_str);
  while (str[*compt_str] != ',' && str[*compt_str] != '\0')
    {
      if (str[*compt_str] >= '0' && str[*compt_str] <= '9')
	*compt_str = *compt_str + 1;
      else
	my_putstr_error(5, *compt_str);
    }
  pass_spaces(str, compt_str);
}

void		str_is_color(char *str, int *compt_str)
{
  if (my_strcmp("BLACK", str, *compt_str) == 0 ||
      my_strcmp("WHITE", str, *compt_str) == 0 ||
      my_strcmp("RED", str, *compt_str) == 0 ||
      my_strcmp("GREEN", str, *compt_str) == 0 ||
      my_strcmp("BLUE", str, *compt_str) == 0 ||
      my_strcmp("YELLOW", str, *compt_str) == 0 ||
      my_strcmp("PURPLE", str, *compt_str) == 0 ||
      my_strcmp("GREY", str, *compt_str) == 0)
    {
      while (str[*compt_str] >= 'A' && str[*compt_str] <= 'Z')
	*compt_str = *compt_str + 1;
      pass_spaces(str, compt_str);
    }
  else
    my_putstr_error(6, *compt_str);
}

void		correct_plan(char *str, int *compt_str)
{
  int		compt_shape;

  compt_shape = 0;
  while (str[*compt_str] != ' ' && str[*compt_str] != '\t' &&
	 str[*compt_str] != '\0')
    *compt_str = *compt_str + 1;
  while (compt_shape < 6)
    {
      pass_spaces(str, compt_str);
      str_is_num(str, compt_str);
      if (str[*compt_str] == ',')
	*compt_str = *compt_str + 1;
      compt_shape++;
    }
  pass_spaces(str, compt_str);
  str_is_color(str, compt_str);
  if (str[*compt_str] == '\n')
    *compt_str = *compt_str + 1;
  else if (str[*compt_str] == '\0')
    return;
  else
    my_putstr_error(7, *compt_str);
}

void		correct_view(char *str, int *compt_str)
{
  int		compt_shape;

  compt_shape = 0;
  while (str[*compt_str] != ' ' && str[*compt_str] != '\t' &&
	 str[*compt_str] != '\0')
    *compt_str = *compt_str + 1;
  while (compt_shape < 7)
    {
      pass_spaces(str, compt_str);
      str_is_num(str, compt_str);
      if (str[*compt_str] == ',')
	*compt_str = *compt_str + 1;
      compt_shape++;
    }
  pass_spaces(str, compt_str);
  if (str[*compt_str] == '\n')
    *compt_str = *compt_str + 1;
  else if (str[*compt_str] == '\0')
    return;
  else
    my_putstr_error(7, *compt_str);
}

void		correct_shape(char *str, int *compt_str)
{
  int		compt_shape;

  compt_shape = 0;
  while (str[*compt_str] != ' ' && str[*compt_str] != '\t' &&
	 str[*compt_str] != '\0')
    *compt_str = *compt_str + 1;
  while (compt_shape < 7)
    {
      pass_spaces(str, compt_str);
      str_is_num(str, compt_str);
      if (str[*compt_str] == ',')
	*compt_str = *compt_str + 1;
      compt_shape++;
    }
  pass_spaces(str, compt_str);
  str_is_color(str, compt_str);
  if (str[*compt_str] == '\n')
    *compt_str = *compt_str + 1;
  else if (str[*compt_str] == '\0')
    return;
  else
    my_putstr_error(7, *compt_str);
}
