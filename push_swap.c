/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:58:51 by isromero          #+#    #+#             */
/*   Updated: 2022/11/29 16:21:36 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ispace(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		
		if (str[i] == ' ')
			return ;
		i++;
	}
	(printf("%s", "No hay espacio crack\n"));
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
	printf("%s", "Ni de coña\n");
}

int	good_input(int argc, char **argv)
{
	int	i;
	int ret;

	ret = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_ispace(argv[i]))
		{
			ft_isdigit(argv[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

int main(int argc, char **argv)
{
	good_input(argc, argv);
	return (0);
}