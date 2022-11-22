/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:05:33 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/11/20 16:11:08 by hgeffroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	isbreak(char *buffer)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if ((!dest && !src) || (src == dest))
		return (dest);
	i = 0;
	while (i < (int)n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		((unsigned char *)src)[i] = '\0';
		i++;
	}
	return (dest);
}

char	*fill_str(t_list *list, int breakline, char *buffer)
{
	int		i;
	int		j;
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_lstsize(list) * BUFFER_SIZE + breakline + 2));
	if(!res)
		return (NULL);
	i = 0;
	while (list)
	{
		j = 0;
		while (j < BUFFER_SIZE && (list->str)[j])
		{
			res[i] = (list->str)[j];
			i++;
			j++;
		}
		list = list->next;
	}
	j = 0;
	while (buffer[j] != '\n')
	{
		res[i] = buffer[j];
		i++;
		j++;
	}
	res[i] = buffer[j];
	res[i + 1] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	int			breakline;
	size_t		sz;
	t_list		**list;
	static char	buffer[BUFFER_SIZE];
	char		*res;

	int i = 0;
	*list = NULL;
	// printf("addresse : %p", &list);
	// printf("buffer avant init : %dFin\n\n", isbreak(buffer));
	while (isbreak(buffer) == -1)
	{
		sz = read(fd, buffer, BUFFER_SIZE);
		// printf("%c ", buffer[0]);
		if (sz <= 0)
		{
			ft_lstclear(list);
			return (NULL);
		}
		// printf("AVANT\n%c\n", ((*list)->str)[0]);
		// printf("%c\n", (ft_lstlast(*list)->str)[0]);
		// printf("%c\n", (ft_lstlast(*list)->str)[1]);
		// printf("%c\n", (ft_lstlast(*list)->str)[2]);
		// printf("%s\n\n\n", fill_str(*list, 2, buffer));
		ft_lstadd_back(list, ft_lstnew(buffer));
		printf("APRES\n%c\n", ((*list)->str)[0]);
		printf("%c\n", (ft_lstlast(*list)->str)[0]);
		printf("%c\n", (ft_lstlast(*list)->str)[1]);
		printf("%c\n", (ft_lstlast(*list)->str)[2]);
		printf("%s\n\n\n", fill_str(*list, 2, buffer));
	}
	breakline = isbreak(buffer);
	// printf("addresse : %p", &list);
	// printf("0%c0\n", (list->str)[0]);
	// printf("1%c1\n", (list->str)[1]);
	// printf("2%c2\n", (list->str)[2]);
	// printf("0%c0\n", ((list->next)->str)[0]);
	// printf("1%c1\n", ((list->next)->str)[1]);
	// printf("2%c2\n", ((list->next)->str)[2]);
	// printf("0%c0\n", (ft_lstlast(list)->str)[0]);
	// printf("1%c1\n", (ft_lstlast(list)->str)[1]);
	// printf("2%c2\n\n", (ft_lstlast(list)->str)[2]);
	res = fill_str(*list, breakline, buffer);
	ft_memmove(buffer, buffer + breakline + 1, BUFFER_SIZE - breakline - 1);

	//printf("Buffer : \n%sFin du buffer\n", buffer);

	//ft_lstclear(&list);
	return (res);
}

#include <fcntl.h>

int main()
{
	// int fd;
	// char test[10];

	// fd = open("get_next_line.c", O_RDONLY);
	// // printf("Debut%s", get_next_line(fd));
	// get_next_line(fd);

	// close(fd);

	// Fill_str marche parfaitement OU PAS
	

	// char	str[] = "Haha ";
	// printf("%i", isbreak(str));

	char	str1[] = "hihihi ";
	char	str2[] = "hahaha ";
	char	str3[] = "youhou ";
	char	buffer[] = "buff\ner";

	t_list	**list;
	//*list = NULL;

	ft_lstadd_back(list, ft_lstnew(str1));
	ft_lstadd_back(list, ft_lstnew(str2));
	ft_lstadd_back(list, ft_lstnew(str3));

	printf("%d\n", ft_lstsize(*list));
	printf("%s", fill_str(*list, isbreak(buffer), buffer));

	printf("%s", (*list)->str);
}
