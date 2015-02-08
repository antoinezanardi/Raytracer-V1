/*
** get_double.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Sat Feb  7 10:51:19 2015 Antoine Zanardi
** Last update Sat Feb  7 15:11:41 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<math.h>
#include	"my.h"
#include	"rtv1.h"

int		count_decimal(char *str, int compt_str)
{
  int		compt_dec;

  compt_dec = 0;
  while (str[compt_str] != '.')
    compt_str++;
  compt_str++;
  while (str[compt_str] != ',')
    {
      compt_str++;
      compt_dec++;
    }
  return (compt_dec);
}

char		*pick_decimal(char *str, int compt_str)
{
  char		*dec;
  int		compt_save;
  int		compt_dec;

  compt_save = compt_str;
  while (str[compt_str] != '.')
    compt_str++;
  compt_str++;
  if ((dec = malloc(sizeof(char) * count_decimal(str, compt_save) + 1)) == NULL)
      return (NULL);
  compt_dec = 0;
  while (str[compt_str] != ',')
    {
      dec[compt_dec] = str[compt_str];
      compt_str++;
      compt_dec++;
    }
  dec[compt_dec] = '\0';
  return (dec);
}

double		my_get_double(char *str, int compt_str)
{
  double	result;
  char		*dec;

  if (str[compt_str] == '1')
    return (1.0);
  else if (str[compt_str] == '0' && str[compt_str + 1] == ',')
    return (0.0);
  else
    {
      dec = pick_decimal(str, compt_str);
      result = my_getnbr(dec) * pow(10, -(count_decimal(str, compt_str)));
    }
  return (result);
}
