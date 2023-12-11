/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:43:41 by apintus           #+#    #+#             */
/*   Updated: 2023/12/06 15:48:30 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strcontains(char *str, char c)
{
	int	i;

	if (str == NULL)
		return (0);
	if (c == '\0')
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *data, char *buff)
{
	char	*join;
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(data) + ft_strlen(buff);
	join = malloc(sizeof(char) * (len + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (data != NULL && data[i] != '\0')
	{
		join[i] = data[i];
		i++;
	}
	if (data != NULL)
		free(data);
	j = 0;
	while (buff != NULL && buff[j] != '\0')
		join[i++] = buff[j++];
	join[len] = '\0';
	return (join);
}

char	*ft_strcpy_nl(char *dest, char *src, int nl_stop)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		if (nl_stop && src[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
