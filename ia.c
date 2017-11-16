/*
** ia.c for Allum1 in /home/dommer_c/rendu/CPE_2015_Allum1
** 
** Made by dommer_c
** Login   <dommer_c@epitech.net>
** 
** Started on  Thu Feb 18 03:52:34 2016 dommer_c
** Last update Sun Feb 21 21:56:39 2016 dommer_c
*/

#include "include/matches.h"

int	**delete_match_ia(int **tab, t_list *list)
{
  int	i;
  int	j;
  int	k;

  i = list->il;
  j = list->col - 1;
  k = list->im;
  while (k > 0)
    {
      if (tab[i][j] == 1)
	{
	  tab[i][j] = 0;
	  tab[i][list->col]--;
	  list->match--;
	  k--;
	}
      j--;
    }
  return (tab);
}

int	search_nim(int **tab, t_list *list)
{
  int	i;
  int	nim;

  i = 1;
  nim = 0;
  while (i < (list->line - 1))
    {
      nim = nim^tab[i][list->col];
      i++;
    }
  list->nim = nim;
  return (nim);
}

int	search_il_im(int **tab, t_list *list)
{
  int	save;

  list->im = 1;
  list->il = 1;
  while (tab[list->il][list->col] == 0)
    list->il++;
  save = tab[list->il][list->col];
  tab[list->il][list->col] = tab[list->il][list->col] - list->im;
  while (list->il < (list->line -1) && search_nim(tab, list) != 0)
    {
      list->im++;
      if (list->im > save)
	save = search_il_im_loop(tab, list, save);
      else
	tab[list->il][list->col] = save - list->im;
    }
  if (save == tab[list->il][list->col])
    {
      set_one_match_ia(tab, list);
      return (1);
    }
  tab[list->il][list->col] = save;
  return (0);
}

void	set_intel(int **tab, t_list *list, t_intel *intel)
{
  int	i;

  i = 1;
  intel->lsone = 0;
  intel->lone = 0;
  while (i < (list->line - 1))
    {
      if (tab[i][list->col] > 1)
	intel->lsone++;
      else if (tab[i][list->col] == 1)
	intel->lone++;
      i++;
    }
}

int	**intel_art(int **tab, t_list *list, t_intel *intel)
{
  set_intel(tab, list, intel);
  if (check_special(tab, list, intel) == 0)
    search_il_im(tab, list);
  tab = delete_match_ia(tab, list);
  printf("AI's turn...\n");
  printf("AI removed %d match(es) from line %d\n", list->im, list->il);
  if (list->match == 0)
    {
      display_tab(tab, list, 0);
      printf("I lost.. snif.. but I'll get you next time!!\n");
      return (NULL);
    }
  display_tab(tab, list, 1);
  return (tab);
}
