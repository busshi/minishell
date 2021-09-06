/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 00:05:22 by aldubar           #+#    #+#             */
/*   Updated: 2021/09/07 00:05:23 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "minishell/datastructure.h"
# include "minishell/lexer.h"

t_pipeline	*parser_invoke(char *input);
int			parse_redirection(t_pipeline *pipeline, t_lexer *lexer,
				char *token);
int			parse_pipe(t_pipeline *pipeline, t_lexer *lexer, char *token);
int			parse_word(t_pipeline *pipeline, char *token);
char		*word_strip_quotes(char *word);
void		expand(t_pipeline *pipeline, char *word);

#endif
