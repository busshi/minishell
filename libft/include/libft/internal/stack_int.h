/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:09:26 by aldubar           #+#    #+#             */
/*   Updated: 2021/09/07 00:09:30 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_INT_H
# define STACK_INT_H

# include "libft/vector.h"

typedef struct s_stack_int
{
	int			top;
	t_vector	data;
}	t_stack_int;

#endif
