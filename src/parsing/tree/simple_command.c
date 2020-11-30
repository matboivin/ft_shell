/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:53:42 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/30 19:05:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "sh_expr.h"

/*
** Simple command
**
** malloc_simple_command()  :  Malloc function
** free_simple_command()    :  Free function
*/

t_simple_cmd		*malloc_simple_command(void)
{
	t_simple_cmd	*result;

	result = malloc(sizeof(t_simple_cmd));
	if (!result)
		return (NULL);
	result->redir_list = NULL;
	result->arg_count = 0;
	result->cmd_args = NULL;
	return (result);
}

void				free_simple_command(t_simple_cmd *to_free)
{
	if (!to_free)
		return ;
	free_redir_list(&(to_free->redir_list));
	if (to_free->cmd_args)
	{
		ft_str_arr_del(to_free->cmd_args);
		to_free->cmd_args = NULL;
	}
	free(to_free);
	to_free = NULL;
}
