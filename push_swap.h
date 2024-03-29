/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 23:16:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/07/06 16:37:06 by ajubert          ###   ########.fr       */
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

typedef struct			s_pivot
{
	int					pos_min;
	int					pos_max;
	int					rot_a;
	int					temp_rot_a;
	int					rot_b;
	int					temp_rot_b;
	int					rev_rot_a;
	int					temp_rev_rot_a;
	int					rev_rot_b;
	int					temp_rev_rot_b;
	int					rrot;
	int					rrevrot;
	int					nb_rot_a_revrot_b;
	int					nb_rot_b_revrot_a;
	int					nb_rot;
	int					nb_revrot;
	int					ind_rot;
	int					nb_min_rot;
}						t_pivot;

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
	int					rot_1;
	int					rev_rot;
	int					rev_rot_1;
	t_pivot				piv_1;
	t_pivot				piv_2;
	t_pivot				piv_3;
	t_pivot				piv_4;
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
int						test_bloc_tri(t_e *e, int med, int min, int size);
void					tri_small_bloc(t_e *e, t_list_cir *tmp_merge, int *tab, int case_med, int case_min);
//void					search_med(t_e *e, int med);

#endif
