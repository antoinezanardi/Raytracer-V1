/*
** main.c for main in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 10:54:17 2015 Antoine Zanardi
** Last update Mon Feb  2 16:14:05 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"mlx.h"
#include	"rtv1.h"

int		escape_hook(int keycode)
{
  if (keycode == 65307)
    exit(0);
  return (0);
}

void		init_my_mlx(t_windows *win)
{
  win->mlx_ptr = mlx_init();
  if (!win->mlx_ptr)
    my_putstr_error(2, 0);
  win->win_ptr = mlx_new_window(win->mlx_ptr, LARG, HAUT, "Raytracer 1.0");
  win->img_ptr = mlx_new_image(win->mlx_ptr, LARG, HAUT);
}

int		main(int argc, char **argv)
{
  t_windows	win;

  if (argc != 2)
    my_putstr_error(1, 0);
  parsing(argv[1]);
  init_my_mlx(&win);
  mlx_key_hook(win.win_ptr, &escape_hook, 0);
  win.data = mlx_get_data_addr(win.img_ptr, &win.bpp, &win.line, &win.endian);
  mlx_loop(win.mlx_ptr);
  return (0);
}
