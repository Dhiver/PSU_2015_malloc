/*
** tests_merge_block.c for tests_merge_block in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Feb 03 17:30:43 2016 Bastien DHIVER
** Last update Mon Feb 08 13:01:13 2016 Bastien DHIVER
*/

#include "test_main.h"

void	tests_merge_block_again(t_block tmp)
{
  ast(tmp->size == align_page(align_size(42))
      + align_page(align_size(21) + META_SIZE)
      + align_page(align_size(84) + META_SIZE)
      + align_page(align_size(4096) + META_SIZE)
      - META_SIZE);
}

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
  ast(tmp2->next == tmp3);
  ast(tmp3->size == sav_size);
  ast(tmp3->next == NULL);
  tmp2->free = 1;
  merge_block(tmp3);
  ast(start_point == tmp);
  ast(end_point == tmp);
  ast(tmp->free == 1);
  ast(tmp->prev == NULL);
  ast(tmp->next == NULL);
  tests_merge_block_again(tmp);
}
