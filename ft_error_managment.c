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

int		ft_ant_err_manager(char **s, t_map **map)
{
	int len;
	int i;

	len = ft_strlen(*s);
	if (len == 0 && NONEND)
		return (0);
	i = **s == '-' ? 0 : -1;
	while (++i < len)
		if (ft_isdigit(*(*s + i)) == 0 && write(2, NUM, 49))
			return (0);
	(*map)->ants = ft_atoi(*s);
	if ((*map)->ants < 0 && **s != '-' && write(2, OMAX_INT, 59))
		return (0);	
	if ((*map)->ants <= 0 && write(2, BEL_ZER, 47))
		return (0);
	ft_printf("%s\n", *s);
	free(*s);
	return (1);
}

void	ft_free_split(char ***split)
{
	char **s;
	int i;

	i = -1;
	s = *split;
	while (s[++i])
	{
		ft_strclr(s[i]);
		free(s[i]);
	}
	free(s);
}

int 	ft_rooms_err_manager(t_rooms *head, char ***split)
{
	char 	**s;
	int 	i;
	int 	j;

	s = *split;
	i = ft_atoi(s[1]);
	if (((s[1][0] != '-' && i < 0) || (s[1][0] == '-' && i > 0)) &&\
		write(1, CORX, 56))
		return(0);
	j = ft_atoi(s[2]);
	if (((s[2][0] != '-' && j < 0) || (s[2][0] == '-' && j > 0)) &&\
		write(1, CORY, 56))
		return (0);
	if ((s[0][0] == '#' || s[0][0] == 'L') && write(2, DAT, 34))
		return (0);
	while (head)
	{
		if (ft_strequ(s[0], head->name) && DUP)
			return(0);
		if (head->x == i && head->y == j && DUP)
			return(0);
		head = head->next;
	}
	ft_free_split(split);
	return (1);
}
