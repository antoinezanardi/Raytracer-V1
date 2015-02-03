/*
** param_to_list.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Tue Feb  3 09:53:05 2015 Antoine Zanardi
** Last update Tue Feb  3 19:05:42 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"rtv1.h"
#include	"my.h"

int		view_to_list(char *str, int *compt_str, t_list **list)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (0);
  if (my_strcmp("VIEW", str, *compt_str) == 0)
    elem->forme = "VIEW";
  else
    elem->forme = "LIGHT";
  while (str[*compt_str] != ' ' && str[*compt_str] != '\t')
    *compt_str = *compt_str + 1;
  coor_to_elem(str, compt_str, elem, 'x');
  coor_to_elem(str, compt_str, elem, 'y');
  coor_to_elem(str, compt_str, elem, 'z');
  coor_to_elem(str, compt_str, elem, 'r');
  elem->next = *list;
  elem->prev = NULL;
  if (*list != NULL)
    (*list)->prev = elem;
  *list = elem;
  return (0);
}

int		plan_to_list(char *str, int *compt_str, t_list **list)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (0);
  elem->forme = "PLAN";
  while (str[*compt_str] != ' ' && str[*compt_str] != '\t')
    *compt_str = *compt_str + 1;
  coor_to_elem(str, compt_str, elem, 'x');
  coor_to_elem(str, compt_str, elem, 'y');
  coor_to_elem(str, compt_str, elem, 'z');
  color_to_elem(str, compt_str, elem);
  elem->next = *list;
  elem->prev = NULL;
  if (*list != NULL)
    (*list)->prev = elem;
  *list = elem;
  return (0);
}

int		form_to_list(char *str, int *compt_str, t_list **list)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (0);
  if (my_strcmp("SPHERE", str, *compt_str) == 0)
    elem->forme = "SPHERE";
  else if (my_strcmp("CONE", str, *compt_str) == 0)
    elem->forme = "CONE";
  else
    elem->forme = "CYLINDRE";
  while (str[*compt_str] != ' ' && str[*compt_str] != '\t')
    *compt_str = *compt_str + 1;
  coor_to_elem(str, compt_str, elem, 'x');
  coor_to_elem(str, compt_str, elem, 'y');
  coor_to_elem(str, compt_str, elem, 'z');
  coor_to_elem(str, compt_str, elem, 'r');
  color_to_elem(str, compt_str, elem);
  elem->next = *list;
  elem->prev = NULL;
  if (*list != NULL)
    (*list)->prev = elem;
  *list = elem;
  return (0);
}

void		param_to_list(char *str, t_list **list)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      pass_spaces(str, &compt_str);
      if (correct_form(str, compt_str) == 0)
	form_to_list(str, &compt_str, list);
      else if (correct_form(str, compt_str) == 1)
	plan_to_list(str, &compt_str, list);
      else if (correct_form(str, compt_str) == 2)
	view_to_list(str, &compt_str, list);
      if (str[compt_str] == '\n')
	compt_str++;
    }
}
