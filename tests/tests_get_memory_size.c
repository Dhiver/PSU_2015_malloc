/*
** tests_get_memory_size.c for tests_get_memory_size.c in /home/perso/work/projets/malloc_doc/PSU_2015_malloc
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 15:47:55 2016 Bastien DHIVER
** Last update Tue Feb 02 16:15:14 2016 Bastien DHIVER
*/

#include "test_main.h"

void		tests_get_memory_size(void)
{
  size_t	cur_page_size;

  cur_page_size = getpagesize();
  assert(get_memory_size(0) == 0);
  assert(get_memory_size(42) == cur_page_size);
  assert(get_memory_size(cur_page_size - 1) == cur_page_size);
  assert(get_memory_size(cur_page_size) == cur_page_size);
  assert(get_memory_size(cur_page_size + 1) == cur_page_size * 2);
  assert(get_memory_size(cur_page_size * 2 - 1) == cur_page_size * 2);
  assert(get_memory_size(cur_page_size * 2) == cur_page_size * 2);
  assert(get_memory_size(cur_page_size * 2 + 1) == cur_page_size * 3);
}
