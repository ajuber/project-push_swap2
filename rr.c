/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 03:19:25 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/24 03:19:36 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_e *e)
{
	t_list_cir *tmp;
	t_list_cir *tmp1;

	tmp = e->l_a->next;
	tmp1 = tmp->next;
	tmp1->previous = e->l_a;
	e->l_a->next = tmp1;
	tmp1 = e->l_a->previous;
	tmp1->next = tmp;
	tmp->next = e->l_a;
	e->l_a->previous = tmp;
	tmp->previous = tmp1;
}

void	rb(t_e *e)
{
	t_list_cir *tmp;
	t_list_cir *tmp1;

	tmp = e->l_b->next;
	tmp1 = tmp->next;
	tmp1->previous = e->l_b;
	e->l_b->next = tmp1;
	tmp1 = e->l_b->previous;
	tmp1->next = tmp;
	tmp->next = e->l_b;
	e->l_b->previous = tmp;
	tmp->previous = tmp1;
}

void	rr(t_e *e)
{
	ra(e);
	rb(e);
}
