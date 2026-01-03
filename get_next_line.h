/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabarin <mjabarin@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:50:23 by mjabarin          #+#    #+#             */
/*   Updated: 2026/01/03 15:35:18 by mjabarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#endif

#ifndef BUFF_SIZE
#define BUFF_SIZE 10
#endif

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list{
	char	 	*str_buff;
	struct s_list 	*next;
}		t_list;

char	*get_next_line(int fd);
void	create_lst(t_list **lst, int fd);
void	append(t_list **lst, char *buff);
t_list	*ft_lstlast(t_list *lst);
void    ft_dealloc(t_list **lst, t_list *clean_node, char *buff);
