/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_projections.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 00:41:08 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 01:19:56 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_PROJECTIONS_H
# define LINE_PROJECTIONS_H

/*
** A line may cross the rectangular views' boundaries four times when we extend
** these to infinity. Therefore isect[4].
*/
# define ISEC_CT 4

/*
 * Indexes of:
 * - first point, 
 * - delta between first point and second point, 
 * - second point
 * in the stupid mash-up array
*/
# define P1 0
# define DELTA 1
# define P2 2

#endif
