/*
** allum1.c for Allum1 in /home/dommer_c/rendu/CPE_2015_Allum1
** 
** Made by dommer_c
** Login   <dommer_c@epitech.net>
** 
** Started on  Wed Feb 17 16:28:02 2016 dommer_c
** Last update Sun Feb 21 21:54:20 2016 dommer_c
*/

#include "include/matches.h"

void	display_tab(int **tab, t_list *list, int x)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < list->line)
    {
      while (j < list->col)
	{
	  if (tab[i][j] == 0)
	    write(1, " ", 1);
	  else if (tab[i][j] == 1)
	    write(1, "|", 1);
	  else if (tab[i][j] == 2)
	    write(1, "*", 1);
	  j++;
	}
      write(1, "\n", 1);
      i++;
      j = 0;
    }
  if (x == 1)
    write(1, "\n", 1);
}

int	**delete_match(int **tab, t_list *list)
{
  int	j;
  int	i;

  i = list->pl;
  j = list->col - 1;
  while (list->pm > 0)
    {
      while (tab[i][j] != 1)
	j--;
      tab[i][j] = 0;
      tab[i][list->col]--;
      list->pm--;
      list->match--;
    }
  if (list->match == 0)
    {
      display_tab(tab, list, 0);
      printf("You lost, too bad..\n");
      return (NULL);
    }
  return (tab);
}

int	allum_one_loop(int **tab, t_list *list)
{
  char	*ent;
    
  printf("Line: ");
  ent = get_next_line(0);
  if (check_pl_error(tab, ent, list) == 1)
    {
      free(ent);
      return (allum_one_loop(tab, list));
    }
  printf("Matches: ");
  ent = get_next_line(0);
  if (check_pm_error(tab, ent, list) == 1)
    {
      free(ent);
      return (allum_one_loop(tab, list));
    }
  free(ent);
  return (0);
}

int	allum_one(int **tab, t_list *list, t_intel *intel)
{
  while (42)
    {
      printf("Your turn:\n");
      allum_one_loop(tab, list);
      printf("Player removed %d match(es) from line %d\n",
		list->pm, list->pl);
      if (delete_match(tab, list) == NULL)
	{
	  free_tab(tab, list);
	  free(list);
	  free(intel);
	  return (0);
	}
      display_tab(tab, list, 1);
      if (intel_art(tab, list, intel) == NULL)
	{
	  free_tab(tab, list);
	  free(list);
	  free(intel);
	  return (0);
	}
    }
  return (0);
}

int	main(int ac, char **av)
{
  int		**tab;
  t_list	*list;
  t_intel	*intel;

  tab = NULL;
  if ((list = malloc(sizeof(t_list))) == NULL)
    return (2);
  if ((intel = malloc(sizeof(t_intel))) == NULL)
    return (2);
  init_var(list, intel);
  if (ac == 1)
    list->line = 6;
  else if (check_arg(ac, av, list) == 1)
    return (1);
  list->col = ((list->line - 3) * 2) + 3;
  tab = create_tab(tab, list);
  display_tab(tab, list, 1);
  allum_one(tab, list, intel);
  return (0);
}
