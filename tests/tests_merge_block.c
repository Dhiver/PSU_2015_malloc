/*
** tests_merge_block.c for tests_merge_block in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Feb 03 17:30:43 2016 Bastien DHIVER
** Last update Thu Feb 04 13:46:46 2016 Bastien DHIVER
*/

#include "test_main.h"

void		tests_merge_block(void)
{
  t_block	tmp;
  t_block	tmp2;
  t_block	tmp3;

  tmp = malloc(21);
  tmp2 = malloc(42);
  tmp3 = malloc(84);
  ((t_block)((char *)tmp - META_SIZE))->free = 1;
  ((t_block)((char *)tmp2 - META_SIZE))->free = 1;
  ((t_block)((char *)tmp3 - META_SIZE))->free = 1;
  /* TODO must be on the same page */
  printf("get_nb_page = %ld\n", get_nb_page((t_block)((char *)tmp - META_SIZE)));
  printf("get_nb_page = %ld\n", get_nb_page((t_block)((char *)tmp2 - META_SIZE)));
  printf("get_nb_page = %ld\n", get_nb_page((t_block)((char *)tmp3 - META_SIZE)));
  show_alloc_mem();
  merge_block(tmp);
  show_alloc_mem();
}
