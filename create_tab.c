/*
** create_tab.c for Allum1 in /home/dommer_c/rendu/CPE_2015_Allum1
** 
** Made by dommer_c
** Login   <dommer_c@epitech.net>
** 
** Started on  Wed Feb 17 19:05:26 2016 dommer_c
** Last update Fri Feb 19 23:21:56 2016 dommer_c
*/

#include "include/matches.h"

void	free_tab(int **tab, t_list *list)
{
  int	i;

  i = 0;
  while (i < list->line)
    {
      free(tab[i]);
      i++;
    }
}

int	**set_tab_loop(int **tab, t_list *list, int i, int j)
{
  if (i == 0 || i == (list->line -1))
    tab[i][j] = 2;
  else if (j == 0 || j == (list->col -1))
    tab[i][j] = 2;
  else if (i >= 1 && i <= (list->line - 2))
    {
      if (j >= ((list->line - 2) - list->k) &&
	  j <= ((list->line - 2) + list->k))
	{
	  tab[i][j] = 1;
	  list->match++;
	  tab[i][list->col]++;
	}
      else if (j < list->col)
	tab[i][j] = 0;
    }
  return (tab);
}

int	**set_tab(int **tab, t_list *list)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < list->line)
    {
      tab[i][list->col] = 0;
      while (j <= list->col)
        {
          tab = set_tab_loop(tab, list, i, j);
          j++;
        }
      i++;
      j = 0;
      if (i >= 2 && i <= (list->line - 2))
        list->k++;
    }
  return (tab);
}

int	**create_tab(int **tab, t_list *list)
{
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(int *) * list->line)) == NULL)
    return (NULL);
  while (i < list->line)
    {
      if ((tab[i] = malloc(sizeof(int) * (list->col + 1))) == NULL)
        return (NULL);
      i++;
    }
  tab = set_tab(tab, list);
  return (tab);
}
