#ifndef DISCRETE_RATIO_TRACKING
# define DISCRETE_RATIO_TRACKING

# define DT 0
# define INIT 1
# define DNI_SZ 2

typedef t_ruint (t_delta_n_init)[DNI_SZ];

/*
**Ratio unsigned integer :
*/
typedef unsigned int	t_ruint;

# define DT 0
# define E1 1
# define E2 2
# define DNE_SZ 3

typedef t_ruint	(t_delta_n_ends)[DNE_SZ];

#endif
