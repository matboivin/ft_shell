/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 17:03:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)envp;
	if (argc != DEFAULT_ARGC)
		print_usage();
	return (0);
}
