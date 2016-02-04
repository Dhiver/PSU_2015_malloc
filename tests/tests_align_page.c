/*
** tests_align_page.c for tests_align_page in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Feb 04 10:57:34 2016 Bastien DHIVER
** Last update Thu Feb 04 13:36:19 2016 Bastien DHIVER
*/

#include "test_main.h"

void		tests_align_page(void)
{
  size_t	cur_page_size;

  cur_page_size = getpagesize();
  ast(align_page(0) == cur_page_size);
  ast(align_page(42) == cur_page_size);
  ast(align_page(cur_page_size - 1) == cur_page_size);
  ast(align_page(cur_page_size) == cur_page_size);
  ast(align_page(cur_page_size + 1) == cur_page_size * 2);
  ast(align_page(cur_page_size * 2 - 1) == cur_page_size * 2);
  ast(align_page(cur_page_size * 2) == cur_page_size * 2);
  ast(align_page(cur_page_size * 2 + 1) == cur_page_size * 3);
}
