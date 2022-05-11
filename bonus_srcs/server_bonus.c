/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:25 by myukang           #+#    #+#             */
/*   Updated: 2022/05/11 17:19:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"



int main()
{
	int pid;

	pid = getpid();
	ft_printf("Server Process ID : %d\n", pid);
	
//signal 핸들러 등록.
	struct	sigaction	action;

	action.sa_sigaction = handler;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
//
	return (0);
}
