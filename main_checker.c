/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 23:26:40 by ajubert           #+#    #+#             */
/*   Updated: 2016/06/22 18:49:45 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_cir		*ft_create_list1(char **argv, t_e *e, int argc)
{
	int		i;

	i = 1;
	if (!(e->l_a = ft_create_racine()))
		return (NULL);
	while (i < argc)
	{
		e->j = 0;
		if (argv[i][e->j] == '\0')
			return (NULL);
		while (argv[i][e->j])
		{
			if (!(ft_isdigit(argv[i][e->j])))
				return (NULL);
			e->j++;
		}
		e->nb = ft_atoi_long(argv[i]);
		if (e->nb < -2147483648 || e->nb > 2147483647)
			return (NULL);
		push_back_list(e->l_a, e->nb);
		i++;
	}
	e->size_l = i - 1 - e->v;
	return (e->l_a);
}

int				ft_check_doublon1(t_e *e)
{
	t_list_cir *tmp;
	t_list_cir *tmp1;

	tmp = e->l_a->next;
	while (tmp != e->l_a)
	{
		tmp1 = tmp->next;
		while (tmp1 != e->l_a)
		{
			if (tmp->n == tmp1->n)
				return (0);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int			checker_calc(t_e *e)
{
	char	*line;

	while (get_next_line(0, &line) != 0)
	{
		if (ft_strcmp("sa", line) == 0)
			sa(e);
		else if (ft_strcmp("sb", line) == 0)
			sb(e);
		else if (ft_strcmp("ss", line) == 0)
			ss(e);
		else if (ft_strcmp("ra", line) == 0)
			ra(e);
		else if (ft_strcmp("rb", line) == 0)
			rb(e);
		else if (ft_strcmp("rr", line) == 0)
			rr(e);
		else if (ft_strcmp("rra", line) == 0)
			rra(e);
		else if (ft_strcmp("rrb", line) == 0)
			rrb(e);
		else if (ft_strcmp("rrr", line) == 0)
			rrr(e);
		else if (ft_strcmp("pa", line) == 0)
			pa(e);
		else if (ft_strcmp("pb", line) == 0)
			pb(e);
		else
		{
			ft_putendl_fd("Error", 2);
			ft_memdel((void **)&line);
			return (0);
		}
		ft_memdel((void **)&line);
	}
	return (1);
}

void			checker_resolv(t_e *e)
{
	t_list_cir	*tmp;
	int			nbr;

	if (e->l_b->next != e->l_b && e->l_b->previous != e->l_b)
	{
		ft_putendl("KO");
		return ;
	}
	tmp = e->l_a->next;
	nbr = tmp->n;
	tmp = tmp->next;
	while (tmp != e->l_a)
	{
		if (nbr > tmp->n)
		{
			ft_putendl("KO");
			return ;
		}
		tmp = tmp->next;
	}
	ft_putendl("OK");
}

int				main(int argc, char **argv)
{
	t_e		e;

	if (argc == 1)
		return (0);
	e.l_a = ft_create_list1(argv, &e, argc);
	e.l_b = ft_create_racine();
	if (e.l_a == NULL || e.l_b == NULL || (!(ft_check_doublon1(&e))))
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	if (!(checker_calc(&e)))
		return (1);
	checker_resolv(&e);
	ft_free_list_cir(e.l_a);
	ft_free_list_cir(e.l_b);
	return (0);
}
