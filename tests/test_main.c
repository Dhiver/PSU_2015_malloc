/*
** test_main.c for test_main.c in /home/perso/work/projets/malloc_doc/PSU_2015_malloc
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 15:49:05 2016 Bastien DHIVER
** Last update Wed Feb 03 14:24:37 2016 Bastien DHIVER
*/

#include "test_main.h"

void	reset_end_and_start_points(void)
{
  start_point = NULL;
  end_point = NULL;
}

void	reset_env(void)
{
  reset_end_and_start_points();
}

int	main(void)
{
  tests_get_memory_size();
  reset_env();
  tests_create_block();
  reset_env();
  tests_split_block();
  reset_env();
  tests_find_block();
  reset_env();
  tests_check_addr();
  reset_env();
  tests_malloc();
  reset_env();
  printf("\033[32;1m OK !\033[0m\n");
  return (0);
}
