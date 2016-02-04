/*
** tests_check_addr.c for tests_check_addr in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 16:17:42 2016 Bastien DHIVER
** Last update Thu Feb 04 14:37:12 2016 Bastien DHIVER
*/

#include "test_main.h"

void		tests_check_addr(void)
{
  t_block	ptr;

  ast(start_point == NULL);
  ast(check_addr(NULL) == FALSE);
  ptr = create_block(42);
  start_point = ptr;
  ast(check_addr(NULL) == FALSE);
  ast(check_addr((void *)-1) == FALSE);
  ast(check_addr(sbrk(0)) == FALSE);
  ast(check_addr((t_block)sbrk(0) + 1) == FALSE);
  ast(check_addr((t_block)((char *)ptr + META_SIZE)) == TRUE);
  ast(check_addr(ptr) == FALSE);
}
