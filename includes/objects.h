#ifndef OBJECTS_H
# define OBJECTS_H

/*
**Objects that may live in the scene.
*/

typedef struct				s_point
{
	union
	{
		struct
		{
			int		x;
			int		y;
			int		z;
		};
		struct
		{
			double	t;
			double	p;
			double	r;
		};
	};
	uint32_t	rgba;
}							t_s_p;

/*
**t_s_v stands for typedef struct vector
**describe vectors as (point) - (0,0,0):
*/
typedef t_s_p	t_s_v;

# define L_END1 0
# define L_END2 1
# define L_END 0
# define L_VEC 1
typedef struct				s_line
{
	union
	{
		t_s_p	ends[2];
		t_s_p	pnr[2];
	}
}							t_s_l;

#endif
