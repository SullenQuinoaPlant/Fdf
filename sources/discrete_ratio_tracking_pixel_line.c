void							targb_pair_to_tdni(
	t_argb *argbs,
	t_delta_n_init *ret)
{
	t_argb argb1
	t_argb argb2,
	int		i;
	t_ruint	c;

	argb1 = argbs[0];
	argb2 = argbs[1];
	i = -1;
	while (++i < ARGBS)
	{
		c = argb1 & ARGB_MASK;
		dec[i][INIT] = c;
		dec[i][DT] = argb2 & ARGB_MASK - c;
		argb1 >> ARGB_SHIFT;
		argb2 >> ARGB_SHIFT;
	}
}


int							track_pixel_line(
	t_s_lp const *const l,
	t_ruint **ret)
{
	t_delta_n_init pxl_dec[ARGBS + V_DIMS];

	targb_pair_to_tdni(l->argb, pxl_dec);
	tvpos_pair_to_tdni(l->ends, pxl_dec + ARGBS]
