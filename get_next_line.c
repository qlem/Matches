/*
** get_next_line.c for get_next_line in /home/dommer_c/rendu/CPE_2015_getnextline
** 
** Made by clement dommerc
** Login   <dommer_c@epitech.net>
** 
** Started on  Wed Jan  6 18:29:33 2016 clement dommerc
** Last update Wed Feb 17 21:20:27 2016 dommer_c
*/

#include "./include/matches.h"

char	*mem_str(char *str, int j)
{
  int	i;

  i = 0;
  while (i < j)
    {
      str[i] = 0;
      i++;
    }
  return (str);
}

char	*str_copy(char *dest, char *src, int i)
{
  int	j;

  j = 0;
  if (dest[j] == 0)
    {
      while (src[i])
	{
	  dest[j] = src[i];
	  i++;
	  j++;
	}
      return (dest);
    }
  while (dest[j] != 0)
    j++;
  while (src[i])
    {
      dest[j] = src[i];
      i++;
      j++;
    }
  return (dest);
}

char	*str_add(char *s1, char *s2)
{
  int	i;
  int	j;
  char	*s3;

  i = 0;
  j = 0;
  while (s2[j])
    j++;
  if (s1 == NULL)
    {
      if ((s3 = malloc(sizeof(char) * j + 1)) == NULL)
	return (NULL);
      s3 = mem_str(s3, j + 1);
      s3 = str_copy(s3, s2, i);
      return (s3);
    }
  while (s1[i])
    i++;
  if ((s3 = malloc(sizeof(char) * (i + j) + 1)) == NULL)
    return (NULL);
  s3 = mem_str(s3, i + j + 1);
  s3 = str_copy(s3, s1, 0);
  s3 = str_copy(s3, s2, 0);
  return (s3);
}

int	check_new_line(char *str, char *rest)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	{
	  str[i] = 0;
	  i++;
	  rest = mem_str(rest, READ_SIZE);
	  while (str[i])
	    rest[j++] = str[i++];
	  return (1);
	}
      i++;
    }
  return (0);
}

char	*get_next_line(const int fd)
{
  char		buf[READ_SIZE + 1];
  char		*line;
  static char	rest[READ_SIZE];

  line = NULL;
  mem_str(buf, READ_SIZE + 1);
  if (rest[0] != 0)
    {
      if ((line = str_add(line, rest)) == NULL)
	return (NULL);
      mem_str(rest, READ_SIZE);
      if (check_new_line(line, rest) == 1)
	return (line);
    }
  while (read(fd, buf, READ_SIZE) > 0)
    {
      if ((line = str_add(line, buf)) == NULL)
	return (NULL);
      if (check_new_line(line, rest) == 1)
	return (line);
      mem_str(buf, READ_SIZE + 1);
    }
  return (line);
}
