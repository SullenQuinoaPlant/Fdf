typedef struct				s_scene_points_and_vectors
{
	t_u_spsv	**ar;
	size_t		ar_sz;
	t_list		*nxt;
}							t_s_spnv;

typedef struct				s_scene_dots
{
	t_s_d	**ar;
	size_t	ar_sz;
	t_list	*nxt;
}							t_s_sd;

typedef struct				s_scene_lines_and_arrows
{
	t_u_slsa	**ar;
	size_t		ar_sz;
	t_list		*nxt;
}							t_s_slna;

typedef struct				s_scene_areas
{
	t_s_a	**ars;
	size_t	ar_sz;
	t_tag	nxt_tag;
}							t_s_sa;

typedef struct				s_scene_objects
{
	t_s_o	**ars;
	size_t	ar_sz;
	t_tag	nxt_tag;
}							t_s_so;

