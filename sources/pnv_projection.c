void						pnv_projection(
	t_s_sv *v,
	void *point,
	t_u_spsv const *const *points,
	void *projection)
{
	t_u_spsv *const	p = (t_u_spsv*)point;
	t_s_pp *const	pp = (t_s_pp*)projection;

	(void)points;
	ft_memcpy(pp.xyz, p.xyz, sizeof(t_pos));
	ft_memcpy(pp.prt, p.prt, sizeof(t_pos));
}
