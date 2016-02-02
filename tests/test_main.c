/*
** test_main.c for test_main.c in /home/perso/work/projets/malloc_doc/PSU_2015_malloc
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 15:49:05 2016 Bastien DHIVER
** Last update Tue Feb 02 16:43:55 2016 Bastien DHIVER
*/

#include "test_main.h"

int	main(void)
{
  tests_get_memory_size();
  tests_check_addr();
  tests_create_block();
  printf("\033[32;1m OK !\033[0m\n");
  return (0);
}
