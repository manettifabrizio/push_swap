/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:41:26 by fmanetti          #+#    #+#             */
/*   Updated: 2021/04/13 18:19:28 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		read_inst_and_execute(t_stack *s)
{
	char	*inst;

	while (get_next_line(STDIN_FILENO, &inst) > 0)
		if (!(execute_instructions(s, inst)))
			return (0);
	return (1);
}

int				main(int ac, char **av)
{
	t_stack	s;

	if (ac < 2)
		return (0);
	if (!(create_stacks(ac, av, &s)) && !(read_inst_and_execute(&s)))
		return (error(&s));
	if (stack_is_sort(s.a, s.size_a) && s.size_b == 0)
		ft_putstr(OK);
	else
		ft_putstr(KO);
	free(s.a);
	free(s.b);
	return (0);
}