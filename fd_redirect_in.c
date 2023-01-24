/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_redirect_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoller <mkoller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:40:39 by mkoller           #+#    #+#             */
/*   Updated: 2023/01/24 16:38:45 by mkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp_special(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
	}
	return (0);
}

char	*heredoc(char *limit)
{
	char	*str[2];
	char	*temp;
	int		len;

	len = 0;
	str[0] = NULL;
	str[1] = NULL;
	while (!str[0] || (ft_strncmp_special(str[0], limit, len))
		|| (ft_strlen(limit) != len))
	{
		temp = str[1];
		str[1] = ft_strjoin(str[1], str[0]);
		free(temp);
		free(str[0]);
 		str[0] = readline("heredoc> ");
		if (!str[0])
		{
			printf("ERROR!!");
			break ;
		}
		temp = str[0];
		str[0] = ft_strjoin(str[0], "\n");
		free(temp);
		len = ft_strlen(str[0]) - 1;
	}
	free(str[0]);
	return (str[1]);
}

void	print_file_error(char **str, int i)
{
	ft_putstr_fd("minishell: no such file or directory: ",
					1);
	ft_putstr_fd(str[i], 1);
	ft_putstr_fd("\n", 1);
}

int	create_trunc_in(t_parse *temp, int *i)
{
	if (temp->full_cmd[*i][1] != '\0')
	{
		temp->full_cmd[*i] = ft_strtrim(temp->full_cmd[*i], "<");
		temp->in = open(temp->full_cmd[*i], O_RDONLY, 0666);
		if (temp->in == -1)
			print_file_error(temp->full_cmd, *i);
		temp->full_cmd[*i] = ft_strtrim(temp->full_cmd[*i],
										temp->full_cmd[*i]);
	}
	else
	{
		temp->in = open(temp->full_cmd[*i + 1], O_RDONLY, 0666);
		if (temp->in == -1)
			print_file_error(temp->full_cmd, *i + 1);
		temp->full_cmd[*i] = ft_strtrim(temp->full_cmd[*i],
										temp->full_cmd[*i]);
		temp->full_cmd[*i + 1] = ft_strtrim(temp->full_cmd[*i + 1],
											temp->full_cmd[*i + 1]);
	}
	return (1);
}

int	create_heredoc(t_parse *temp, int *i)
{
	char	*str;

	if (temp->full_cmd[*i][2] != '\0')
	{
		temp->full_cmd[*i] = ft_strtrim(temp->full_cmd[*i], "<<");
		str = heredoc(temp->full_cmd[*i]);
		temp->full_cmd[*i] = ft_strtrim(temp->full_cmd[*i],
										temp->full_cmd[*i]);
		temp->heredoc = ft_strjoin(temp->heredoc, str);
		free(str);
	}
	else
	{
		temp->full_cmd[*i] = ft_strtrim(temp->full_cmd[*i], "<<");
		str = heredoc(temp->full_cmd[*i + 1]);
		temp->full_cmd[*i + 1] = ft_strtrim(temp->full_cmd[*i + 1],
											temp->full_cmd[*i + 1]);
		temp->heredoc = ft_strjoin(temp->heredoc, str);
		free(str);
	}
	return (1);
}

int	get_all_fd_in(t_prompt *struc)
{
	int		i;
	t_parse	*temp;

	i = 0;
	temp = struc->cmds;
	if (!check_valid_filename(temp))
	{
		put_error(PARSE_ERROR);
		return (0);
	}
	while (temp)
	{
		while (temp->full_cmd[i])
		{
			if (temp->full_cmd[i][0] == '<' && temp->full_cmd[i][1] == '<')
				create_heredoc(temp, &i);
			else if (temp->full_cmd[i][0] == '<')
				create_trunc_in(temp, &i);
			i++;
		}
		trim_white(temp);
		temp = temp->next;
		i = 0;
	}
	return (1);
}
