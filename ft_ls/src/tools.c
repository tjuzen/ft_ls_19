/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:55:14 by tjuzen            #+#    #+#             */
/*   Updated: 2019/08/14 17:45:09 by hde-ghel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"


void		init_arg(t_arg_ls *arg)
{
	arg->is_l = 0;
	arg->is_rr = 0;
	arg->is_a = 0;
	arg->is_r = 0;
	arg->is_t = 0;
	arg->path = ft_strdup("./");
	arg->totalsize = 0;
	arg->flag_mutiple_folders = 0;
	arg->file_printed = 0;
	arg->is_in_recu = 0;
}

int			check_path(char *str, t_arg_ls *arg)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	/*
	if (str[i - 1] != '/')
	{
		if (!(arg->path = (char *)malloc(sizeof(char) * i + 2)))
			return (-1);
		while (j < i)
		{
			arg->path[j] = str[j];
			j++;
		}
		arg->path[j] = '/';
		arg->path[j + 1] = '\0';
	}
	else
	*/
		arg->path = ft_strjoin(str, "/");
		//free str
	return (1);
}

int			check_point(char *s)
{
	int			i;
	size_t		len;

	i = 0;
	len = ft_strlen(s);
	len--;
	while (s[len] != '/' && s[len] != '.')
		len--;
	while (s[len] != '/' && s[len] == '.')
	{
		i++;
		len--;
	}
	if (i == 1 || i == 2)
	{
		if ((ft_strlen(s)) - 3 <= len)
			return (1);
	}
	return (0);
}
