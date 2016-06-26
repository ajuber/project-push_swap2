/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bloc_tri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 15:39:51 by ajubert           #+#    #+#             */
/*   Updated: 2016/06/26 18:29:10 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		test_bloc_tri(t_e *e, int med, int min, int size)
{
	t_list_cir	*tmp;
	int			nb_previous;
	int			i;

	i = 1;
	tmp = e->l_a->next;
	while (tmp->n != min)
		tmp = tmp->next;
	nb_previous = tmp->n;
	tmp = tmp->next;
	while ((tmp->n > min && tmp->n <= med && tmp->n > nb_previous) || tmp == e->l_a)
	{
		if (tmp != e->l_a)
			i++;
		nb_previous = tmp->n;
		tmp = tmp->next;
	}
	if (i == size && nb_previous == med)
		return (1);
	return (0);
}
