/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:05:32 by aldubar           #+#    #+#             */
/*   Updated: 2021/09/07 00:05:34 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

void	print_sig_msg(int sig);
void	handle_prompt_sigint(int sig);
void	sig_send_to_all_children(int sig);

#endif
