/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:03:42 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/28 22:04:06 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack	**node)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*node || !(*node)->next)
		return ;
	tmp = ft_lstlast(*node);
	tmp2 = (*node)->next;
	tmp->next = *node;
	(*node)->next = NULL;
	*node = tmp2;
}

void	ra(t_stack **node)
{
	rotate(node);
	ft_printf("ra\n");
}

void	rb(t_stack **node)
{
	rotate(node);
	ft_printf("rb\n");
}

void	rr(t_stack **node1, t_stack **node2)
{
	rotate(node1);
	rotate(node2);
	ft_printf("rr\n");
}
