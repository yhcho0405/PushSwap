/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youncho <youncho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:14:26 by youncho           #+#    #+#             */
/*   Updated: 2021/06/23 12:33:17 by youncho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
