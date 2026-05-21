/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjabarin <mjabarin@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:50:23 by mjabarin          #+#    #+#             */
/*   Updated: 2026/01/07 13:00:28 by mjabarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*str_buff;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	create_lst(t_list **lst, int fd);
void	append(t_list **lst, char *buff);
int		found_nl(t_list	*lst);
char	*get_line(t_list *lst);
int		len_to_nl(t_list *lst);
void	copy_str(t_list *lst, char *str);
void	polish_lst(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_dealloc(t_list **lst, t_list *clean_node, char *buff);
#endif
