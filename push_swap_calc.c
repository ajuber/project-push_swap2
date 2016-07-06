/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_calc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 05:50:31 by ajubert           #+#    #+#             */
/*   Updated: 2016/07/06 16:41:03 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_to_min(t_e *e, int rot)
{
	if (rot == 1)
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
	else
	{
		if (e->rot_1 < e->rev_rot_1)
		{
			while (e->rot_1 > 0)
			{
				e->rot_1--;
				ra(e);
				ft_putendl("ra");
				if_display(e, 1);
			}
		}
		else
		{
			while (e->rev_rot_1 > 0)
			{
				e->rev_rot_1--;
				rra(e);
				ft_putendl("rra");
				if_display(e, 1);
			}
		}
	}
}

void	search_pivot(t_e *e, t_pivot *pivot, int min)
{
	t_list_cir	*tmp;
	t_list_cir	*tmp_next;
	int			i;

	pivot->rot_a = 0;
	i = 0;
	tmp = e->l_a->next;
	while (tmp != e->l_a)
	{
		if (tmp->n == min)
		{
			//tmp_min = tmp;
			pivot->rot_a = i;
		}
		tmp = tmp->next;
		i++;
	}
	i = 0;
	pivot->rev_rot_a = e->size_l - pivot->rot_a;
	tmp = e->l_b->next;
	tmp_next = e->l_b->previous;
	if (tmp == e->l_b)
	{
		pivot->rot_b = 0;
		pivot->rev_rot_b = 0;
		return ;
	}
	while (tmp != e->l_b)
	{
		if (tmp->n < min && tmp_next->n > min)
			pivot->rot_b = i;
		tmp = tmp->next;
		tmp_next = e->l_b->previous;
		i++;
	}
	pivot->rev_rot_b = e->size_lb - pivot->rot_b;
	if (pivot->rot_a <= pivot->rot_b)
	{
		pivot->rrot = pivot->rot_a;
		pivot->temp_rot_b = pivot->rot_b - pivot->rot_a;
		pivot->temp_rot_a = 0;
	}
	else
	{
		pivot->rrot = pivot->rot_b;
		pivot->temp_rot_a = pivot->rot_a - pivot->rot_b;
		pivot->temp_rot_b = 0;
	}
	pivot->nb_rot = pivot->temp_rot_a + pivot->temp_rot_b + pivot->rrot;
	if (pivot->rev_rot_a <= pivot->rev_rot_b)
	{
		pivot->rrevrot = pivot->rev_rot_a;
		pivot->temp_rev_rot_b = pivot->rev_rot_b - pivot->rev_rot_a;
		pivot->temp_rev_rot_a = 0;
	}
	else
	{
		pivot->rrevrot = pivot->rev_rot_b;
		pivot->temp_rev_rot_a = pivot->rev_rot_a - pivot->rev_rot_b;
		pivot->temp_rev_rot_b = 0;
	}
	pivot->nb_revrot = pivot->temp_rev_rot_a + pivot->temp_rev_rot_b + pivot->rrevrot;
	pivot->nb_rot_a_revrot_b = pivot->rot_a + pivot->rev_rot_b;
	pivot->nb_rot_b_revrot_a = pivot->rot_b + pivot->rev_rot_a;
	if (pivot->nb_revrot < pivot->nb_rot && pivot->nb_revrot < pivot->nb_rot_a_revrot_b && pivot->nb_revrot < pivot->nb_rot_b_revrot_a)
	{
		pivot->ind_rot = 4;
		pivot->nb_min_rot = pivot->nb_revrot;
	}
	else if (pivot->nb_rot < pivot->nb_revrot && pivot->nb_rot < pivot->nb_rot_b_revrot_a && pivot->nb_rot < pivot->nb_rot_a_revrot_b)
	{
		pivot->ind_rot = 3;
		pivot->nb_min_rot = pivot->nb_rot;
	}
	else if (pivot->nb_rot_b_revrot_a < pivot->nb_rot && pivot->nb_rot_b_revrot_a < pivot->nb_revrot && pivot->nb_rot_b_revrot_a < pivot->nb_rot_a_revrot_b)
	{
		pivot->ind_rot = 2;
		pivot->nb_min_rot = pivot->nb_rot_b_revrot_a;
	}
	else
	{
		pivot->ind_rot = 1;
		pivot->nb_min_rot = pivot->nb_rot_a_revrot_b;
	}
	//if (pivot->rot_1 <= e->rev_rot_1)
	//	return (e->rot_1);
//	return (e->rev_rot_1);
}

void	rotate_pl(t_pivot *pivot)
{
	if (pivot->ind_rot == 1 || pivot->ind_rot == 2)
	{
		pivot->rrot = 0;
		pivot->rrevrot = 0;
		if (pivot->ind_rot == 1)
		{
			pivot->rev_rot_a = 0;
			pivot->rot_b = 0;
		}
		if (pivot->ind_rot == 2)
		{
			pivot->rot_a = 0;
			pivot->rev_rot_b = 0;
		}
	}
	if (pivot->ind_rot == 3)
	{
		pivot->rot_a = pivot->temp_rot_a;
		pivot->rot_b = pivot->temp_rot_b;
		pivot->rrevrot = 0;
		pivot->rev_rot_a = 0;
		pivot->rev_rot_b = 0;
	}
	if (pivot->ind_rot == 4)
	{
		pivot->rev_rot_a = pivot->temp_rev_rot_a;
		pivot->rev_rot_b = pivot->temp_rev_rot_b;
		pivot->rrot = 0;
		pivot->rot_a = 0;
		pivot->rot_b = 0;
	}
}

void	rotate_to(t_e *e, t_pivot *pivot)
{
	while (pivot->rot_a > 0)
	{
		ra(e);
		ft_putendl("ra");
		if_display(e, 1);
		pivot->rot_a--;
	}
	while (pivot->rot_b > 0)
	{
		rb(e);
		ft_putendl("rb");
		if_display(e, 1);
		pivot->rot_b--;
	}
	while (pivot->rev_rot_a > 0)
	{
		rra(e);
		ft_putendl("rra");
		if_display(e, 1);
		pivot->rev_rot_a--;
	}
	while (pivot->rev_rot_b > 0)
	{
		rrb(e);
		ft_putendl("rrb");
		if_display(e, 1);
		pivot->rev_rot_b--;
	}
	while (pivot->rrot > 0)
	{
		rr(e);
		ft_putendl("rr");
		if_display(e, 1);
		pivot->rrot--;
	}
	while (pivot->rrevrot > 0)
	{
		rrr(e);
		ft_putendl("rrr");
		if_display(e, 1);
		pivot->rrevrot--;
	}
}

void	rotation_min(t_e *e)
{
	if (e->piv_1.nb_min_rot < e->piv_2.nb_min_rot && e->piv_1.nb_min_rot < e->piv_3.nb_min_rot && e->piv_1.nb_min_rot < e->piv_4.nb_min_rot)
	{
		rotate_pl(&e->piv_1);
		rotate_to(e, &e->piv_1);
		e->piv_1.pos_min++;
	}
	else if (e->piv_2.nb_min_rot < e->piv_1.nb_min_rot && e->piv_2.nb_min_rot < e->piv_3.nb_min_rot && e->piv_2.nb_min_rot < e->piv_4.nb_min_rot)
	{
		rotate_pl(&e->piv_2);
		rotate_to(e, &e->piv_2);
		e->piv_2.pos_min++;
	}
	else if (e->piv_3.nb_min_rot < e->piv_1.nb_min_rot && e->piv_3.nb_min_rot < e->piv_2.nb_min_rot && e->piv_3.nb_min_rot < e->piv_4.nb_min_rot)
	{
		rotate_pl(&e->piv_3);
		rotate_to(e, &e->piv_3);
		e->piv_3.pos_min++;
	}
	else
	{
		rotate_pl(&e->piv_4);
		rotate_to(e, &e->piv_4);
		e->piv_4.pos_min++;
	}
}

/*int		search_med_next(t_e *e, int med)
{
	t_list_cir	*tmp;
	//t_list_cir	*tmp_min;
	int			i;

	e->rot_1 = 0;
	i = 0;
	tmp = e->l_a->next;
	while (tmp != e->l_a)
	{
		if (tmp->n == med)
		{
			//tmp_min = tmp;
			e->rot_1 = i;
		}
		tmp = tmp->next;
		i++;
	}
	e->rev_rot_1 = e->size_l - e->rot_1;
	if (e->rot_1 <= e->rev_rot_1)
		return (e->rot_1);
	return (e->rev_rot_1);
}*/

