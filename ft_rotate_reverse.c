/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 03:17:40 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/24 03:37:53 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_e *e)
{
	t_list_cir *tmp;
	t_list_cir *tmp1;

	tmp = e->l_a->previous;
	tmp1 = tmp->previous;
	tmp1->next = e->l_a;
	e->l_a->previous = tmp1;
	tmp1 = e->l_a->next;
	tmp1->previous = tmp;
	tmp->next = tmp1;
	tmp->previous = e->l_a;
	e->l_a->next = tmp;
}

void	rrb(t_e *e)
{
	t_list_cir *tmp;
	t_list_cir *tmp1;

	tmp = e->l_b->previous;
	tmp1 = tmp->previous;
	tmp1->next = e->l_b;
	e->l_b->previous = tmp1;
	tmp1 = e->l_b->next;
	tmp1->previous = tmp;
	tmp->next = tmp1;
	tmp->previous = e->l_b;
	e->l_b->next = tmp;
}

void	rrr(t_e *e)
{
	rra(e);
	rrb(e);
}
