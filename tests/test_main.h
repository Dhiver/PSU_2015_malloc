/*
** test_main.h for test_main.h in /home/perso/work/projets/malloc_doc/PSU_2015_malloc
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Feb 02 15:49:40 2016 Bastien DHIVER
** Last update Tue Feb 09 12:34:59 2016 Bastien DHIVER
*/

#ifndef	TEST_MAIN_H_
# define TEST_MAIN_H_

# include "my_assert.h"
# include "malloc.h"

void		tests_check_addr(void);
void		tests_create_block(void);
void		tests_find_block(void);
void		tests_split_block(void);
void		tests_malloc(void);
void		tests_free(void);
void		tests_merge_block(void);
void		tests_align_size(void);
void		tests_align_page(void);
void		tests_get_nb_page(void);
void		tests_bzero(void);
void		tests_realloc(void);
void		tests_calloc(void);

#endif /* !TEST_MAIN_H_ */
