/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_managment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:21:47 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/28 13:21:49 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void	ft_show_com(char **s)
{
	while (s[0][0] == '#' && s[0][1] != '#')
	{
		ft_printf("%s\n", *s);
		free(*s);
		get_next_line(0, s);
	}
}

int		ft_ant_err_manager(char **s, t_map **map)
{
	int len;
	int i;

	ft_show_com(s);
	len = ft_strlen(*s);
	if (len == 0 && NONEND)
		return (0);
	i = **s == '-' ? 0 : -1;
	while (++i < len)
		if (ft_isdigit(*(*s + i)) == 0 && write(2, NUM, 56))
			return (0);
	(*map)->ants = ft_atoi(*s);
	if ((*map)->ants < 0 && **s != '-' && write(2, OMAX_INT, 48))
		return (0);
	if ((*map)->ants <= 0 && write(2, BEL_ZER, 54))
		return (0);
	ft_printf("%s\n", *s);
	free(*s);
	return (1);
}

void	ft_free_split(char ***split)
{
	char	**s;
	int		i;

	i = -1;
	s = *split;
	while (s[++i])
	{
		ft_strclr(s[i]);
		free(s[i]);
	}
	free(s);
}

int		ft_rooms_err_manager(t_rooms *head, char ***split)
{
	char	**s;
	int		i;
	int		j;

	s = *split;
	i = ft_atoi(s[1]);
	if (((s[1][0] != '-' && i < 0) || (s[1][0] == '-' && i > 0)) &&\
		write(2, CORX, 57))
		return (0);
	j = ft_atoi(s[2]);
	if (((s[2][0] != '-' && j < 0) || (s[2][0] == '-' && j > 0)) &&\
		write(2, CORY, 57))
		return (0);
	if ((s[0][0] == '#' || s[0][0] == 'L') && write(2, DAT, 41))
		return (0);
	while (head)
	{
		if (ft_strequ(s[0], head->name) && DUP)
			return (0);
		if (head->x == i && head->y == j && DUP)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_resend(int i, t_map **map, char **s)
{
	if (i != 3 && write(2, DAT, 41))
		exit(EXIT_FAILURE);
	if (!ft_rooms_err_manager((*map)->top, &s))
		exit(EXIT_FAILURE);
}
