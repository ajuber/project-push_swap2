/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 05:50:31 by ajubert           #+#    #+#             */
/*   Updated: 2016/06/25 17:12:50 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_to_min(t_e *e)
{
	if (e->rot < e->rev_rot)
	{
		while (e->rot > 0)
		{
			e->rot--;
			ra(e);
			ft_putendl("ra");
			if_display(e, 1);
		}
	}
	else
	{
		while (e->rev_rot > 0)
		{
			e->rev_rot--;
			rra(e);
			ft_putendl("rra");
			if_display(e, 1);
		}
	}
}

/*void	search_min(t_e *e)
{
	t_list_cir	*tmp;
	t_list_cir	*tmp_min;
	int			i;

	e->rot = 0;
	i = 0;
	tmp = e->l_a->next;
	tmp_min = tmp;
	while (tmp != e->l_a)
	{
		if (tmp->n < tmp_min->n)
		{
			tmp_min = tmp;
			e->rot = i;
		}
		tmp = tmp->next;
		i++;
	}
	e->rev_rot = e->size_l - e->rot;
	rot_to_min(e);
}*/

void	search_med(t_e *e, int med)
{
	t_list_cir	*tmp;
	//t_list_cir	*tmp_min;
	int			i;

	e->rot = 0;
	i = 0;
	tmp = e->l_a->next;
	while (tmp != e->l_a)
	{
		if (tmp->n == med)
		{
			//tmp_min = tmp;
			e->rot = i;
		}
		tmp = tmp->next;
		i++;
	}
	e->rev_rot = e->size_l - e->rot;
	rot_to_min(e);
}

t_list_cir	*search_merge_pivot_rev(t_e *e, int med, int min)
{
	t_list_cir	*tmp;
	t_list_cir	*tmp_merge;
	t_list_cir	*tmp_med;
	//t_list_cir	*tmp_min;

	tmp = e->l_a->next;
	while (tmp != e->l_a && (tmp->n < med || tmp->n > med))
		tmp = tmp->next;
	tmp_med = tmp;
	while ((tmp->n <= med && tmp->n >= min) || tmp == e->l_a->next)
		tmp = tmp->previous;
	tmp = tmp->next;
	tmp_merge = tmp;
	return (tmp_merge);
}

t_list_cir	*search_merge_pivot(t_e *e, int med)
{
	t_list_cir	*tmp;
	t_list_cir	*tmp_merge;
	t_list_cir	*tmp_med;
	//t_list_cir	*tmp_min;

	tmp = e->l_a->next;
	while (tmp != e->l_a && (tmp->n < med || tmp->n > med))
		tmp = tmp->next;
	tmp_med = tmp;
	while (tmp->n <= med || tmp == e->l_a->next)
		tmp = tmp->next;
	tmp_merge = tmp;
	return (tmp_merge);
}

int		*create_tab_tri(t_e *e)
{
	int			*tab;
	t_list_cir	*tmp;
	int			i;
	int			min;
	int			pos_i;

	if (!(tab = (int *)malloc(sizeof(int) * e->size_l)))
		return (NULL);
	i = 0;
	tmp = e->l_a->next;
	while (tmp != e->l_a)
	{
		tab[i] = tmp->n;
		i++;
		tmp = tmp->next;
	}
	i = 0;
	while (i < e->size_l)
	{
		e->j = i + 1;
		pos_i = i;
		while (e->j < e->size_l)
		{
			if (tab[e->j] < tab[pos_i])
				pos_i = e->j;
			e->j++;
		}
		min = tab[pos_i];
		tab[pos_i] = tab[i];
		tab[i] = min;
		i++;
	}
	return (tab);
}

void	resolv_rev(t_e *e, int *tab, int case_med, int case_min)
{
	int			med;
	int			min;
	t_list_cir	*tmp;
	int			i;
	t_list_cir	*tmp_merge;
	int static	test = 1;

	med = tab[case_med];
	min = tab[case_min];
	if (med > min)
	{
		tmp = e->l_a->next;
		tmp_merge = search_merge_pivot_rev(e, med, min);
		i = -1;
		while (tmp != e->l_a)
		{
			i++;
			if (tmp->n >= min && tmp->n < med)
			{
				search_med(e, tmp->n);
				pb(e);
				ft_putendl("pb");
				tmp = e->l_a;
				if_display(e, 1);
				e->size_l--;
				i = -1;
			}
			tmp = tmp->next;
		}
		search_med(e, med);
		pb(e);
		ft_putendl("pb");
		if_display(e, 1);
		e->size_l--;
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
		if ((case_med > case_min) && ((((case_med - case_min) / 2 + case_min) < case_med - 1 || test)))
		{
			if (((case_med - case_min) / 2 + case_min) == case_med - 1)
				test = 0;
			(resolv_rev(e, tab, case_med , (case_med - case_min) / 2 + case_min));
			test = 1;
			(resolv_rev(e, tab, (case_med - case_min) / 2 + case_min, case_min));
		}
	}
}

void	resolv(t_e *e, int *tab, int case_med, int case_min)
{
	int			med;
	int			min;
	t_list_cir	*tmp;
	int			i;
	t_list_cir	*tmp_merge;
	int static	test = 1;

	med = tab[case_med];
	min = tab[case_min];
	if (med > min)
	{
		tmp = e->l_a->next;
		tmp_merge = search_merge_pivot(e, med);
		i = -1;
		while (tmp != e->l_a)
		{
			i++;
			if (tmp->n >= min && tmp->n < med)
			{
				search_med(e, tmp->n);
				pb(e);
				ft_putendl("pb");
				tmp = e->l_a;
				if_display(e, 1);
				e->size_l--;
				i = -1;
			}
			tmp = tmp->next;
		}
		search_med(e, med);
		pb(e);
		ft_putendl("pb");
		if_display(e, 1);
		e->size_l--;
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
		if ((case_med > case_min) && ((((case_med - case_min) / 2 + case_min) < case_med - 1 || test)))
		{
			if (((case_med - case_min) / 2 + case_min) == case_med - 1)
				test = 0;
			(resolv(e, tab, case_med , (case_med - case_min) / 2 + case_min));
			test = 1;
			(resolv(e, tab, (case_med - case_min) / 2 + case_min, case_min));
		}
	}
}

int		push_swap_calc(t_e *e)
{
//	t_list_cir	*tmp;
	int			*tab;
//	int			i;

//	i = 0;
	if (test_small_list(e))
		return (1);
	/*while (e->size_l > 0)
	{
		search_min(e);
		pb(e);
		e->size_l--;
		ft_putendl("pb");
		if_display(e, 1);
	}
	tmp = e->l_b->next;
	while (tmp != e->l_b)
	{
		pa(e);
		ft_putendl("pa");
		if_display(e, 1);
		tmp = e->l_b->next;
	}*/
	tab = create_tab_tri(e);
	if (tab == NULL)
		return (0);
	resolv_rev(e, tab, e->size_l - 1, ((e->size_l - 1) / 2) + ((e->size_l - 1) / 4));
	resolv_rev(e, tab, ((e->size_l - 1) / 2) + ((e->size_l - 1) / 4), (e->size_l - 1) / 2);
	resolv(e, tab, (e->size_l - 1) / 2, 0);
	return (1);
}
