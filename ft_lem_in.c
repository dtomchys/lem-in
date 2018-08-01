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

void	ft_set_st_end(t_map **map)
{
	t_rooms	*temp;
	int		i;

	temp = (*map)->top;
	i = 0;
	while (temp)
	{
		if (temp->st == STA)
			(*map)->start = i;
		if (temp->st == END)
			(*map)->end = i;
		i++;
		temp = temp->next;
	}
}

int		main(void)
{
	char	*line;
	t_map	*map;
	int		i;

	map = (t_map*)malloc(sizeof(t_map));
	ft_bzero(map, sizeof(t_map));
	if ((i = get_next_line(0, &line)) && !ft_ant_err_manager(&line, &map))
		exit(EXIT_FAILURE);
	if (i == 0 && EMPTY)
		exit(EXIT_FAILURE);
	while (get_next_line(0, &line) > 0)
	{
		ft_make_rooms(&map, &line);
		ft_set_st_end(&map);
		ft_make_links(&map, &line);
		if (!ft_find_ways(&map))
			exit(EXIT_FAILURE);
	}
	return (0);
}
