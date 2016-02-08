/*
** my_assert.c for my_assert in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Feb 04 12:29:30 2016 Bastien DHIVER
** Last update Mon Feb 08 09:51:24 2016 Bastien DHIVER
*/

#include "my_assert.h"

void	__ast_print_nbr(size_t nb)
{
  char	value;

  if (nb < 10)
    {
      value = nb + 48;
      write(1, &value, 1);
      return ;
    }
  __ast_print_nbr(nb / 10);
  value = (nb % 10) + 48;
  write(1, &value, 1);
  return ;
}

int	__ast(const char *file, size_t line, const char *fct, const char *e)
{
  write(1, program_invocation_short_name, \
	strlen(program_invocation_short_name));
  write(1, ": ", 2);
  write(1, file, strlen(file));
  write(1, ":", 1);
  __ast_print_nbr(line);
  write(1, " ", 1);
  write(1, fct, strlen(fct));
  write(1, ": Assertion `", 13);
  write(1, e, strlen(e));
  write(1, "' failed.\n", 10);
  abort();
}
