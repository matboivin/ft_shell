/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:24:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 00:06:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <limits.h>
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin pwd() without any options
**
** pwd
**     Print the name of the current working directory.
**     If no option is specified, -P is assumed (print the physical directory,
**     without any symbolic links)
**
** returns: 0
**          non-zero if an invalid option is given or the current directory
**          cannot be read
*/

int			pwd_builtin(int argc, char **argv)
{
	char	cwd[PATH_MAX];

	(void)argc;
	if (!getcwd(cwd, PATH_MAX))
	{
		print_errno(argv[CMD_NAME]);
		return (EXIT_FAILURE);
	}
	ft_printf("%s\n", cwd);
	return (0);
}