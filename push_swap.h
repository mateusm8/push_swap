/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:56:43 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/26 16:00:01 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_lstnew(int data);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
char	**ft_split(const char *s, char c);
long	ft_atol(const char *str);
int		check_number(char *str);
int		check_equal(t_stack *stack_a, t_stack *node);
long	check_min_max(char *str);
int		ft_printnumber(int nb);
int		ft_printaddress(unsigned long int nb);
int		ft_printundec(unsigned int nb);
int		ft_printhex(unsigned int nb, int s);
int		ft_printstr(char *str);
int		ft_printchar(char c);
int		ft_type_check(char c, va_list *lst_args, long int num, int len);
int		ft_printf(const char *format, ...);
void	sa(t_stack *node);
void	sb(t_stack *node);
void	ss(t_stack *node1, t_stack *node2);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *node);
void	rb(t_stack *node);
void	rr(t_stack *node1, t_stack *node2);
void	rra(t_stack *node);
void	rrb(t_stack *node);
void	rrr(t_stack *node1, t_stack *node2);

#endif
