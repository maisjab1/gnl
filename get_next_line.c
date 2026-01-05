/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabarin <mjabarin@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:49:35 by mjabarin          #+#    #+#             */
/*   Updated: 2026/01/03 15:44:52 by mjabarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	copy_str(t_list *lst, char *str)
{
	int	i;
	int	j;

	if (lst == NULL)
		return ;
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->str_buff[i])
		{
			if (lst->str_buff[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = lst->str_buff[i++];
		}
		lst = lst->next;
	}
	str[j] = '\0';
}

void	polish_lst(t_list **lst)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buff == NULL || clean_node == NULL)
	{
		free(buff);
		free(clean_node);
		return ;
	}
	last_node = ft_lstlast(*lst);
	i = 0;
	j = 0;
	while (last_node->str_buff[i] != '\n' && last_node->str_buff[i])
		++i;
	if (last_node->str_buff[i] == '\n')
		i++;
	while (last_node->str_buff[i])
		buff[j++] = last_node->str_buff[i++];
	buff[j] = '\0';
	clean_node->str_buff = buff;
	clean_node->next = NULL;
	ft_dealloc(lst, clean_node, buff);
}

void	append(t_list **lst, char *buff)
{
	t_list	*new_node;
	t_list	*last;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->str_buff = buff;
	new_node->next = NULL;
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new_node;
}

void	create_lst(t_list **lst, int fd)
{
	int		chars_read;
	char	*buff;

	while (!found_nl(*lst))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (buff == NULL)
			return ;
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			free(buff);
			if (chars_read == -1)
				*lst = NULL;
			return ;
		}
		buff[chars_read] = '\0';
		append(lst, buff);
	}
}

char	*get_next_line(int fd)
{
	static t_list *lst;
	char *next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_lst(&lst, fd);
	if (lst == NULL)
		return (NULL);
	next_line = get_line(lst);
	polish_lst(&lst);
	return (next_line);
}