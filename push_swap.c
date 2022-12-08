/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:58:51 by isromero          #+#    #+#             */
/*   Updated: 2022/12/08 19:54:03 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (res > 2147483648 && n == -1)
		return (0);
	if (res > 2147483647 && n == 1)
		return (-1);
	return (res * n);
}

int	ft_ispace(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		
		if (str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_isdigit(const char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	
}

int	good_input(int argc, char **argv)
{
	int	i;
	int ret;

	i = 1;
	while (i < argc)
	{
		if (ft_ispace(argv[i]))
		{
			ft_isdigit(argv[i]);
			ft_atoi(argv[i]);
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		good_input(argc, argv);
	}
	return (0);
}