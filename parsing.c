/*
** parsing.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 15:26:20 2015 Antoine Zanardi
** Last update Fri Feb  6 17:58:50 2015 Antoine Zanardi
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"my.h"
#include	"rtv1.h"

int		correct_form(char *str, int compt_str)
{
  if (my_strcmp("SPHERE", str, compt_str) == 0 ||
      my_strcmp("CONE", str, compt_str) == 0 ||
      my_strcmp("CYLINDRE", str, compt_str) == 0)
    return (0);
  else if (my_strcmp("PLAN", str, compt_str) == 0)
    return (1);
  else if (my_strcmp("VIEW", str, compt_str) == 0)
    return (2);
  else
    my_putstr_error(4, compt_str);
  return (-1);
}

void		correct_file(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\0')
    {
      pass_spaces(str, &compt_str);
      if (correct_form(str, compt_str) == 0)
	correct_shape(str, &compt_str);
      else if (correct_form(str, compt_str) == 1)
	correct_plan(str, &compt_str);
      else if (correct_form(str, compt_str) == 2)
	correct_view(str, &compt_str);
    }
}

void		parsing(char *file, t_list **list)
{
  int		fd;
  int		ret;
  static char	buffer[BUFFER_SIZE];

  if ((fd = open(file, O_RDONLY)) == -1)
    my_putstr_error(3, 0);
  ret = read(fd, buffer, BUFFER_SIZE);
  buffer[ret] = '\0';
  close(fd);
  correct_file(buffer);
  param_to_list(buffer, list);
  check_the_view(list);
}
