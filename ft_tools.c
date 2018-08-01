/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:17:44 by dtomchys          #+#    #+#             */
/*   Updated: 2018/04/17 20:17:46 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

int		ft_lenway(t_way *way)
{
	int		i;
	t_way	*tmp;

	i = 0;
	tmp = way;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	*ft_name(t_way *way, int in)
{
	t_way	*tmp;
	int		i;

	i = 0;
	tmp = way;
	while (i < in)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp ? tmp->name : NULL);
}

void	ft_show_run(int *tab, t_way *way, int size)
{
	while (size--)
	{
		if (tab[size] && size != 0)
			ft_printf("L%d-%s ", tab[size], ft_name(way, size));
	}
}

void	ft_shift(int *tab, int size)
{
	int tmp;

	tab[size] = 0;
	size--;
	while (size > 0)
	{
		tmp = tab[size];
		tab[size] = tab[size - 1];
		tab[size - 1] = tmp;
		size--;
	}
}

int		ft_num_dif(int *tab, int size, int num)
{
	int i;

	i = -1;
	while (++i < size)
		if (tab[i] != num)
			return (1);
	return (0);
}
