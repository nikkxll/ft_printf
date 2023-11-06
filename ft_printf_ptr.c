/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:07:22 by dnikifor          #+#    #+#             */
/*   Updated: 2023/11/06 15:50:41 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_char_cpy(char *dest, char src, int *position)
{
	dest[(*position)++] = src;
}

static int	ft_hex_len(unsigned long long int nb)
{
	int	i;

	i = 1;
	while (nb > 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}


static void	ft_ptr_puthex(char *str, unsigned long long int nb, int *position)
{
	char const	*charset;

	charset = "0123456789abcdef";
	if (nb < 16)
	{
		ft_char_cpy(str, charset[nb], position);
	}
	else
	{
		ft_ptr_puthex(str, nb / 16, position);
		ft_char_cpy(str, charset[nb % 16], position);
	}
}

char	*ft_ptr_to_hex(void *ptr)
{
	unsigned long long int	ptr_val;
	char					*str;
	int						len;
	int						position;

	ptr_val = (unsigned long long int)ptr;
	position = 2;
	len = ft_hex_len(ptr_val);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	ft_ptr_puthex(str, ptr_val, &position);
	str[position] = '\0';
	return (str);
}

// int main() {
//     void *ptr = (void*)"derfefred";
// 	char *str;
//     str = ft_ptr_to_hex(ptr);
//     printf("%p", ptr);

//     return 0;
// }