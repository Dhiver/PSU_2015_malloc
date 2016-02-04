/*
** tests_split_block.c for tests_split_block in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Feb 03 09:40:45 2016 Bastien DHIVER
** Last update Thu Feb 04 14:02:46 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include "test_main.h"

void		tests_split_block_again(t_block tmp, t_block splited_blk)
{
  ast(end_point == splited_blk);
  ast((char *)tmp + META_SIZE + tmp->size + align_size(1) ==
      (char *)splited_blk);
}

void		tests_split_block(void)
{
  t_block	tmp;
  t_block	splited_blk;
  t_block	tmp_next;
  size_t	magic_size;
  size_t	old_tmp_size;

  magic_size = 42;
  tmp = create_block(magic_size);
  ast(split_block(NULL, magic_size) == FALSE);
  ast(split_block(tmp, tmp->size + 1) == FALSE);
  tmp_next = tmp->next;
  old_tmp_size = tmp->size;
  ast(split_block(tmp, magic_size) == TRUE);
  splited_blk = (t_block)((char *)tmp + META_SIZE +
			  align_size(magic_size) + align_size(1));
  ast(tmp->size == align_size(magic_size));
  ast(splited_blk->size == old_tmp_size - (align_size(magic_size) +
					   META_SIZE + align_size(1)));
  ast(splited_blk->free == 1);
  ast(splited_blk->ptr == (t_block)((char *)splited_blk + META_SIZE));
  ast(splited_blk->prev == tmp);
  ast(tmp->next == splited_blk);
  ast(splited_blk->next == tmp_next);
  tests_split_block_again(tmp, splited_blk);
}
