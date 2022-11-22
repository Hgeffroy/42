/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:45:45 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/11/10 17:26:41 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	n;

	if (size > 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	n = nmemb * size;
	res = malloc(n);
	if (!res)
		return (NULL);
	ft_bzero(res, n);
	return (res);
}
