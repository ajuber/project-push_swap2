/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_small_bloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 17:30:13 by ajubert           #+#    #+#             */
/*   Updated: 2016/06/26 18:09:08 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_small_bloc(t_e *e, t_list_cir *tmp_merge, int *tab, int case_med, int case_min)
{
	t_list_cir	*tmp;
	int			i;

	i = 0;
	tmp = e->l_a->next;
	while (tmp != e->l_a)
	{
		if (tmp->n == tab[case_min + i] && tmp->n <= tab[case_med])
		{
			i++;
			search_med(e, tmp->n);
			pb(e);
			ft_putendl("pb");
			tmp = e->l_a;
			if_display(e, 1);
			e->size_l--;
		}
		tmp = tmp->next;
	}
	search_med(e, tmp_merge->n);
	tmp = e->l_b->next;
	while (tmp != e->l_b)
	{
		pa(e);
		ft_putendl("pa");
		tmp = e->l_b->next;
		if_display(e, 1);
		e->size_l++;
	}
}
