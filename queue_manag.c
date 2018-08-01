/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_manag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:20:42 by dtomchys          #+#    #+#             */
/*   Updated: 2018/04/17 20:20:43 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lem_in.h"

void	push_queue(t_queue *q, int val)
{
	q->i[q->size++] = val;
}

void	pop_queue(t_queue *q)
{
	int i;

	i = -1;
	while (++i < q->size && i + 1 < 2048)
		q->i[i] = q->i[i + 1];
	q->size--;
}

int		front_queue(t_queue *q)
{
	return (q->i[0]);
}

int		empty_queue(t_queue *q)
{
	return (q->size == 0);
}
