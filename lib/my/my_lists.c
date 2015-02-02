/*
** my_lists.c for my_lists in /home/zanard_a/rendu/Librairie/Librairie_off
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Dec 17 11:19:28 2014 Antoine Zanardi
** Last update Wed Dec 17 11:40:10 2014 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"

int             add_top_list(t_list **list, int nombre)
{
  t_list        *elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (0);
  elem->nombre = nombre;
  elem->next = *list;
  elem->prev = NULL;
  if (*list != NULL)
    (*list)->prev = elem;
  *list = elem;
  return (0);
}

int             add_bot_list(t_list **list, int nombre)
{
  t_list        *elem;
  t_list        *tmp;

  if ((*list) == NULL)
    return (add_top_list(list, nombre));
  elem = malloc(sizeof(t_list));
  if (elem == NULL)
    return (0);
  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  elem->nombre = nombre;
  elem->next = NULL;
  elem->prev = tmp;
  tmp->next = elem;
  return (0);
}

void            my_show_list(t_list *list)
{
  t_list        *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_put_nbr(tmp->nombre);
      my_putchar(' ');
      tmp = tmp->next;
    }
  my_putchar('\n');
}
