#include "scene.h"

int							chg_tag_refct(
	t_tag tag,
	int chg,
	t_s_s *s,
	t_s_se *grp)
{
	t_refct *const	refct = (int*)grp->ar[tag >> TPS][tag & TPM];
	int const		sign = *refct < 0 ? -1 : 1;

	if (chg > 0)
	{
		if (refct < 0)
			return (RELEASING_TAG);
		if (MAX_REFS - *refct < chg)
			return (REFCOUNT_TOO_BIG);
	}
	else if (chg < 0 && chg > -1 * sign * *refct)
			return (REFCOUNT_INCOHERENT);
	if (!(*refct += chg * sign))
		return (reg_freetags(tag, 0, s, grp));
	return (SUCCESS);
}

int							initiate_tag_release(
	t_tag tag,
	void *se)
{
	t_refct *const	refct = (int*)se;

	if (*refct > 0)
	{
		*refct *= -1;
		return (SUCCESS);
	}
	return (REFCOUNT_INCOHERENT);
}
