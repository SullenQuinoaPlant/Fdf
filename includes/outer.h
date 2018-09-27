#ifndef OUTER_H
# define OUTER_H

# include <stddef.h>
# include <stdint.h>

typedef uint32_t	t_rgba;

/*
**tags are used to find elements in arrays.
**tag type should be unsigned.
**tag size is subject to constraints. See scene.h and DEF_TAG_AR_SZ.
*/
typedef unsigned int	t_tag;

# define SYS_ERR -1
# define SUCCESS 0
# define BAD_ARGS 1
# define MEM_CAP 2

#endif
