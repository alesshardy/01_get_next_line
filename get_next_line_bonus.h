/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:07:46 by apintus           #+#    #+#             */
/*   Updated: 2023/12/06 17:34:06 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 4096

char	*get_next_line(int fd);
char	*ft_extract_line(char *data);
char	*ft_update_data(char *old_data);
char	*ft_fill(int fd, char *data);

size_t	ft_strlen(char *str);
int		ft_strcontains(char *str, char c);
char	*ft_strjoin(char *data, char *buff);
char	*ft_strcpy_nl(char *dest, char *src, int nl_stop);

#endif
