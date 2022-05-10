/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:45:06 by myukang           #+#    #+#             */
/*   Updated: 2022/05/10 22:44:12 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <signal.h>

typedef struct s_server
{
	int				total_req_num;
	int				requested_num;
	unsigned char	charactor;
}	t_server;

#endif
