/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:56:07 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/20 16:59:02 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "outer.h"

#define USAGE "usage: ./fdf path-to-conforming-file\n"

int								usage(
	void)
{
	int const	len = ft_strlen(USAGE);
	int			r;

	if ((r = write(1, USAGE, ft_strlen(USAGE))) != len)
		return (SYS_ERR);
	return (SUCCESS);
}
