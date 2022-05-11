/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:45:07 by myukang           #+#    #+#             */
/*   Updated: 2022/05/11 17:19:33 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <signal.h>
void	client_ac_check(int ac);
void	client_spid_check(int server_pid);
void	set_connection(int server_pid);
void	print_time();
#endif
