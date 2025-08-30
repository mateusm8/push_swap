/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:56:43 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/30 03:42:38 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_lstnew(int data);
t_stack	*ft_lstlast(t_stack *lst);
char	**ft_split(const char *s, char c);
long	ft_atol(const char *str);
long	check_min_max(char *str);
int		check_number(char *str);
int		ft_lstsize(t_stack *lst);
int		ordenate_checker(t_stack **stack_a);
int		min_data_position(t_stack **stack_a);
int		check_equal(t_stack *stack_a, t_stack *node);
void	sa(t_stack *node);
void	sb(t_stack *node);
void	ra(t_stack **node);
void	rb(t_stack **node);
void	rra(t_stack **node);
void	rrb(t_stack **node);
void	ft_free_str(char **str);
void	free_list(t_stack **node);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ordenate_index(t_stack **node);
void	ss(t_stack *node1, t_stack *node2);
void	rr(t_stack **node1, t_stack **node2);
void	rrr(t_stack **node1, t_stack **node2);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	radix_pass(t_stack **stack_a, t_stack **stack_b);
void	hard_coding(t_stack **stack_a, t_stack **stack_b);
void	ft_all(t_stack **stack, t_stack *node, char **str);

#endif
