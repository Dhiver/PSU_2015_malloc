/*
** test_main.c for test_main.c in /home/perso/work/projets/malloc_doc/PSU_2015_malloc
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 15:49:05 2016 Bastien DHIVER
** Last update Thu Feb 04 17:24:28 2016 Bastien DHIVER
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
  /*tests_free();*/
  /*reset_env();*/
  printf("\033[34;1m END TESTS \033[0m\n");
  return (0);
}
