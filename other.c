/*
** other.c for Allum1 in /home/dommer_c/rendu/CPE_2015_Allum1
** 
** Made by dommer_c
** Login   <dommer_c@epitech.net>
** 
** Started on  Sat Feb 20 03:10:34 2016 dommer_c
** Last update Sun Feb 21 21:47:51 2016 dommer_c
*/

#include "include/matches.h"

int	search_il_im_loop(int **tab, t_list *list, int save)
{
  tab[list->il][list->col] = save;
  list->il++;
  list->im = 1;
  save = tab[list->il][list->col];
  if (save > 0)
    tab[list->il][list->col] = tab[list->il][list->col] - list->im;
  return (save);
}

void	set_one_match_ia(int **tab, t_list *list)
{
  int	i;

  i = 1;
  while (tab[i][list->col] == 0)
    i++;
  list->il = i;
  list->im = 1;
}

void	init_var(t_list *list, t_intel *intel)
{
  list->line = 0;
  list->col = 0;
  list->match = 0;
  list->k = 0;
  list->pl = 0;
  list->pm = 0;
  list->il = 0;
  list->im = 0;
  list->nim = 0;
  intel->lone = 0;
  intel->lsone = 0;
}

int	check_arg(int ac, char **av, t_list *list)
{
  int	i;

  i = 0;
  if (ac > 2)
    {
      printf("usage: ./allum1 [nbr_line > 1]\n");
      return (1);
    }
  while (av[1][i])
    {
      if (av[1][i] >= '1' && av[1][i] <= '9')
        i++;
      else
        {
          printf("usage: ./allum1 [nbr_line > 1]\n");
          return (1);
        }
    }
  if ((list->line = atoi(av[1]) + 2) < 3)
    {
      printf("usage: ./allum1 [nbr_line > 1]\n");
      return (1);
    }
  return (0);
}
