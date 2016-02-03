/*
** tests_split_block.c for tests_split_block in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Feb 03 09:40:45 2016 Bastien DHIVER
** Last update Wed Feb 03 12:25:05 2016 Bastien DHIVER
*/

#include "test_main.h"

void		tests_split_block(void)
{
  t_block	tmp;
  t_block	splited_blk;
  t_block	tmp_next;
  size_t	magic_size;

  magic_size = 42;
  assert(start_point == NULL);
  assert(end_point == NULL);
  tmp = create_block(magic_size);
  assert(split_block(NULL, magic_size) == FALSE);
  assert(split_block(tmp, magic_size + 1) == FALSE);
  assert(split_block(tmp, 4096 - META_SIZE + 1) == FALSE);
  tmp_next = tmp->next;
  assert(split_block(tmp, magic_size - META_SIZE) == TRUE);
  splited_blk = (t_block)((char *)tmp + META_SIZE + (magic_size - META_SIZE));
  assert(tmp->size == magic_size - META_SIZE);
  assert(splited_blk->size == 0);
  assert(splited_blk->free == 1);
  assert(splited_blk->ptr == (t_block)((char *)splited_blk + META_SIZE));
  assert(splited_blk->prev == tmp);
  assert(tmp->next == splited_blk);
  assert(splited_blk->next == tmp_next);
  assert(end_point == splited_blk);
}
