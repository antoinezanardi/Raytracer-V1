/*
** picture.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb  4 10:15:52 2015 Antoine Zanardi
** Last update Wed Feb  4 10:40:39 2015 Antoine Zanardi
*/

#include	"rtv1.h"
#include	"my.h"

unsigned int	get_my_color(unsigned char rouge, unsigned char vert, unsigned
			     char bleu)
{
  return ((rouge << 16) | (vert << 8) | (bleu));
}

int		put_pix_picture(t_windows *win, int x, int y, int color)
{
  int		rang;

  if (x >= LARG || y >= HAUT || x < 0 || y < 0)
    return (1);
  rang = x * win->bpp / 8 + y * win->line;
  win->data[rang] = color & 0xFF;
  win->data[rang + 1] = (color >> 8) & 0xFF;
  win->data[rang + 2] = (color >> 16) & 0xFF;
  win->data[rang + 3] = 0xFF;
  return (0);
}
