/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:52:11 by nikitos           #+#    #+#             */
/*   Updated: 2023/03/21 22:17:49 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include "../libftPrintf/src/ft_printf.h"
# include "../libftPrintf/libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/signal.h>
# include <unistd.h>

void	handler(int signal, siginfo_t *siginfo, void *context);
void	init_g_temp(void);

typedef struct s_temp{
	int		i;
	int		client_pid;
	char	prog_char;
}t_temp;

#endif