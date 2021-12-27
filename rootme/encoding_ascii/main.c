/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:54:39 by youness           #+#    #+#             */
/*   Updated: 2021/05/06 15:04:32 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_get_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

int main()
{
	char	c;
	char	buffer[1024];

	scanf("%s", buffer);
	for (int i = 0; buffer[i]; i++)
	{
		if (i % 2)
		{
			c += ft_get_index("0123456789ABCDEF", buffer[i]);
			printf("%c", c);
		}
		else
			c = ft_get_index("0123456789ABCDEF", buffer[i]) * 16;
	}
	return (0);
}
