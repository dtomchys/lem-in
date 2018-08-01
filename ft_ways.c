/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ways.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:19:20 by dtomchys          #+#    #+#             */
/*   Updated: 2018/04/17 20:19:22 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

char	*ft_find_name(t_rooms *head, int ind)
{
	int i;

	i = 0;
	while (head)
	{
		if (i == ind)
			return (head->name);
		head = head->next;
		i++;
	}
	return (NULL);
}

t_way	*ft_create_way(char *s)
{
	t_way	*tmp;

	tmp = (t_way*)malloc(sizeof(t_way));
	tmp->name = s;
	tmp->ant = 0;
	tmp->next = NULL;
	return (tmp);
}

t_way	*ft_push_front(t_way *head, char *s)
{
	t_way *res;

	res = ft_create_way(s);
	res->next = head;
	return (res);
}

t_way	*ft_set_way(t_vert *v, t_map *map)
{
	int		i;
	t_way	*res;

	i = map->end;
	res = ft_create_way(ft_find_name(map->top, i));
	while (i != map->start)
	{
		i = v[i].p;
		res = ft_push_front(res, ft_find_name(map->top, i));
	}
	res->ant = map->ants;
	return (res);
}
