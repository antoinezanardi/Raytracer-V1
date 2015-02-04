/*
** fc.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 16:15:03 2015 Antoine Zanardi
** Last update Wed Feb  4 17:46:34 2015 Antoine Zanardi
*/

#include	<stdlib.h>

void		pass_spaces(char *str, int *compt_str)
{
  while ((str[*compt_str] == ' ' || str[*compt_str] == '\t') &&
	 str[*compt_str] != '\0')
    *compt_str = *compt_str + 1;
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
  if ((dest = malloc(sizeof(char) * compt_len + 1)) == NULL)
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
