/*
** tests_find_block.c for tests_find_block in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 16:50:38 2016 Bastien DHIVER
** Last update Wed Feb 03 13:53:23 2016 Bastien DHIVER
*/

#include "test_main.h"

void		tests_find_block(void)
{
  t_block	tmp;
  t_block	tmp2;
  t_block	tmp3;
  t_block	tmp_last;

  assert(find_block(NULL, 0) == NULL);
  assert(start_point == NULL);
  tmp = create_block(4096);
  start_point = tmp;
  tmp_last = start_point;
  split_block(tmp, 50);
  split_block(tmp->next, 80);
  tmp2 = tmp->next;
  tmp3 = tmp2->next;
  assert(start_point == tmp);
  assert(find_block(NULL, 20) == tmp);
  assert(find_block(&tmp_last, 0) == tmp);
  assert(tmp_last == NULL);
  assert(find_block(&tmp_last, 51) == tmp2);
  assert(tmp_last == tmp);
  assert(start_point == tmp);
  assert(end_point == tmp3);
  assert(find_block(&tmp_last, 20) == tmp);
  assert(tmp_last == NULL);
}
