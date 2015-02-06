/*
** error.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 14:02:41 2015 Antoine Zanardi
** Last update Fri Feb  6 16:03:14 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"

void		my_notice(void)
{
  my_putstr("\n                     ~ HOW TO USE ~\n");
  my_putstr("\nFORME | X | Y | Z | RAY | X_R | Y_R | Z_R | COLOR\n");
  my_putstr("FORME : You can choose between : SPHERE / PLAN\n");
  my_putstr("X / Y / Z : Position of the form\n");
  my_putstr("RAY : ONLY for sphere, cylindre, cone\n");
  my_putstr("X_R / Y_R / Z_R : Rotate in those coordinates\n");
  //  my_putstr("BRI : Coeff between 0 & 1 of how bright the object is\n");
  // my_putstr("HT : Hauteur : ONLY for the cylindre and cone\n");
  my_putstr("COLOR : Choose : BLACK / WHITE / BLUE / RED / GREEN / YELLOW\n\n");
  exit(0);
}

void		my_putstr_error2(int error, int nb)
{
  if (error == 7)
    {
      my_putstr("Too many arguments for a declaration, at character n°");
      my_put_nbr(nb + 1);
      my_putchar('\n');
    }
  else if (error == 8)
    my_putstr("A point of view has to be set\n");
  exit(1);
}

void		my_putstr_error(int error, int nb)
{
  if (error == 1)
    my_putstr("Usage : ./rtv1 file_scene.rtv\n");
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
