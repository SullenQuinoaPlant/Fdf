/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdgfxyrz_builder.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:32:05 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/07 04:55:40 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CDGFXYRZ_BUILDER_H
# define CDGFXYRZ_BUILDER_H

# include "scene.h"
# include "parse.h"
# include "functions.h"

int							cdgfxyrz_add_lines(
	t_s_cdgfxyrz	*p,
	t_tag			*tags,
	t_s_s			*scene,
	t_s_o			*object);

#endif
