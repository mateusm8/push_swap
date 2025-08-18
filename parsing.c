/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:56:07 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/18 23:12:38 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_equal(t_stack *stack_a, t_stack *node)
{
	t_stack	*tmp;
	
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->data == node->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

long	check_min_max(char *str)
{
	long	c;

	c = ft_atol(str);
	if (c < INT_MIN || c > INT_MAX)
		return (0);
	return (1);
}