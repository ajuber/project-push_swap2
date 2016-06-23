/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 23:39:30 by ajubert           #+#    #+#             */
/*   Updated: 2016/04/24 07:26:55 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_cir		*ft_create_racine(void)
{
	t_list_cir		*racine;

	if (!(racine = malloc(sizeof(t_list_cir))))
		return (NULL);
	racine->previous = racine;
	racine->next = racine;
	return (racine);
}

t_list_cir		*new_list_cir(t_list_cir *racine, int nb)
{
	t_list_cir *new;

	if (!(new = (t_list_cir *)malloc(sizeof(t_list_cir))))
		return (NULL);
	new->next = racine;
	new->previous = racine;
	new->n = nb;
	return (new);
}

t_list_cir		*push_back_list(t_list_cir *begin_list, int nb)
{
	t_list_cir *new;
	t_list_cir *tmp;

	new = new_list_cir(begin_list, nb);
	if (begin_list->previous == begin_list && begin_list->next == begin_list)
		begin_list->next = new;
	else
	{
		tmp = begin_list->previous;
		tmp->next = new;
		new->previous = tmp;
	}
	begin_list->previous = new;
	return (begin_list);
}

void			ft_free_list_cir(t_list_cir *begin_list)
{
	t_list_cir *tmp;
	t_list_cir *tmp1;

	tmp1 = begin_list->next;
	while (tmp1 != begin_list)
	{
		tmp = tmp1;
		tmp1 = tmp1->next;
		ft_memdel((void **)&tmp);
	}
	ft_memdel((void **)&begin_list);
	tmp1 = NULL;
}
