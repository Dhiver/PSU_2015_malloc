/*
** malloc.h for malloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/include
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:36:19 2016 Bastien DHIVER
** Last update Wed Jan 27 15:51:38 2016 Bastien DHIVER
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <unistd.h>
# include <stdio.h>

void		*malloc(size_t);
void		*realloc(void *, size_t);
void		free(void *);
void		show_alloc_mem(void);

#endif /* !MALLOC_H_ */
