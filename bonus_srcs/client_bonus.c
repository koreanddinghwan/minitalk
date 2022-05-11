/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:35 by myukang           #+#    #+#             */
/*   Updated: 2022/05/11 17:19:32 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int main(int ac, char **av)
{
	int	server_pid;

	client_ac_check(ac);
	server_pid = ft_atoi(av[1]);
	client_spid_check(server_pid);
	return (0);
}
