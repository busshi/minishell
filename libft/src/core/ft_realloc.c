/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:09:54 by aldubar           #+#    #+#             */
/*   Updated: 2021/09/07 00:10:27 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/cstring.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t osize, size_t nsize)
{
	void	*nptr;

	nptr = malloc(nsize);
	if (!nptr)
		return (NULL);
	ft_memcpy(nptr, ptr, osize);
	free(ptr);
	return (nptr);
}
