/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:56:28 by nikitos           #+#    #+#             */
/*   Updated: 2023/03/15 18:52:33 by nikitos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/server.h"


void	handler(int signal, siginfo_t *siginfo, void *context)
{
	kill(getpid(), siginfo);
}

int main(void)
{
	struct sigaction siga;

	ft_printf("Server's pid: %d\n", getpid());
	siga.sa_flags = SA_SIGINFO;
	siga.sa_sigaction = &handler;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
}