#include "scene.h"

static int				chg_tag_refct(
	t_tag tag,
	int chg,
	t_s_s *scene,
	t_s_se *grp)
{
	int *const	refct = (int*)grp;

	if (chg > 0 && UINT_MAX - *refct <= (unsigned int)chg)
		return (REF_COUNT_TOO_BIG);
	else if (chg < 0 && *refct < (unsigned int)(-chg))
		return (NEGATIVE_REF_COUNT);
	else if (!(*refct += chg))
		return (reg_freetags(tag, 0, scene, grp));
	return (SUCCESS);
}
