/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:45:06 by myukang           #+#    #+#             */
/*   Updated: 2022/05/11 17:19:34 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <signal.h>
typedef struct s_server
{
	int				requested_num;
	unsigned char	charactor;
}	t_server;

void	print_time();
#endif
