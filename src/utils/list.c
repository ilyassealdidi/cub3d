/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:07:42 by ialdidi           #+#    #+#             */
/*   Updated: 2024/11/06 12:01:35 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int ft_lstappend(t_list **lines, void *content)
{
	t_list  *new;

	new = ft_lstnew(content);
	if (!isset(new))
		return (FAILURE);
	ft_lstadd_back(lines, new);
	return (SUCCESS);
}
