/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:37:12 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/27 12:37:20 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void testing(t_map *map)
{
	while (map->top)
	{
		printf("X: %d Y: %d NAME: %s STAT: %d \n", map->top->x, map->top->y, map->top->name, map->top->st);
		map->top = map->top->next;
	}
}

int main(void)
{
	char	*line;
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	ft_bzero(map, sizeof(t_map));
	if (get_next_line(0, &line) && !ft_ant_err_manager(&line, &map))
		exit(EXIT_FAILURE);
	while (get_next_line(0, &line) > 0)
	{
		ft_make_rooms(&map, &line);
		testing(map);
		ft_make_links(&map, &line);
		exit(0);
	}
	return (0);
}
