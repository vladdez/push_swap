/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 22:34:32 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/18 13:48:33 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

# define BUFF_SIZE 9999
# define MAXINT 2147483648

typedef struct		s_flg
{
	int				v;
	int				c;
}					t_flg;

typedef struct		s_stk
{
	struct s_stk	*next;
	long long int	num;
	int				chunk;
}					t_stk;

typedef struct		s_cmd
{
	int				minnum;
	int				cmdinb;
	long long		mostlowest;
	long long		minb;
	long long		curr_b;
	int				cmdina3;
	int				cmdina2;
	int				flag;
	int				flagb;
}					t_cmd;

int					get_next_line(const int fd, char **line);

/*
** checker handlers
*/

char				**makewords(char *av, int probel);
long long int		ls_atoi(const char *str);

int					iscmdnorm(char *line);
int					issorted(t_stk *a);
int					isanorm(t_stk *a);

/*
** pushswap finders
*/

void				push_cmd(t_stk **str, t_stk **a, t_stk **b, int cmd);
void				printlist_cmd(t_stk *heada);
void				ft_list_sort(t_stk *begin_list);
int					findmin(t_stk *a);
int					findmin2(t_stk *a);
int					findmax2(t_stk *a);
int					lenofchunk(t_stk **list, int chunk);
long long			findchmax(t_stk *a, int chunk);
void				ft_list_sort(t_stk *begin_list);
int					findpivot2(t_stk **a, int lower);
int					findpivot(t_stk **a, int chunk);
void				ft_list_sort(t_stk *begin_list);
void				ft_list_copy(t_stk **a, t_stk **cpy, int chunk);

/*
** lists
*/

void				*ft_create_elem(long long int x);
t_stk				*ft_push_params(int ac, char **av, t_flg *f);
void				ft_list_clear(t_stk **begin_list);
void				ft_list_push_front(t_stk **begin_list, long long int data);
int					ft_list_size(t_stk *begin_list);
void				ft_list_push_back(t_stk **begin_list, long long int x);

/*
** simple cases
*/

void				case3(t_stk **a, t_stk **str);
void				case4(t_stk **a, t_stk **str, t_stk **b);
void				case5(t_stk **a, t_stk **str, t_stk **b);
int					findmax(t_stk *a);
void				chunk0(t_stk **a);
void				casesmall(t_stk **a, t_stk **str, t_stk **b);

/*
** hard cases
*/

void				partition_of_a(t_stk **a, t_stk **str, t_stk **b);
void				case100(t_stk **a, t_stk **str, t_stk **b);
void				insertionsort2(t_stk **a, t_stk **str, t_stk **b);
void				parted_a(t_stk **a, t_stk **str, t_stk **b);
int					findpivot(t_stk **a, int chunk);
void				parted_a_triple(t_stk **a, t_stk **str, t_stk **b);
int					pivchecker(t_stk **a, int pivot);

/*
** commands - cmd
*/
void				usecmd(t_stk **a, t_stk **b, char *line);
void				ft_p(t_stk **from, t_stk **to, int sw);
void				ft_rr(t_stk **a);
void				ft_r(t_stk **a);
void				ft_s(t_stk *a);

/*
** sa - 1; rra - 2, ra - 3, pa - 4, 6 - rrr, 5 - rr
*/

/*
** circular lock
*/

void				comb_lock(t_stk **a, t_stk **str, t_stk **b);
void				pre_comb_lock(t_stk **a, t_stk **str, t_stk **b,
		t_cmd *cmds);

/*
** lock stat
*/

void				opcounter(t_stk **a, t_stk **b, t_cmd *cmds);
int					comb_counter(t_stk **a, long long int numinb, t_cmd *cmds);

/*
** lock - finders
*/

long long			findalowest(t_stk **a);
int					findforbhigher(t_stk **a, long long int num);
int					findforblower(t_stk **a, long long lowest, long long num);
long long			take_num_in_b(t_stk **b, int unitnum);

/*
** vizual
*/
void				printlist(t_stk *heada);
void				check_viz(int ac, char **av, t_flg *f);
void				doviz(t_flg *f, t_stk **a, t_stk **b, char *line);

/*
** structure creators
*/

t_cmd				*creatcmd(void);
t_flg				*create_flg(void);
void				clean_flg(t_flg *f);
void				clean_cmd(t_cmd *cmds);
void				cleanshit(t_stk **a, t_stk **b, t_flg *f);

#endif
