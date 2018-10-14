size_t						get_ve_size(
	t_e_seg g)
{
	size_t const	sizes[e_seg_sz] = {
		sizeof(t_u_spsv),
		sizeof(t_s_dp),
		sizeof(t_s_loap),
		sizeof(t_s_fp),
		sizeof(t_s_op)};

	return (sizes[g]);
}
