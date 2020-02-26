/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:55:40 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/17 14:55:44 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*creatcmd(void)
{
	t_cmd *cmds;

	if (!(cmds = (t_cmd *)malloc(sizeof(t_cmd))))
		return (NULL);
	cmds->cmdinb = 0;
	cmds->minnum = 20000;
	cmds->mostlowest = 0;
	cmds->minb = 0;
	cmds->curr_b = 0;
	cmds->cmdina3 = -1;
	cmds->cmdina2 = -1;
	cmds->flag = 0;
	cmds->flagb = 0;
	return (cmds);
}

void	clean_cmd(t_cmd *cmds)
{
	cmds->cmdinb = 0;
	cmds->minnum = 20000;
	cmds->mostlowest = 0;
	cmds->minb = 0;
	cmds->curr_b = 0;
	cmds->cmdina3 = -1;
	cmds->cmdina2 = -1;
	cmds->flag = 0;
	cmds->flagb = 0;
	free(cmds);
}

t_flg	*create_flg(void)
{
	t_flg *f;

	if (!(f = (t_flg *)malloc(sizeof(t_flg))))
		return (NULL);
	f->v = 0;
	f->c = 0;
	return (f);
}

void	clean_flg(t_flg *f)
{
	f->v = 0;
	f->c = 0;
	free(f);
}
