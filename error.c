/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoller <mkoller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:22:06 by mkoller           #+#    #+#             */
/*   Updated: 2023/01/26 11:44:01 by mkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_error(t_parse *node)
{
	
}

void	put_error(char *str)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}
