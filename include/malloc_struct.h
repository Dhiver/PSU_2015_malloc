/*
** malloc_struct.h for malloc_struct in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/include
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Fri Jan 29 10:52:15 2016 Bastien DHIVER
** Last update Mon Feb 01 12:54:20 2016 Bastien DHIVER
*/

#ifndef MALLOC_STRUCT_H_
# define MALLOC_STRUCT_H_

# include <stddef.h>

typedef struct		s_block
{
  size_t		size;
  int			free;
  void			*ptr;
  struct s_block	*prev;
  struct s_block	*next;
}			*t_block;

#endif /* !MALLOC_STRUCT_H_ */
