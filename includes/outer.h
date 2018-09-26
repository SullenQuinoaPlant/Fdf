#ifndef OUTER_H
# define OUTER_H

# include <stddef.h>
# include <stdint.h>

typedef uint32_t	t_rgba;

/*
**tag value 0 is special and should not be assigned to any active
**object
*/
typedef unsigned int	t_tag;
# define UNTAGGED (t_tag)0

#endif
