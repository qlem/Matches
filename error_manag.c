/*
** error_manag.c for Allum1 in /home/dommer_c/rendu/CPE_2015_Allum1
** 
** Made by dommer_c
** Login   <dommer_c@epitech.net>
** 
** Started on  Thu Feb 18 03:34:27 2016 dommer_c
** Last update Fri Feb 19 05:35:44 2016 dommer_c
*/

#include "include/matches.h"

int	check_match_line(int **tab, t_list *list)
{
  int	i;
  int	j;
  int	k;

  i = list->pl;
  j = list->col - 1;
  k = 0;
  while (j >= 1)
    {
      if (tab[i][j] == 1)
        k++;
      j--;
    }
  if (list->pm > k)
    return (1);
  return (0);
}

int	check_empty_line(int **tab, t_list *list)
{
  int	i;
  int	j;

  i = list->pl;
  j = list->col - 1;
  while (j >= 1 && tab[i][j] != 1)
    j--;
  if (j == 0)
    return (1);
  return (0);
}

int	check_entry(char *ent)
{
  int   i;

  i = 0;
  while (ent[i])
    {
      if (ent[0] == '-')
        i++;
      else if (ent[i] >= '0' && ent[i] <= '9')
        i++;
      else
        return (1);
    }
  return (0);
}

int	check_pm_error(int **tab, char *ent, t_list *list)
{
  if (ent[0] == 0 || check_entry(ent) == 1)
    {
      printf("Error: invalid input (positive number expected)\n");
      return (1);
    }
  list->pm = atoi(ent);
  if (list->pm < 0)
    {
      printf("Error: invalid input (positive number expected)\n");
      return (1);
    }
  else if (list->pm == 0)
    {
      printf("Error: you have to remove at least one match\n");
      return (1);
    }
  else if (list->pm > tab[list->pl][list->col])
    {
      printf("Error: not enough matches on this line\n");
      return (1);
    }
  return (0);
}

int	check_pl_error(int **tab, char *ent, t_list *list)
{
  if (ent[0] == 0 || check_entry(ent) == 1)
    {
      printf("Error: invalid input (positive number expected)\n");
      return (1);
    }
  list->pl = atoi(ent);
  if (list->pl > (list->line - 2) || list->pl == 0)
    {
      printf("Error: this line is out of range\n");
      return (1);
    }
  else if (list->pl < 0)
    {
      printf("Error: invalid input (positive number expected)\n");
      return (1);
    }
  else if (tab[list->pl][list->col] == 0)
    {
      printf("Error: this line is empty\n");
      return (1);
    }
  return (0);
}
