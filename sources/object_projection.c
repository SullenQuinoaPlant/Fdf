void						obj_proj
	t_s_sv *v,
	void *obj,
	t_u_spsv const *const *points,
	void *projection)
{
	t_s_o *const	o = (t_s_o*)obj;
	t_s_op *const	op = (t_s_op*)projection;

	(void)points;
	(void)obj;
	op->flgs = O_SHOW;
}
