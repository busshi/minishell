#include <stdlib.h>

#include "minishell/minishell.h"
#include "minishell/env.h"
#include "minishell/builtin.h"

#include "libft/cstring.h"
#include "libft/ctype.h"
#include "libft/io.h"

static int	error_export(char *var_name)
{
	ft_dprintf(2, "minishell: export \"%s\": not a valid"
		" identifier\n", var_name);
	free(var_name);
	return (1);
}

int	builtin_export(int argc, char *argv[], bool forked)
{
	char	*var_name;
	char	*s;

	(void)forked;
	if (argc == 2)
	{
		s = ft_strdup(argv[1]);
		var_name = s;
		s = ft_strchr(s, '=');
		if (s == NULL)
		{
			free(s);
			return (0);
		}
		else
			*s++ = '\0';
		if (is_valid_env_var_name(var_name) && argv[1][0] != '=')
			minishell_setenv(var_name, s);
		else
			return (error_export(var_name));
		free(var_name);
	}
	return (0);
}
