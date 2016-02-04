/*
** my_assert.h for my_assert in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Feb 04 12:29:25 2016 Bastien DHIVER
** Last update Thu Feb 04 13:34:22 2016 Bastien DHIVER
*/

#ifndef MY_ASSERT_H_
# define MY_ASSERT_H_

# define ast(x) my_assert(x, __FILE__, __LINE__, __func__)

void		my_assert(int, const char *, int, const char *);

#endif /* !MY_ASSERT_H_ */
