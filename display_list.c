/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 07:01:21 by ajubert           #+#    #+#             */
/*   Updated: 2016/05/06 15:22:32 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_list(t_e *e, int n)
{
	t_list_cir *tmp_a;
	t_list_cir *tmp_b;

	tmp_a = e->l_a->previous;
	ft_putstr("a :");
	while (tmp_a != e->l_a)
	{
		ft_putchar(' ');
		ft_putnbr(tmp_a->n);
		tmp_a = tmp_a->previous;
	}
	tmp_b = e->l_b->previous;
	ft_putstr("\nb :");
	while (tmp_b != e->l_b)
	{
		ft_putchar(' ');
		ft_putnbr(tmp_b->n);
		tmp_b = tmp_b->previous;
	}
	if (n == 1)
		ft_putstr("\n\n");
	else
		ft_putchar('\n');
}

void	if_display(t_e *e, int n)
{
	if (e->v)
		display_list(e, n);
}
