/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:35 by myukang           #+#    #+#             */
/*   Updated: 2022/05/10 19:29:37 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	request_char(int pid, char c)
{
	int	i;
	int	ret;

	i = 0;
	while (i < 8)
	{
		ft_printf("%d\n", c & 0x1);
		if (c & 0x1)
			ret = kill(pid, SIGUSR2);
		else
			ret = kill(pid, SIGUSR1);
		if (ret)
		{
			ft_printf("error\n");
			exit(1);
		}
		c = c >> 1;
		i++;
		usleep(100);
	}
}

void	request_to_server(char **av)
{
	int		pid;
	int		ret;
	char	*str;

	pid = ft_atoi(av[1]);
	ret = kill(pid, 0);
	if (ret == -1)
	{
		ft_printf("Unavailable pid");
		exit(1);
	}
	else
		ft_printf("we have permission\n");
	str = av[2];
	while (*str)
	{
		request_char(pid, *str);
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac < 3 || ac > 3)
	{
		ft_printf("Client Argument should be greater than 2\n");
		exit(1);
	}
	request_to_server(av);
	return (0);
}
