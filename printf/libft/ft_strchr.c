/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:48:30 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/11/18 10:46:07 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!c)
		return ((char *)(s + ft_strlen(s)));
	while (s[i] && s[i] != (char)c)
		i++;
	if (!c)
		return ((char *)(s + i));
	if (s[i] == '\0')
		return (NULL);
	return ((char *)(s + i));
}
