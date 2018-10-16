#ifndef DISCRETE_RATIO_TRACKING
# define DISCRETE_RATIO_TRACKING

/*
**Ratio unsigned integer :
*/
# define TRUINT_MAX UINT_MAX
typedef unsigned int	t_ruint;

# define DT 0
# define INIT 1
# define DNI_SZ 2

typedef t_ruint (t_delta_n_init)[DNI_SZ];

#endif
