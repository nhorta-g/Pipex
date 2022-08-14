/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunograzina <nunograzina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:22:44 by nhorta-g          #+#    #+#             */
/*   Updated: 2022/08/12 10:43:34 by nunograzina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!str1 || !str2)
		return (-1);
	i = -1;
	while (str1[++i] && str2[i] && i < n)
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	if (i < n)
		return (str1[i] - str2[i]);
	return (0);
}
