/*
** my_assert.h for my_assert in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Feb 04 12:29:25 2016 Bastien DHIVER
** Last update Fri Feb 05 00:15:43 2016 Bastien DHIVER
*/

#ifndef MY_ASSERT_H_
# define MY_ASSERT_H_

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

extern char	*program_invocation_short_name;

# define ast(e) ((e) ? 0 : __ast(__FILE__, __LINE__, __func__, #e))

int		__ast(const char *, size_t, const char *, const char *);

#endif /* !MY_ASSERT_H_ */
