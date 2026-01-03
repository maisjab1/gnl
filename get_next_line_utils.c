/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabarin <mjabarin@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:39:45 by mjabarin          #+#    #+#             */
/*   Updated: 2026/01/03 15:33:47 by mjabarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
	
t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
void    ft_dealloc(t_list **lst, t_list *clean_node, char *buff)
{
        t_list  *tmp;

        if (*lst == NULL)
                return ;
        while (*lst)
        {
                tmp = (*lst)->next;
                free((*lst)->str_buff);
                free(*lst);
                *lst = tmp;
        }
        *lst = NULL;
        if (clean_node->str_buff[0])
                *lst = clean_node;
        else
        {
                free(buff);
                free(clean_node);
        }
}

