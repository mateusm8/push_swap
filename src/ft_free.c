/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:47:06 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/30 03:38:29 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack **node)
{
	t_stack	*tmp;
	t_stack	*next;

	if (!node || !*node)
		return ;
	tmp = *node;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*node = NULL;
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_all(t_stack **stack, t_stack *node, char **str)
{
	if (stack && *stack)
		free_list(stack);
	if (str)
		ft_free_str(str);
	if (node)
		free(node);
	write(2, "Error\n", 6);
	exit (0);
}
