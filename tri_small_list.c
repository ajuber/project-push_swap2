/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_small_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:09:36 by ajubert           #+#    #+#             */
/*   Updated: 2016/06/22 18:09:50 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		test_small_list(t_e *e)
{
	if (test_a(e))
		return (1);
	if (e->size_l == 3)
	{
		tri_a_and_b(e);
		return (1);
	}
	if (test_swap_a(e))
		return (1);
	if (e->size_l <= 6)
	{
		tri_small_list(e);
		return (1);
	}
	return (0);
}

void	tri_small_list(t_e *e)
{
	int		i;

	i = 0;
	while (i < e->size_l - 3)
	{
		pb(e);
		i++;
		ft_putendl("pb");
		if_display(e, 1);
	}
	if (e->size_l == 6)
		tri_b_and_a(e);
	e->size_l = 3;
	tri_aa(e);
	after_tri_aa(e);
}
