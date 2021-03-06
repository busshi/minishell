#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "minishell/minishell.h"
#include "minishell/parser.h"
#include "minishell/env.h"
#include "minishell/error.h"

#include "libft/cstring.h"
#include "libft/gc.h"
#include "libft/io.h"
#include "libft/string.h"
#include "libft/ctype.h"

static char	*parse_var(char **word_loc)
{
	char	*var;
	char	*tmp;
	char	*word;
	size_t	i;

	i = 0;
	word = *word_loc;
	while (ft_isalnum(word[i]))
		++i;
	if (i == 0)
		return (NULL);
	tmp = assert_ptr(ft_substr(word, 0, i));
	var = minishell_getenv(tmp);
	free(tmp);
	*word_loc += i;
	return (var);
}

static void	tokenize_var(t_pipeline *pipeline, t_string *expanded, char *var)
{
	char	*token;
	char	*tmp;

	var = gc_add_tmp(ft_strdup(var), &free);
	token = ft_strtok(var, " \t");
	tmp = token;
	while (token != NULL)
	{	
		tmp = ft_strtok(NULL, " \t");
		if (tmp == NULL)
		{
			if (token != var)
				ft_string_set_length(*expanded, 0);
			ft_string_append_cstr(*expanded, token);
		}
		else if (token == var)
		{
			ft_string_append_cstr(*expanded, token);
			parse_word(pipeline,
				gc_add_tmp(ft_string_tocstring(*expanded), &free));
		}
		else
			parse_word(pipeline, token);
		token = tmp;
	}
}

static void	expand_env_variable(t_pipeline *pipeline, t_string *expanded,
		char **word_loc, unsigned char quote)
{
	char		status[4];
	char		*var;

	(*word_loc)++;
	if (**word_loc == '?')
	{
		ft_snprintf(status, sizeof (status), "%hhu",
			g_msh.status);
		ft_string_append_cstr(*expanded, status);
		(*word_loc)++;
		return ;
	}
	var = parse_var(word_loc);
	if (var == NULL)
		return ;
	if (quote == '"')
		ft_string_append_cstr(*expanded, var);
	else if (!quote)
		tokenize_var(pipeline, expanded, var);
}

void	expand(t_pipeline *pipeline, char *word)
{
	t_string		expanded;
	unsigned char	quote;

	quote = 0;
	expanded = gc_add_tmp(ft_string_new(ft_strlen(word) * 2),
			(void *)(void *)&ft_string_destroy);
	while (*word != '\0')
	{
		if (*word == quote)
			quote = 0;
		else if (!quote && (*word == '\'' || *word == '"')
			&& ft_strchr(word + 1, *word))
			quote = *word;
		if (quote != '\'' && word[0] == '$' && word[1] != quote)
			expand_env_variable(pipeline, &expanded, &word, quote);
		else if (*word != '\0')
			ft_string_append_char(expanded, *word++);
	}
	if (ft_string_length(expanded) > 0)
		parse_word(pipeline, gc_add_tmp(ft_string_tocstring(expanded), &free));
}
