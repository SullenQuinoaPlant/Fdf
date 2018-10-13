/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_double_tvuint_conversions.          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 03:30:50 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 04:28:07 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int							dbl_to_tvuint(
	t_vuint dim_sz,
	double d
	t_vuint *ret)
{
	int const		sign = d > 0 ? 1 : -1;
	t_vuint cost	offset = dim_sz / 2;

	if (!dbl_within_dimsz(dim_sz, d))
		return (OUT_OF_VIEW);
	if (sign == 1)
		*ret = (t_vuint)d + offset;
	else
		*ret = offset - (t_vuint)(sign * d);
	return (SUCCESS);
}

int							dbl_within_dimsz(
	t_vuint dim_sz,
	double d)
{
	t_vuint const	half = dim_sz / 2;
	int const		sign = d > 0 ? 1 : -1;
	int const		even = dim_sz & 0x1 ? 0 : 1;
	t_vuint			cast;
	int				ret;

	if ((d *= (double)sign) > (double)(TVUINT_MAX))
		return (0);
	cast = (t_vuint)d;
	if (even && sign == 1)
		ret = cast > half - 1 ? 0 : 1;
	else
		ret = cast > half ? 0 : 1;
	return (ret);
}
