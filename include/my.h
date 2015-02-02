/*
** my.h for my in /home/zanard_a/rendu/Brouillons_Piscine/J9/ex2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Oct  9 18:41:53 2014 Antoine Zanardi
** Last update Wed Dec 17 11:49:07 2014 Antoine Zanardi
*/

#ifndef		MY_H_
# define	MY_H_

typedef struct	s_list
{
  int		nombre;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;


void		my_putchar(char);
void		my_put_nbr(int);
void		my_putstr(char*);
void		my_show_list(t_list *);
int		add_top_list(t_list **, int);
int		add_bot_list(t_list **, int);
int		my_strlen(char*);
int		my_getnbr(char*);

#endif		/* !MY_H_ */
