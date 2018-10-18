#include "functions.h"
#include "scene.h"

void						isometric_dot_proj(
	t_s_sv *v,
	void *dot,
	t_s_pp const *const *points,
	void *projection)
{
	t_s_d *const	d = (t_s_d*)dot;
	t_s_dp *const	dp = (t_s_dp*)projection;
	t_tag const		t = d->pos;
	t_s_p *const	p = &((t_s_p*)(v->s->e[e_p].ar[t >> TPS]))[t & TPM];

	(void)points;
	if (iso_dbl_dims_to_tvpos(v, p->xyz, dp->here) == SUCCESS)
		dp->flgs |= F_V_VISIBLE;
	else
		dp->flgs &= ~F_V_VISIBLE;
	dp->argb = d->argb;
	dp->prec = p->xyz[Z];
}
