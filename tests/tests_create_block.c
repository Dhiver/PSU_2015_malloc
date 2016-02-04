/*
** tests_create_block.c for tests_create_block in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 16:40:46 2016 Bastien DHIVER
** Last update Thu Feb 04 13:45:58 2016 Bastien DHIVER
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
  ast(tmp->size == align_page(align_size(magic_size) + META_SIZE));
  ast(tmp->free == 1);
  ast(tmp->ptr == (char *)tmp + META_SIZE);
  ast(tmp->prev == old_end_point);
  ast(tmp->next == NULL);
  ast(end_point == tmp);
  brk(tmp);
}
