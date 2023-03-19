/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:46:05 by nikitos           #+#    #+#             */
/*   Updated: 2023/03/19 16:23:23 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include "../libftPrintf/src/ft_printf.h"
# include "../libftPrintf/libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/signal.h>
# include <unistd.h>

void	wrong_pid(void);
void	send_byte(char byte, int pid);
void	send_message(char *msg, int pid);
void	got_message(int sig);

#endif 