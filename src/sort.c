/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 01:23:14 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/31 12:14:45 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(*stack_a);
}

static void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;

	if (a > b && b < c && a < c)
		sa(*stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(*stack_a);
		ra(stack_a);
	}
}

static void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = min_data_position(stack_a);
	if (i == 2)
		sa(*stack_a);
	else if (i == 3)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (i == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = min_data_position(stack_a);
	if (i == 2)
		sa(*stack_a);
	else if (i == 3)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (i == 4)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (i == 5)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sort_two(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a))
		sort_five(stack_a, stack_b);
}
