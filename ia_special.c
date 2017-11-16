/*
** ia_special.c for Allum1 in /home/dommer_c/rendu/CPE_2015_Allum1
** 
** Made by dommer_c
** Login   <dommer_c@epitech.net>
** 
** Started on  Sat Feb 20 00:49:53 2016 dommer_c
** Last update Sat Feb 20 01:34:05 2016 dommer_c
*/

#include "include/matches.h"

int	check_one_line(int **tab, t_list *list)
{
  int	i;

  i = 1;
  while (i < (list->line - 1))
    {
      if (tab[i][list->col] > 0)
        {
          list->il = i;
          list->im = tab[i][list->col] - 1;
        }
      i++;
    }
  return (0);
}

void	check_one_sone_even(int **tab, t_list *list)
{
  int	i;

  i = 1;
  while (i < (list->line - 1))
    {
      if (tab[i][list->col] > 1)
        {
          list->il = i;
          list->im = tab[i][list->col];
        }
      i++;
    }
}

void	check_one_sone_uneven(int **tab, t_list *list)
{
  int	i;

  i = 1;
  while (i < (list->line - 1))
    {
      if (tab[i][list->col] > 1)
        {
          list->il = i;
          list->im = tab[i][list->col] - 1;
        }
      i++;
    }
}

int	check_line_one(int **tab, t_list *list)
{
  int	i;

  i = 1;
  while (i < (list->line - 1))
    {
      if (tab[i][list->col] == 1)
	{
	  list->il = i;
	  list->im = tab[i][list->col];
	  return (1);
	}
      i++;
    }
  return (0);
}

int	check_special(int **tab, t_list *list, t_intel *intel)
{
  if (intel->lsone == 1 && intel->lone == 0)
    {
      check_one_line(tab, list);
      return (1);
    }
  else if (intel->lsone == 1 && intel->lone > 0)
    {
      if (((intel->lsone + intel->lone) % 2) == 0)
        check_one_sone_even(tab, list);
      else
        check_one_sone_uneven(tab, list);
      return (1);
    }
  else if (intel->lsone == 0 && intel->lone > 1)
    {
      check_line_one(tab, list);
      return (1);
    }
  return (0);
}
