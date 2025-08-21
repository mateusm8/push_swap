/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matmagal <matmagal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:18:46 by matmagal          #+#    #+#             */
/*   Updated: 2025/08/21 17:29:05 by matmagal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printchar(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

static int	ft_type_check(char c, va_list *lst_args, long int num, int len)
{
	if (c == 'c')
		len += ft_printchar(va_arg(*lst_args, int));
	if (c == '%')
		len += write(1, "%", 1);
	if (c == 'd' || c == 'i')
		len += ft_printnumber(va_arg(*lst_args, int));
	if (c == 'u')
		len += ft_printundec(va_arg(*lst_args, unsigned int));
	if (c == 'x')
		len += ft_printhex(va_arg(*lst_args, unsigned int), 1);
	if (c == 'X')
		len += ft_printhex(va_arg(*lst_args, unsigned int), 2);
	if (c == 'p')
	{
		num = va_arg(*lst_args, long int);
		if (!num)
			return (ft_printstr("(nil)"));
		len += write(1, "0x", 2);
		len += ft_printaddress(num);
	}
	if (c == 's')
		len += ft_printstr(va_arg(*lst_args, char *));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	lst_args;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(lst_args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				len += ft_type_check(format[i], &lst_args, 0, 0);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(lst_args);
	return (len);
}

/*int	main(void)
{
	unsigned int	u;
	char			*str = "Mateus";
	const char		*teste = NULL;

	ft_printf("Criado: Meu nome e %s.\n", str);
	printf("Original: Meu nome e %s.\n\n", str);
	u = 16463464;
	ft_printf("Criado: O valor de u e %u.\n", u);
	printf("Original: O valor de u e %u.\n\n", u);
	ft_printf("Criado: A primeira letra do meu nome e %c.\n", str[0]);
	printf("Original: A primeira letra do meu nome e %c.\n\n", str[0]);
	ft_printf("Criado: O valor de u em hexadecimal e %x ou %X.\n", u, u);
	printf("Original: O valor de u em hexadecimal e %x ou %X.\n\n", u, u);
	ft_printf("Criado: O endereco de str e %p.\n", str);
	printf("Original: O endereco de str e %p.\n\n", str);
	ft_printf("Criado: Eu quero imprimir um %%.\n");
	printf("Original: Eu quero imprimir um %%.\n\n");
	ft_printf(teste, str);
	printf(teste, str);

	return (0);
}
*/