/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:16:29 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 15:39:14 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/*
** x	|1	0	0	|
**		|0	cos	-sin|
**		|0	sin	cos	|
**
** y	|cos  0	sin	|
**		|0	  1	0	|
**		|-sin 0	cos	|
**
** z	|cos -sin 0	|
**		|sin cos  0	|
**		|0	 1	  1	|
*/

void		pf_rotate(t_vector *v, t_cam cam)
{
	double x;
	double y;
	double z;

	x = v->x;
	z = v->z;
	v->x = cos(cam.y) * x - sin(cam.y) * z;
	v->z = sin(cam.y) * x + cos(cam.y) * z;
	y = v->y;
	z = v->z;
	v->y = cos(cam.x) * y + sin(cam.x) * z;
	v->z = -sin(cam.x) * y + cos(cam.x) * z;
	x = v->x;
	y = v->y;
	v->x = cos(cam.z) * x + sin(cam.z) * y;
	v->y = -sin(cam.z) * x + cos(cam.z) * y;
}

t_vector	fx_transform(t_vector v, t_cam cam, t_map map)
{
	t_vector ret;

	ret.x = v.x - (map.width - 1) / 2.0;
	ret.y = v.y - (map.height - 1) / 2.0;
	ret.z = v.z - (map.depth_max - map.depth_min) / 2.0;
	ret.color = v.color;
	pf_rotate(&ret, cam);
	ret.x *= cam.scale;
	ret.y *= cam.scale;
	ret.x += cam.offsetx;
	ret.y += cam.offsety;
	return (ret);
}
