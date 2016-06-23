/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 01:13:38 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/24 07:25:45 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_e *e)
{
	t_list_cir *tmp_a;
	t_list_cir *tmp_b;
	t_list_cir *tmp_b1;

	if (e->l_b->next != e->l_b)
	{
		tmp_b = e->l_b->next;
		tmp_a = e->l_a->next;
		tmp_b1 = tmp_b->next;
		e->l_a->next = tmp_b;
		tmp_b->previous = e->l_a;
		tmp_b->next = tmp_a;
		tmp_a->previous = tmp_b;
		e->l_b->next = tmp_b1;
		tmp_b1->previous = e->l_b;
	}
}

void	pb(t_e *e)
{
	t_list_cir *tmp_a;
	t_list_cir *tmp_a1;
	t_list_cir *tmp_b;

	if (e->l_a->next != e->l_a)
	{
		tmp_b = e->l_b->next;
		tmp_a = e->l_a->next;
		tmp_a1 = tmp_a->next;
		e->l_b->next = tmp_a;
		tmp_a->previous = e->l_b;
		tmp_a->next = tmp_b;
		tmp_b->previous = tmp_a;
		e->l_a->next = tmp_a1;
		tmp_a1->previous = e->l_a;
	}
}
