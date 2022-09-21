/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhorta-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:24:02 by nhorta-g          #+#    #+#             */
/*   Updated: 2022/03/06 11:24:09 by nhorta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;
	char	*ned;

	i = 0;
	hay = (char *)haystack;
	ned = (char *)needle;
	if (!ned[i])
		return (&hay[i]);
	while (hay[i] && i < len)
	{
		j = 0;
		while (ned[j] && hay[i + j] == ned[j] && i + j < len)
			j++;
		if (!ned[j])
			return (&hay[i]);
		i++;
	}
	return (NULL);
}
