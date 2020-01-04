//
// Created by Grass Emerald on 25/12/2019.
//

#include "lemin.h"
#include <fcntl.h>

void	concat_me_stdin(char **args, char *str)
{
	static int	i;
	int			j;
	char		*dst;

	j = 0;
	dst = *args;
	while (str[j])
	{
		dst[i++] = str[j++];
	}
	dst[i++] = '\n';
	dst[i] = '\0';
}

char	*ft_undin(int fd)
{
	char	*buf;
	char	*line;

	if (!(buf = (char *)malloc(sizeof(char) * 1000000)))
		return (NULL);
	buf[0] = '\0';
	while (get_next_line(fd, &line) > 0)
	{
		concat_me_stdin(&buf, line);
		free(line);
	}
	if (!ft_strlen(buf))
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

int check_and_parse(char **spl)
{
	t_lemin lemin;

	lemin.start = -1;
	lemin.end = -1;
	if (!init_lemin(&lemin, spl))
		return (0);
	return (1);
}

int search_void_string(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
			return (1);
	}
	return (0);
}

int lets_read(void)
{
	char *input;
	char **spl;
	int fd;

	fd = open("trick",O_RDONLY);
	if (!(input = ft_undin(fd)))
		return (0);
	if (search_void_string(input))
	{
		free(input);
		return (0);
	}
	spl = ft_strsplit(input, '\n');
	free(input);
	if (!check_and_parse(spl))
		return (0);
	return (1);
}