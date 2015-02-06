/*
** main.c for main in /home/zanard_a/rendu/Projets_TEK1/MUL_2014_rtv1
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Mon Feb  2 10:54:17 2015 Antoine Zanardi
** Last update Fri Feb  6 15:45:25 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"mlx.h"
#include	"rtv1.h"

int		my_expose(t_windows *win)
{
  mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr, 0, 0);
}

int		escape_hook(int keycode)
{
  if (keycode == 65307)
    exit(0);
  return (0);
}

void		init_list(t_list **list, int argc, char **argv)
{
  if (argc != 2)
    my_putstr_error(1, 0);
  if (my_strcmp("--help", argv[1], 0) == 0)
    my_notice();
  *list = NULL;
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
  t_list	*list;

  init_list(&list, argc, argv);
  parsing(argv[1], &list);
  init_my_mlx(&win);
  mlx_key_hook(win.win_ptr, &escape_hook, 0);
  win.data = mlx_get_data_addr(win.img_ptr, &win.bpp, &win.line, &win.endian);
  treat(&win, &list);
  mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.img_ptr, 0, 0);
  mlx_expose_hook(win.win_ptr, &my_expose, &win);
  mlx_loop(win.mlx_ptr);
  return (0);
}
