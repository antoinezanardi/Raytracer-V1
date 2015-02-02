/*
** fc.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 16:15:03 2015 Antoine Zanardi
** Last update Mon Feb  2 18:05:57 2015 Antoine Zanardi
*/

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
      my_putchar(str2[compt2]);
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
