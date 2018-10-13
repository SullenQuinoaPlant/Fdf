/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_double_tvuint_conversions.          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 03:30:50 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 03:40:36 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_vuint						dbl_to_tvuint(
	t_vuint dim_sz,
	double d)
{
	int const		sign = d > 0 ? 1 : -1;
	t_vuint cost	offset = dim_sz / 2;
	t_vuint			ret;

	if (d == 1)
		ret = (t_vuint)d + offset;
	else
		ret = offset - (t_vuint)(sign * d);
	return (ret);
}

int							dbl_within_dimsz(
	t_vuint dim_sz,
	double d)
{
	int const		sign = d > 0 ? 1 : -1;
	int const		even = dim_sz & 0x1 ? 0 : 1;
	int				ret;

	if ((d *= (double)sign) > (double)TVUINT_MAX)
	if (even && sign == 1)
		ret = 
}
