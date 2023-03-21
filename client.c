/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:56:13 by nikitos           #+#    #+#             */
/*   Updated: 2023/03/21 21:56:12 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/client.h"

void	wrong_pid(void)
{
	ft_putstr_fd("PID is wrong\n", 2);
	exit(0);
}

void	send_byte(char byte, int pid)
{
	int	i;
	int	kill_return;

	kill_return = 0;
	i = 7;
	while (i >= 0)
	{
		if (byte >> i & 1)
			kill_return = kill(pid, SIGUSR2);
		else
			kill_return = kill(pid, SIGUSR1);
		if (kill_return == -1)
			wrong_pid();
		usleep(100);
		i--;
	}
}

void	send_message(char *msg, int pid)
{
	while (*msg)
	{
		send_byte(*msg, pid);
		msg++;
	}
	send_byte(0, pid);
}

void	got_message(int sig)
{
	ft_printf("Message was succesful received!\n");
}

int	main(int ac, char **av)
{
	int	pid;

	signal (SIGUSR1, got_message);
	if (ac != 3)
	{
		ft_putstr_fd ("Error! Usage: ./client [pid] [message]\n", 2);
		return (-1);
	}
	pid = ft_atoi(av[1]);
	if (!av[2][0])
		ft_putstr_fd("Empty message\n", 2);
	send_message(av[2], pid);
	return (0);
}
