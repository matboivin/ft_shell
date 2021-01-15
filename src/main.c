/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/15 20:24:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wandre_mode.h"
#include "ft_sh.h"

/*
** ft_sh
** A minimalist interactive shell mimicking bash
*/

int				main(int argc, char **argv, char **envp)
{
	t_shctrl	ft_sh;

	if (argc != NO_ARGS)
		print_usage(argv[0]);
#ifdef WANDRE_MODE
	wake_wandre();
#endif /* WANDRE_MODE */
	start_shell(envp);
	create_shell(&ft_sh);
	return (wait_for_input(&ft_sh));
}
