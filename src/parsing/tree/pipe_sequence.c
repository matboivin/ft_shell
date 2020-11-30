/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:53:42 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/30 19:06:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_expr.h"

/*
** Pipe sequence
**
** malloc_pipe_sequence()  :  Malloc function
** free_pipe_sequence()    :  Free function
*/

t_pipe_seq		*malloc_pipe_sequence(size_t count)
{
	t_pipe_seq	*result;

	result = malloc(sizeof(t_pipe_seq));
	if (!result)
		return (NULL);
	result->cmd_count = 0;
	result->simple_cmds = malloc(count * sizeof(t_simple_cmd *));
	return (result);
}

void			free_pipe_sequence(t_pipe_seq *to_free)
{
	size_t		i;

	if (!to_free)
		return ;
	i = 0;
	if (to_free->simple_cmds)
	{
		while (i < to_free->cmd_count)
			free_simple_command(to_free->simple_cmds[i++]);
		free(to_free->simple_cmds);
		to_free->simple_cmds = NULL;
	}
	free(to_free);
}
