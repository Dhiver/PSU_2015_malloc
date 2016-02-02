/*
** tests_create_block.c for tests_create_block in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 16:40:46 2016 Bastien DHIVER
** Last update Tue Feb 02 16:49:09 2016 Bastien DHIVER
*/

#include "test_main.h"

void		tests_create_block(void)
{
  t_block	tmp;
  size_t	magic_size;
  t_block	old_end_point;

  magic_size = 42;
  old_end_point = end_point;
  tmp = create_block(magic_size);
  assert(tmp->size == magic_size);
  assert(tmp->free == 1);
  assert(tmp->ptr == tmp + META_SIZE);
  assert(tmp->prev == old_end_point);
  assert(tmp->next == NULL);
  assert(end_point = tmp);
  brk(tmp);
}
