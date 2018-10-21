/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_typedefs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:29:29 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/20 19:13:15 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TYPEDEFS_H
# define PARSE_TYPEDEFS_H

# include "scene_typedefs.h"

typedef struct s_cartesian_xy_dot	t_s_cxyd;

typedef enum e_scene_input_types	t_e_sit;

typedef struct s_cartesian_dot_grid_fullxy_regularz	t_s_cdgfxyrz;

typedef struct s_scene_builder_input	t_s_sbi;

typedef int		(*t_scene_builder)(void*, t_s_s*);

typedef void	(*t_tssbi_freer)(void*);
/*
**typedef struct s_cartesian_xy_dot	t_s_cxyd;
**
**typedef struct s_scene_builder_input	t_s_sbi;
*/

#endif
