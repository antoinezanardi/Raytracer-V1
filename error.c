/*
** error.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 14:02:41 2015 Antoine Zanardi
** Last update Mon Feb  2 17:51:05 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"

void		my_putstr_error2(int error, int nb)
{
  if (error == 7)
    {
      my_putstr("Too many arguments for a declaration, at character n°");
      my_put_nbr(nb + 1);
      my_putchar('\n');
    }
  exit(1);
}

void		my_putstr_error(int error, int nb)
{
  if (error == 1)
    my_putstr("Usage : ./rtv1 file_scene\n");
  else if (error == 2)
    my_putstr("Environement couldn't be found\n");
  else if (error == 3)
    my_putstr("File couldn't be found\n");
  else if (error == 4)
    {
      my_putstr("Invalid shape/light/view, at character n°");
      my_put_nbr(nb + 1);
      my_putchar('\n');
    }
  else if (error == 5)
    {
      my_putstr("Invalid number for coordinates, at character n°");
      my_put_nbr(nb + 1);
      my_putchar('\n');
    }
  else if (error == 6)
    {
      my_putstr("Invalid color, at character n°");
      my_put_nbr(nb + 1);
      my_putchar('\n');
    }
  my_putstr_error2(error, nb);
}
