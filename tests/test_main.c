/*
** test_main.c for test_main.c in /home/perso/work/projets/malloc_doc/PSU_2015_malloc
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 15:49:05 2016 Bastien DHIVER
** Last update Mon Feb 08 17:54:41 2016 Bastien DHIVER
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

void	unit_tests_again(void)
{
  tests_bzero();
  reset_env();
  tests_calloc();
  reset_env();
}

int     main(void)
{
  tests_align_size();
  reset_env();
  tests_align_page();
  reset_env();
  tests_create_block();
  reset_env();
  tests_split_block();
  reset_env();
  tests_find_block();
  reset_env();
  tests_check_addr();
  reset_env();
  tests_get_nb_page();
  reset_env();
  tests_merge_block();
  reset_env();
  tests_malloc();
  reset_env();
  tests_free();
  reset_env();
  unit_tests_again();
  printf("\033[34;1m END TESTS \033[0m\n");
  return (0);
}
