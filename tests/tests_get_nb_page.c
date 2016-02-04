/*
** tests_get_nb_page.c for tests_get_nb_page in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Feb 04 14:58:15 2016 Bastien DHIVER
** Last update Thu Feb 04 15:31:35 2016 Bastien DHIVER
*/

#include "test_main.h"

void		tests_get_nb_page(void)
{
  t_block	tmp;
  t_block	tmp2;
  t_block	tmp3;
  t_block	tmp4;

  tmp = malloc(40);
  tmp2 = malloc(100);
  tmp3 = malloc(3980);
  tmp4 = malloc(70);
  show_alloc_mem();
  show_alloc_mem_free();
  ast(get_nb_page(tmp) == 1);
  ast(get_nb_page(tmp2) == 1);
  ast(get_nb_page(tmp3) == 2);
  ast(get_nb_page(tmp4) == 1);
}