int		search_med(t_e *e, int med)
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
	if (e->rot <= e->rev_rot)
		return (e->rot);
	return (e->rev_rot);
}

void	search_min(t_e *e)
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
}

/*void	search_med(t_e *e, int med)
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
}*/

/*t_list_cir	*search_merge_pivot_rev(t_e *e, int med, int min)
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
}*/

/*t_list_cir	*search_merge_pivot(t_e *e, int med)
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
}*/

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

/*void	resolv_rev(t_e *e, int *tab, int case_med, int case_min)
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
		//if (!(test_bloc_tri(e, med, min, e->size_lb)))
		//{
			tmp = e->l_a->next;
			tmp_merge = search_merge_pivot_rev(e, med, min);
			//if (e->size_lb <= 3)
			//{
		//		tri_small_bloc(e, tmp_merge, tab, case_med, case_min);
	//		}
	//		else
	//		{
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
				if (((case_med > case_min) && ((((case_med - case_min) / 2 + case_min) < case_med - 1) || test)))
				{
					if (((case_med - case_min) / 2 + case_min) == case_med - 1)
						test = 0;
					(resolv_rev(e, tab, case_med , (case_med - case_min) / 2 + case_min));
					test = 1;
					(resolv_rev(e, tab, (case_med - case_min) / 2 + case_min, case_min));
				}
	//		}
	//	}
	}
}*/

