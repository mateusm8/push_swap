/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:35:07 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/26 16:03:21 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *node)
{
	int	tmp;

	if (node == NULL || node->next == NULL)
		return ;
	tmp = node->data;
	node->data = node->next->data;
	node->next->data = tmp;
}

void	sa(t_stack *node)
{
	swap(node);
	ft_printf("sa\n");
}

void	sb(t_stack *node)
{
	swap(node);
	ft_printf("sb\n");
}

void	ss(t_stack *node1, t_stack *node2)
{
	sa(node1);
	sb(node2);
}
