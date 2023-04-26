/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:29:10 by isromero          #+#    #+#             */
/*   Updated: 2023/04/26 10:37:00 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					p;
	int					n;
	unsigned int		res;

	p = 0;
	n = 1;
	res = 0;
	while ((str[p] >= 9 && str[p] <= 13) || (str[p] == 32))
		p++;
	if (str[p] == '+' || str[p] == '-')
	{
		if (str[p] == '-')
			n = n * -1;
		p++;
	}
	while (str[p] >= '0' && str[p] <= '9')
	{
		res = (str[p] - '0') + (res * 10);
		p++;
	}
	if (n == 1 && res > INT_MAX)
    {
        ft_putstr("Error\n");
        exit(1); // se retorna un valor indicando error
    }
    else if (n == -1 && res > INT_MAX)
    {
        ft_putstr("Error\n");
        exit(1);
    }
	return (res * n);
}