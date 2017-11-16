/*
** my.h for allum1 in /home/dommer_c/rendu/CPE_2015_Allum1/include
** 
** Made by dommer_c
** Login   <dommer_c@epitech.net>
** 
** Started on  Wed Feb 17 16:16:41 2016 dommer_c
** Last update Sun Feb 21 21:47:39 2016 dommer_c
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_SIZE (14)

typedef struct	s_list
{
  int		line;
  int		col;
  int		match;
  int		k;
  int		pl;
  int		pm;
  int		il;
  int		im;
  int		nim;
}		t_list;

typedef struct	s_intel
{
  int		lone;
  int		lsone;
}		t_intel;

void	free_tab(int **tab, t_list *list);
int	    **set_tab_loop(int **tab, t_list *list, int i, int j);
int	    **set_tab(int **tab, t_list *list);
int	    **create_tab(int **tab, t_list *list);
int	    check_entry(char *ent);
int	    check_pm_error(int **tab, char *ent, t_list *list);
int	    check_pl_error(int **tab, char *ent, t_list *list);
int	    **delete_match_ia(int **tab, t_list *list);
int	    search_nim(int **tab, t_list *list);
int	    search_il_im_loop(int **tab, t_list *list, int save);
int	    search_il_im(int **tab, t_list *list);
void	set_intel(int **tab, t_list *list, t_intel *intel);
int	    **intel_art(int **tab, t_list *list, t_intel *intel);
void	display_tab(int **tab, t_list *list, int x);
int	    **delete_match(int **tab, t_list *list);
int	    allum_one_loop(int **tab, t_list *list);
int	    allum_one(int **tab, t_list *list, t_intel *intel);
int	    check_one_line(int **tab, t_list *list);
void	check_one_sone_even(int **tab, t_list *list);
void	check_one_sone_uneven(int **tab, t_list *list);
int	    check_line_one(int **tab,t_list *list);
int	    check_special(int **tab, t_list *list, t_intel *intel);
void	set_one_match_ia(int **tab, t_list *list);
void	init_var(t_list *list, t_intel *intel);
int	    check_arg(int ac,char **av, t_list *list);
char	*get_next_line(const int fd);

#endif /* !MY_H_ */
