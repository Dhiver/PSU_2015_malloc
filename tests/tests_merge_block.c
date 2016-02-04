/*
** tests_merge_block.c for tests_merge_block in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Feb 03 17:30:43 2016 Bastien DHIVER
** Last update Thu Feb 04 17:23:43 2016 Bastien DHIVER
*/

#include "test_main.h"

void		tests_merge_block(void)
{
  t_block	tmp;
  t_block	tmp2;
  t_block	tmp3;
  t_block	tmp4;
  size_t	sav_size;

  tmp = create_block(42);
  start_point = tmp;
  tmp2 = create_block(21);
  tmp3 = create_block(84);
  tmp4 = create_block(4096);
  tmp2->free = 0;
  sav_size = tmp3->size + tmp4->size + META_SIZE;
  merge_block(tmp3);
  ast(tmp3->size == sav_size);
}
