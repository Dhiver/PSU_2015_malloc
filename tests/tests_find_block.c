/*
** tests_find_block.c for tests_find_block in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 16:50:38 2016 Bastien DHIVER
** Last update Thu Feb 04 14:25:13 2016 Bastien DHIVER
*/

#include "test_main.h"

void		tests_find_block(void)
{
  t_block	tmp;
  t_block	tmp2;
  t_block	tmp3;
  t_block	tmp_last;

  ast(find_block(NULL, 0) == NULL);
  ast(start_point == NULL);
  tmp = create_block(4096);
  start_point = tmp;
  tmp_last = start_point;
  split_block(tmp, 50);
  split_block(tmp->next, 80);
  tmp2 = tmp->next;
  tmp3 = tmp2->next;
  ast(start_point == tmp);
  ast(find_block(NULL, 20) == tmp);
  ast(find_block(&tmp_last, 0) == tmp);
  ast(tmp_last == NULL);
  ast(find_block(&tmp_last, 59) == tmp2);
  ast(tmp_last == tmp);
  ast(start_point == tmp);
  ast(end_point == tmp3);
  ast(find_block(&tmp_last, 20) == tmp);
  ast(tmp_last == NULL);
}
