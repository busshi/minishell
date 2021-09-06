/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:11:07 by aldubar           #+#    #+#             */
/*   Updated: 2021/09/07 00:11:10 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/internal/string_int.h"

int	ft_string_output(t_string_int *str, int fd)
{
	return (write(fd, str->chrs, str->length));
}
