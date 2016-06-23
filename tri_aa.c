/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 05:50:31 by ajubert           #+#    #+#             */
/*   Updated: 2016/06/22 18:20:39 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_aa_else(t_e *e, t_list_cir *tmp_b, t_list_cir *tmp_a_next,
		t_list_cir *tmp_a_previous)
{
	int		rot;
	int		rev_rot;
	int		test;

	test = 1;
	rot = what_ratation2(tmp_b, tmp_a_next, tmp_a_previous);
	rev_rot = e->size_l - rot;
	if (rot <= rev_rot)
		while (rot > 0 || test)
		{
			test = 0;
			rot--;
			ra(e);
			ft_putendl("ra");
			if_display(e, 1);
		}
	else
		while (rev_rot > 0 || test)
		{
			test = 0;
			rev_rot--;
			rra(e);
			ft_putendl("rra");
			if_display(e, 1);
		}
}

void	tri_aa(t_e *e)
{
	t_list_cir *tmp_b;
	t_list_cir *tmp_a_next;
	t_list_cir *tmp_a_previous;

	tmp_b = e->l_b->next;
	while (tmp_b != e->l_b)
	{
		tmp_a_next = e->l_a->next;
		tmp_a_previous = e->l_a->previous;
		if ((tmp_b->n < tmp_a_next->n && tmp_b->n > tmp_a_previous->n) ||
				(tmp_b->n > tmp_a_next->n && tmp_b->n > tmp_a_previous->n
				&& tmp_a_next->n < tmp_a_previous->n) ||
				(tmp_b->n < tmp_a_next->n && tmp_b < tmp_a_previous
				&& tmp_a_next->n < tmp_a_previous->n))
		{
			pa(e);
			ft_putendl("pa");
			e->size_l++;
			if_display(e, 1);
			tmp_b = e->l_b->next;
		}
		else
			tri_aa_else(e, tmp_b, tmp_a_next, tmp_a_previous);
	}
}

void	after_tri_aa(t_e *e)
{
	t_list_cir	*tmp_a_next;
	t_list_cir	*tmp_a_previous;

	tmp_a_next = e->l_a->next;
	tmp_a_previous = e->l_a->previous;
	e->rot = what_ratation2a(tmp_a_next, tmp_a_previous);
	e->rev_rot = e->size_l - e->rot;
	while (tmp_a_next->n > tmp_a_previous->n)
	{
		if (e->rot <= e->rev_rot)
		{
			ra(e);
			ft_putendl("ra");
			if_display(e, 1);
		}
		else
		{
			rra(e);
			ft_putendl("rra");
			if_display(e, 1);
		}
		tmp_a_next = e->l_a->next;
		tmp_a_previous = e->l_a->previous;
	}
}
