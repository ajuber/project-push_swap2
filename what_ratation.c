/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_ratation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 14:31:34 by ajubert           #+#    #+#             */
/*   Updated: 2016/05/11 22:30:30 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		what_ratation2(t_list_cir *tmp_b, t_list_cir *tmp_a_next,
		t_list_cir *tmp_a_previous)
{
	int			rot;

	rot = 0;
	while (!((tmp_b->n < tmp_a_next->n && tmp_b->n > tmp_a_previous->n) ||
				(tmp_b->n > tmp_a_next->n && tmp_b->n > tmp_a_previous->n
				&& tmp_a_next->n < tmp_a_previous->n) ||
				(tmp_b->n < tmp_a_next->n && tmp_b->n < tmp_a_previous->n
				&& tmp_a_next->n < tmp_a_previous->n)))
	{
		rot++;
		tmp_a_previous = tmp_a_next;
		tmp_a_next = tmp_a_next->next;
	}
	return (rot);
}

int		what_ratation2a(t_list_cir *tmp_a_next, t_list_cir *tmp_a_previous)
{
	int rot;

	rot = 0;
	while (tmp_a_next->n > tmp_a_previous->n)
	{
		rot++;
		tmp_a_previous = tmp_a_next;
		tmp_a_next = tmp_a_next->next;
	}
	return (rot);
}
