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

int	len_to_nl(t_list *lst)
{
	int	i;
	int	len;

	if (lst == NULL)
		return (0);
	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->str_buff[i])
		{
			if (lst->str_buff[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

char	*get_line(t_list *lst)
{
	int		len;
	char	*next_str;

	if (lst == NULL)
		return (NULL);
	len = len_to_nl(lst);
	next_str = malloc(len + 1);
	if (next_str == NULL)
		return (NULL);
	copy_str(lst, next_str);
	return (next_str);
}

int	found_nl(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->str_buff[i] && i < BUFFER_SIZE)
		{
			if (lst->str_buff[i] == '\n')
				return (1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

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

void	ft_dealloc(t_list **lst, t_list *clean_node, char *buff)
{
	t_list	*tmp;

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
