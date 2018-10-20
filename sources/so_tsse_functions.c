#include "functions.h"
#include "scene.h"

/*
**No t_refct bookeeping done in the following:
**	the structures are being freed so any subsequent access is an error.
*/
void					free_tso_tsse_content(
	t_s_se *se)
{
	t_s_o **const	po_ar = (t_s_o**)se->ar;
	t_s_o			*po;
	size_t			ar_sz;
	size_t			i;

	ar_sz = se->ar_sz;
	while (ar_sz--)
	{
		i = -1;
		while (++i < TAS)
		{
			po = &po_ar[ar_sz][i];
			free_object_lists(po);
		}
	}
}
