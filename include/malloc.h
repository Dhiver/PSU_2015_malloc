/*
** malloc.h for malloc in /home/perso/work/projets/malloc_doc/PSU_2015_malloc/include
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jan 27 15:36:19 2016 Bastien DHIVER
** Last update Sun Feb 14 21:23:47 2016 Bastien DHIVER
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include "malloc_struct.h"

# define META_SIZE	sizeof(struct s_block)
# define PAGE_SIZE	getpagesize()

typedef	enum		e_bool
{
  FALSE,
  TRUE
}			bool;

extern void		*start_point;
extern void		*end_point;
extern pthread_mutex_t	lock;

void			*malloc(size_t);
void			*malloc_func(size_t);
void			*realloc(void *, size_t);
void			*realloc_func(void *, size_t);
void			free(void *);
void			free_func(void *);
void			*calloc(size_t, size_t);
void			*calloc_func(size_t, size_t);

void			show_alloc_mem(void);
void			show_alloc_mem_free(void);
void			show_alloc_mem_all(void);

bool			check_addr(void *);
t_block			get_block(void *);
void			copy_data(t_block, t_block);
size_t			get_nb_page(t_block);

t_block			create_block(size_t);
t_block			find_block(t_block *, size_t);
void			merge_block(t_block *);
bool			split_block(t_block, size_t);

size_t			align_size(size_t);
size_t			align_page(size_t);

#endif /* !MALLOC_H_ */
