/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:10:17 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/27 15:10:19 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

t_rooms	*ft_make_one_room(int x, int y, char *name, t_rooms **head)
{
	t_rooms *temp;

	temp = *head;
	if (*head == NULL)
	{
		*head = (t_rooms*)malloc(sizeof(t_rooms));
		(*head)->x = x;
		(*head)->y = y;
		(*head)->name = ft_strdup(name);
		(*head)->st = WAY;
		(*head)->next = NULL;
		return (*head);	
	}
	while (temp->next)
		temp = temp->next;
	temp->next = (t_rooms*)malloc(sizeof(t_rooms));
	temp->next->x = x;
	temp->next->y = y;
	temp->next->name = ft_strdup(name);
	temp->st = WAY;
	temp->next->next = NULL;
	return (*head);
}

t_rooms	*ft_set_room(t_rooms *head, int op, char **line)
{
	char 	**s;
	t_rooms *temp;
	int		i;

	if (op == 1 || op == 2)
	{
		ft_printf("%s\n", *line);
		free(*line);
		get_next_line(0, line);
	}
	ft_printf("%s\n", *line);
	s = ft_strsplit(*line, ' ');
	i = 0;
	while (s[i])
		i++;
	if (i != 3 && write(2, DAT, 34))
		exit(EXIT_FAILURE);
	if (!ft_rooms_err_manager(head, &s))
		exit(EXIT_FAILURE);	
	temp = ft_make_one_room(ft_atoi(s[1]), ft_atoi(s[2]), s[0], &head);
	if (op == 1)
		temp->st = STA;
	else if (op == 2)
		temp->st = END;
	return (temp);
}

void	ft_chooser(t_map **map, char **line)
{
	if(ft_strcmp(*line, "##start") == 0 && ++g_i)
		(*map)->top = ft_set_room((*map)->top, 1, line);
	else if(ft_strcmp(*line, "##end") == 0)
		(*map)->top = ft_set_room((*map)->top, 2, line);
	else if(ft_strstr(*line, "#") && !(ft_strstr(*line, "##")))
	{
		if (g_i == 0 && write(2, COM, 47))
			exit(EXIT_FAILURE);
		ft_printf("%s\n", line);
	}
	else if(ft_strstr(*line, "##") > 0)
		printf("%s", "");
	else if ((ft_isdigit(**line) || ft_isascii(**line)) && (**line != 'L' && **line != '#'))
		(*map)->top = ft_set_room((*map)->top, 0, line);
	else
		exit(EXIT_FAILURE);
	free(*line);
}

void	ft_make_rooms(t_map **map, char **line)
{
	g_i = 0;
	ft_chooser(map, line);
	while (get_next_line(0, line) > 0)
	{
		if (ft_strstr(*line, "-") > 0)
			return ;
		else
			ft_chooser(map, line);
	}
}
