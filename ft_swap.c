/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 02:47:13 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/24 06:30:06 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_e *e)
{
	t_list_cir	*tmp_a;
	int			tmp;
	int			tmp1;

	tmp_a = e->l_a->next;
	if (e->l_a != tmp_a && e->l_a != tmp_a->next)
	{
		tmp = tmp_a->n;
		tmp_a = tmp_a->next;
		tmp1 = tmp_a->n;
		tmp_a->n = tmp;
		tmp_a = tmp_a->previous;
		tmp_a->n = tmp1;
	}
}

void	sb(t_e *e)
{
	t_list_cir	*tmp_a;
	int			tmp;
	int			tmp1;

	tmp_a = e->l_b->next;
	if (e->l_b != tmp_a && e->l_b != tmp_a->next)
	{
		tmp = tmp_a->n;
		tmp_a = tmp_a->next;
		tmp1 = tmp_a->n;
		tmp_a->n = tmp;
		tmp_a = tmp_a->previous;
		tmp_a->n = tmp1;
	}
}

void	ss(t_e *e)
{
	sa(e);
	sb(e);
}
