/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 15:15:08 by ajubert           #+#    #+#             */
/*   Updated: 2016/06/22 18:23:26 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_a(t_e *e, int nb_rot, int nb_rot_rev)
{
	if (nb_rot <= nb_rot_rev)
	{
		while (nb_rot-- > 0)
		{
			ra(e);
			ft_putendl("ra");
			if_display(e, 1);
		}
	}
	else
	{
		while (nb_rot_rev-- > 0)
		{
			rra(e);
			ft_putendl("rra");
			if_display(e, 1);
		}
	}
}

int		test_to_tri_a(t_e *e, int *nb_rot_rev, int comp, t_list_cir **tmp)
{
	int			max;
	t_list_cir	*tmp1;

	*nb_rot_rev = 1;
	tmp1 = e->l_a->next;
	max = tmp1->n;
	comp = tmp[0]->n;
	tmp[0] = tmp[0]->next;
	if (comp < max)
	{
		while (tmp[0] != e->l_a && comp < tmp[0]->n && tmp[0]->n < max)
		{
			comp = tmp[0]->n;
			tmp[0] = tmp[0]->next;
			*nb_rot_rev += 1;
		}
		return (1);
	}
	return (0);
}

int		test_a(t_e *e)
{
	t_list_cir	*tmp;
	int			comp;
	int			nb_rot;
	int			nb_rot_rev;

	nb_rot = 1;
	tmp = e->l_a->next;
	comp = tmp->n;
	tmp = tmp->next;
	while (tmp != e->l_a && comp < tmp->n)
	{
		nb_rot++;
		comp = tmp->n;
		tmp = tmp->next;
	}
	if (tmp == e->l_a)
		return (1);
	if (!test_to_tri_a(e, &nb_rot_rev, comp, &tmp))
		return (0);
	if (tmp == e->l_a)
	{
		tri_a(e, nb_rot, nb_rot_rev);
		return (1);
	}
	return (0);
}
