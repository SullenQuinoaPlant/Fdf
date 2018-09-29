#include "scene.h"

int						chg_tag_refct(
	t_tag tag,
	int chg,
	t_s_se *grp)
{
	void *const	pe = grp->ar[tag >> TPS][tag & TPM];
	return (chg_e_refct(chg, pe));
}

int						chg_e_refct(
	int chg,
	void *pe)
{
	int *const	refct = (int*)pe;

	if (chg > 0 && UINT_MAX - *refct <= (unsigned int)chg)
		return (REF_COUNT_TOO_BIG);
	else if (chg < 0 && *refct < (unsigned int)(-chg))
		return (NEGATIVE_REF_COUNT);
	*refct += chg;
	return (SUCCESS);
}
