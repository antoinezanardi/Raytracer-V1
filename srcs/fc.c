/*
** fc.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 16:15:03 2015 Antoine Zanardi
** Last update Thu Mar  5 17:13:22 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"rtv1.h"

void		pass_spaces(char *str, int *compt_str)
{
  while ((str[*compt_str] == ' ' || str[*compt_str] == '\t') &&
	 str[*compt_str] != '\0')
    *compt_str = *compt_str + 1;
}

void		str_is_low_nb(char *str, int *compt_str)
{
  if (str[*compt_str] == '1' && str[*compt_str + 1] != ',')
    my_putstr_error(5, *compt_str);
  if (str[*compt_str] == '1')
    *compt_str = *compt_str + 2;
  else if (str[*compt_str] != '0')
    my_putstr_error(5, *compt_str);
  else if (str[*compt_str] == '0' && str[*compt_str + 1] == ',')
    *compt_str = *compt_str + 2;
  else
    {
      if (str[*compt_str + 1] != '.')
	my_putstr_error(5, *compt_str);
      if (!(str[*compt_str + 2] >= '0' && str[*compt_str + 2] <= '9'))
	my_putstr_error(5, *compt_str);
      *compt_str = *compt_str + 2;
      while (str[*compt_str] != ',' && str[*compt_str] != '\0')
	if (str[*compt_str] >= '0' && str[*compt_str] <= '9')
	  *compt_str = *compt_str + 1;
	else
	  my_putstr_error(5, *compt_str);
    }
  if (str[*compt_str] == ',')
    *compt_str = *compt_str + 1;
  pass_spaces(str, compt_str);
}

int		my_strcmp(char *str, char *str2, int compt2)
{
  int		compt;

  compt = 0;
  while (str[compt] != '\0')
    {
      if (str2[compt2] == '\0' || str[compt] != str2[compt2])
	return (1);
      else
	{
	  compt++;
	  compt2++;
	}
    }
  return (0);
}

char		*pick_nb(char *str, int *compt_str)
{
  char		*dest;
  int		compt_len;

  compt_len = 0;
  if (str[*compt_str] == '-')
    {
      *compt_str = *compt_str + 1;
      compt_len++;
    }
  while (str[*compt_str] != ',')
    {
      *compt_str = *compt_str + 1;
      compt_len++;
    }
  *compt_str = *compt_str - compt_len;
  if ((dest = malloc(sizeof(char) * (unsigned int)compt_len + 1)) == NULL)
    return (NULL);
  compt_len = 0;
  while (str[*compt_str] != ',')
    {
      dest[compt_len] = str[(*compt_str)++];
      compt_len++;
    }
  dest[compt_len] = '\0';
  return (dest);
}