/*void	resolv(t_e *e, int *tab, int case_med, int case_min)
{
	int			med;
	int			min;
	t_list_cir	*tmp;
	int			i;
	t_list_cir	*tmp_merge;
	int static	test = 1;

	med = tab[case_med];
	min = tab[case_min];
	e->size_lb = med - min + 1;
	if (med > min)
	{
	//	if (!(test_bloc_tri(e, med, min, e->size_lb)))
	//	{
			tmp = e->l_a->next;
			tmp_merge = search_merge_pivot(e, med);
	//		if (e->size_lb <= 3)
	//			tri_small_bloc(e, tmp_merge, tab, case_med, case_min);
	//		else
	//		{
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
				if (((case_med > case_min) && ((((case_med - case_min) / 2 + case_min) < case_med - 1) || test)))
				{
					if (((case_med - case_min) / 2 + case_min) == case_med - 1)
						test = 0;
					(resolv(e, tab, case_med , (case_med - case_min) / 2 + case_min));
					test = 1;
					(resolv(e, tab, (case_med - case_min) / 2 + case_min, case_min));
				}
	//		}
	//	}
		i = -1;
	}
}*/

int		push_swap_calc(t_e *e)
{
	t_list_cir	*tmp;
//	t_list_cir	*tmp1;
//	t_list_cir	*tmp_next;
	int			*tab;
//	int			i;
//	int			case_med;
//	int			case_next;
	//int			rot;
	//int			rot_min_next;
	int			size_la;
//	i = 0;
	if (test_small_list(e))
		return (1);
	tab = create_tab_tri(e);
	if (tab == NULL)
		return (0);
	size_la = e->size_l;
	//case_med = (e->size_l - 1) / 2;
	//case_next = case_med + 1;
	e->piv_1.pos_min = 0;
	e->piv_1.pos_max = (size_la - 1) / 4;
	e->piv_2.pos_min = ((size_la - 1) / 4) + 1;
	e->piv_2.pos_max = ((size_la - 1) / 2);
	e->piv_3.pos_min = ((size_la - 1) / 2) + 1;
	e->piv_3.pos_max = ((size_la - 1) / 2) + ((size_la - 1) / 4);
	e->piv_4.pos_min = ((size_la - 1) / 2) + ((size_la - 1) / 4) + 1;
	e->piv_4.pos_max = size_la - 1;
	while (e->size_l > 0)
	{
		/*if (case_med >= 0)
			rot = search_med(e, tab[case_med]);
		else
			rot = -1;
		if (case_next < size_la)
			rot_min_next = search_med_next(e, tab[case_next]);
		else
			rot_min_next = -1;
		if ((rot_min_next != -1 && rot_min_next < rot + 2) || rot == -1)
		{
			case_next++;
			rot_to_min(e, 2);
		}
		else
		{
			case_med--;
			rot_to_min(e, 1);
		}
		tmp = e->l_b->next;
		tmp_next = tmp->next;
		tmp1 = e->l_a->next;
		if (tmp->n < tmp_next->n)
		{
			rb(e);
			ft_putendl("rb");
			if_display(e, 1);
		}*/
		if (e->piv_1.pos_min <= e->piv_1.pos_max)
			search_pivot(e, &e->piv_1, tab[e->piv_1.pos_min]);
		else
			e->piv_1.nb_min_rot = 2 * size_la;
		if (e->piv_2.pos_min <= e->piv_2.pos_max)
			search_pivot(e, &e->piv_2, tab[e->piv_2.pos_min]);
		else
			e->piv_2.nb_min_rot = 2 * size_la;
		if (e->piv_3.pos_min <= e->piv_3.pos_max)
			search_pivot(e, &e->piv_3, tab[e->piv_3.pos_min]);
		else
			e->piv_3.nb_min_rot = 2 * size_la;
		if (e->piv_4.pos_min <= e->piv_4.pos_max)
			search_pivot(e, &e->piv_4, tab[e->piv_4.pos_min]);
		else
			e->piv_4.nb_min_rot = 2 * size_la;
		rotation_min(e);
		pb(e);
		e->size_l--;
		e->size_lb++;
		ft_putendl("pb");
		if_display(e, 1);
	}
	tmp = e->l_b->next;
	e->rot = 0;
	while (tmp->n != tab[0])
	{
		e->rot++;
		tmp = tmp->next;
	}
	e->rev_rot = e->size_lb - e->rot;
	//tmp_next = tmp->next;
	if (e->rot <= e->rev_rot)
		while (e->rot > 0)
		{
			e->rot--;
			rb(e);
			ft_putendl("rb");
			if_display(e, 1);
		}
	else
		while (e->rev_rot > 0)
		{
			e->rev_rot--;
			rrb(e);
			ft_putendl("rrb");
			if_display(e, 1);
		}
	tmp = e->l_b->next;
	while (tmp != e->l_b)
	{
		pa(e);
		ft_putendl("pa");
		if_display(e, 1);
		tmp = e->l_b->next;
	}
//	resolv_rev(e, tab, e->size_l - 1, ((e->size_l - 1) / 2) + ((e->size_l - 1) / 4));
//	resolv_rev(e, tab, ((e->size_l - 1) / 2) + ((e->size_l - 1) / 4), (e->size_l - 1) / 2);
//	resolv(e, tab, (e->size_l - 1) / 2, 0);
	return (1);
}
