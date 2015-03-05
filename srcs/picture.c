/*
** picture.c for rtv1 in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Feb  4 10:15:52 2015 Antoine Zanardi
** Last update Thu Mar  5 16:59:03 2015 Antoine Zanardi
*/

#include	"rtv1.h"
#include	"my.h"

unsigned int	get_my_color(unsigned char rouge, unsigned char vert, unsigned
			     char bleu)
{
  return ((unsigned int)(rouge << 16) | (unsigned int)(vert << 8) |
	  (unsigned int)(bleu));
}

int		put_pix_picture(t_windows *win, int x, int y, int color)
{
  int		rang;

  if (x >= LARG || y >= HAUT || x < 0 || y < 0)
    return (1);
  rang = x * win->bpp / 8 + y * win->line;
  win->data[rang] = color & (char)0xFF;
  win->data[rang + 1] = (color >> 8) & (char)0xFF;
  win->data[rang + 2] = (color >> 16) & (char)0xFF;
  win->data[rang + 3] = (char)0xFF;
  return (0);
}
