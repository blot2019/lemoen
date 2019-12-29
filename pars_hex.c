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

	if (init_lemin(&lemin, spl))
		return (0);
	return (1);
}

int lets_read(void)
{
	char *input;
	char **spl;
	int fd;

	fd = open("hex_test",O_RDONLY);
	input = ft_undin(fd);
	spl = ft_strsplit(input, '\n');
	return (check_and_parse(spl));
}