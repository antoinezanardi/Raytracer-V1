/*
** my_atoi_base.c for atoi in /home/zanard_a
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Jan 22 16:38:30 2015 Antoine Zanardi
** Last update Thu Jan 22 16:55:05 2015 Antoine Zanardi
*/

void	my_put_nbr(int nb, char *base)
{
  int	size;

  size = my_strlen(base);
  if (nb >= 10)
    {
      my_put_nbr(nb / size);
      my_putchar(nb % size + 48);
    }
  else if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr(nb * -1);
    }
  else if (nb >= 0 && nb <= 9)
    my_putchar(nb + 48);
}
