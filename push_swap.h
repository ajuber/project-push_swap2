/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 23:16:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/06/23 15:26:44 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct			s_list_cir
{
	int					n;
	struct s_list_cir	*previous;
	struct s_list_cir	*next;
}						t_list_cir;

typedef struct			s_e
{
	t_list_cir			*l_a;
	t_list_cir			*l_b;
	char				*str;
	int					v;
	int					size_l;
	int					size_lb;
	int					j;
	long				nb;
	int					rot;
	int					rev_rot;
}						t_e;

t_list_cir				*ft_create_racine(void);
t_list_cir				*push_back_list(t_list_cir *begin_list, int nb);
void					ft_free_list_cir(t_list_cir *begin_list);
void					pa(t_e *e);
void					pb(t_e *e);
void					sa(t_e *e);
void					sb(t_e *e);
void					ss(t_e *e);
void					ra(t_e *e);
void					rb(t_e *e);
void					rr(t_e *e);
void					rra(t_e *e);
void					rrb(t_e *e);
void					rrr(t_e *e);
int						push_swap_calc(t_e *e);
void					display_list(t_e *e, int n);
int						test_a(t_e *e);
int						tri_a_and_b(t_e *e);
void					tri_b_and_a(t_e *e);
void					if_display(t_e *e, int n);
int						test_swap_a(t_e *e);
void					tri_small_list(t_e *e);
int						test_small_list(t_e *e);
void					tri_aa(t_e *e);
void					after_tri_aa(t_e *e);
int						what_ratation(t_list_cir *tmp_a, t_list_cir *tmp_b_next,
		t_list_cir *tmp_b_previous);
int						what_ratation2(t_list_cir *tmp_b,
		t_list_cir *tmp_a_next, t_list_cir *tmp_a_previous);
int						what_ratation2a(t_list_cir *tmp_a_next,
		t_list_cir *tmp_a_previous);
int						what_ratation2b(t_e *e, t_list_cir *tmp_b_next,
		t_list_cir *tmp_b_previous);

#endif
