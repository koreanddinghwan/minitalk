/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:25 by myukang           #+#    #+#             */
/*   Updated: 2022/05/10 22:44:12 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

t_server	g_server_set;

static	void	translator(int sig, siginfo_t *info, void *p)
{
	int	num;

	num = sig - 30;
	if (g_server_set.total_req_num == 0)
		ft_printf("Message from client, PID : %d\n", info->si_pid);
	g_server_set.charactor += ft_pow(0x2, g_server_set.requested_num) * num;
	g_server_set.requested_num++;
	if (g_server_set.requested_num == 8)
	{
		write(1, &g_server_set.charactor, 1);
		g_server_set.requested_num = 0;
		g_server_set.charactor = 0;
	}
}

void	handler(int sig, siginfo_t *info, void *p)
{
	translator(sig, info, p);
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	action;

	if (ac > 1)
	{
		ft_putstr_fd("server does not need any arguments\n", 2);
		exit(1);
	}
	else
	{
		pid = getpid();
		ft_printf("\n%s pid : %d\n", av[0], pid);
		action.sa_sigaction = handler;
		action.sa_flags = SA_SIGINFO;
		sigemptyset(&action.sa_mask);
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		while (1)
			pause();
	}
	return (0);
}
