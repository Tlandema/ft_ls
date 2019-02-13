/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:05:23 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/13 13:05:46 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	printf ("lines %d\n", w.ws_row);
	printf ("columns %d\n", w.ws_col);
	return 0;  // make sure your main returns int
}
