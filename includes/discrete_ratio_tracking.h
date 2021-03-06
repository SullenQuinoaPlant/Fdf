#ifndef DISCRETE_RATIO_TRACKING
# define DISCRETE_RATIO_TRACKING

# include "outer.h"

/*
**Ratio unsigned integer :
*/
# define TRUINT_MAX UINT_MAX
typedef unsigned int	t_ruint;

# define DNI_DT 0
# define DNI_INI 1
# define DNI_SZ 2

/*
**typedef t_ruint (t_delta_n_init)[DNI_SZ];
*/
typedef t_ruint	(t_dni)[DNI_SZ];

/*
**typedef t_ruint	(t_truint_decomposition)[PXL_DEC_SZ];
*/

typedef t_ruint	(t_ruint_dec)[PXL_DEC_SZ];

#endif
