#ifndef RING_H
# define RING_H

# include <stddef.h>

/*
**Ring headers must be the initial member
**	of containing struct.
*/

typedef void	*t_ring;

typedef struct s_ring_header	t_s_ring;
struct					s_ring_header
{
	t_s_ring	*prv;
	t_s_ring	*nxt;
};

typedef int	(*t_ringapply)(void*, t_ring);

# define RING_SYS_ERR -1
# define RING_SUCCESS 0

#endif
