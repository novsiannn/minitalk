/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:56:28 by nikitos           #+#    #+#             */
/*   Updated: 2023/03/19 18:00:59 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"

t_temp g_temp;

void	handler(int signal, siginfo_t *siginfo, void *context)
{
	int bit;

	bit = signal - SIGUSR1;
	if (siginfo->si_pid != g_temp.client_pid)
		init_g_temp();
	g_temp.prog_char = g_temp.prog_char << 1 | bit;
	g_temp.i++;
	if (g_temp.i == 8)
	{
		if (!g_temp.prog_char)
			kill(g_temp.client_pid, SIGUSR1);
		ft_putchar_fd(g_temp.prog_char, 1);
		init_g_temp();
		exit(0);
	}
	g_temp.client_pid = siginfo->si_pid; 
}

void init_g_temp(void)
{
	g_temp.client_pid = 0;
	g_temp.i = 0;
	g_temp.prog_char = 0;
}

int main(void)
{
	struct sigaction siga;

	ft_printf("Server's pid: %d\n", getpid());
	siga.sa_flags = SA_SIGINFO;
	siga.sa_sigaction = &handler;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	while(0 == 0)
		usleep(1);
}