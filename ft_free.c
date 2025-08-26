/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:47:06 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/26 19:37:25 by matmagal         ###   ########.fr       */
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

int	ft_all(t_stack **stack, t_stack *node, char **str)
{
	free_list(stack);
	ft_free_str(str);
	free(node);
	return (ft_printf("Error\n"));
}