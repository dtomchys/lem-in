/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_ways.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:10:57 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/31 19:10:59 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void	run_ants(t_way *way)
{
	int tab[ft_lenway(way)];
	int ant;
	int len;
	int i;

	ft_bzero(tab, sizeof(tab));
	ant = 0;
	len = ft_lenway(way);
	i = 0;
	while (ft_num_dif(tab, len, 0) || i == 0)
	{
		tab[0] = ant < way->ant ? ++ant : 0;
		ft_show_run(tab, way, len);
		ft_shift(tab, len);
		if (ft_num_dif(tab, len, 0))
			ft_printf("\n");
		i++;
	}
}

void	ft_init(t_vert *v, t_queue *queue, int size)
{
	int i;

	i = -1;
	ft_bzero(queue, sizeof(t_queue));
	while (++i < size)
	{
		v[i].p = INT_MAX;
		v[i].v = INT_MAX;
	}
}

void	ft_bfs(t_map **map, t_vert *v)
{
	int			i;
	int			tmp;
	t_queue		queue;

	tmp = 0;
	ft_init(v, &queue, (*map)->size);
	push_queue(&queue, (*map)->start);
	while (!empty_queue(&queue))
	{
		tmp = front_queue(&queue);
		pop_queue(&queue);
		if (tmp == (*map)->end)
			break ;
		i = -1;
		while (++i < (*map)->size)
		{
			if ((*map)->link[tmp][i] != -1 && (v[i].v > v[tmp].v + 1))
			{
				push_queue(&queue, i);
				v[i].p = tmp;
				v[i].v = v[tmp].v + 1;
			}
		}
	}
}

int		ft_find_ways(t_map **map)
{
	t_vert		v[(*map)->size];

	v[(*map)->start].v = 0;
	ft_bfs(map, v);
	if (v[(*map)->end].p == INT_MAX && NOT_CON)
		return (0);
	(*map)->way = ft_set_way(v, *map);
	run_ants((*map)->way);
	return (1);
}
