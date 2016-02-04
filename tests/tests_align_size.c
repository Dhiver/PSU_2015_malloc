/*
** tests_align_size.c for tests_align_size in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Feb 04 11:01:26 2016 Bastien DHIVER
** Last update Thu Feb 04 13:36:04 2016 Bastien DHIVER
*/

#include "test_main.h"

void		tests_align_size(void)
{
  ast(align_size(0) == sizeof(void *));
  ast(align_size(1) == sizeof(void *));
  ast(align_size(7) == sizeof(void *));
  ast(align_size(8) == sizeof(void *));
  ast(align_size(9) == sizeof(void *) * 2);
  ast(align_size(15) == sizeof(void *) * 2);
  ast(align_size(16) == sizeof(void *) * 2);
  ast(align_size(17) == sizeof(void *) * 3);
  ast(align_size(42) == sizeof(void *) * 6);
}
