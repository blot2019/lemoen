//
// Created by Grass Emerald on 28/12/2019.
//

#include "lemin.h"

int     take_next_start(char *str, int prev_start)
{
	int i;

	i = 0;
	if (prev_start < 0)
		return (i);
	else
		i = prev_start;
	while (str[i] && str[i] != '-')
		i++;
	while (str[i] && str[i] == '-')
		i++;
	return (i);
}

int     take_next_border(char *str, int prev_border)
{
	int i;

	if (prev_border < 0)
		i = 0;
	else
		i = prev_border;
	while (str[i] && str[i] == '-')
		i++;
	while (str[i] && str[i] != '-')
		i++;
	return (i);
}

int     fill_borders(char *str)
{
	int i;
	int border_count;

	i = -1;
	border_count = 0;
	while (str[++i])
	{
		if (str[i] == '-')
			border_count++;
	}
	return (border_count);
}

int     real_hash(int first_hash, t_lemin *lemin)
{
	int i;

	i = 0;
	while (i < lemin->rooms_len)
	{
		if (first_hash == lemin->rooms[i].hash)
			return (1);
		i++;
	}
	return (0);
}

int     fill_one_link(char *str, t_hash *hash_found, t_lemin *lemin)
{
	int border_count;
	int start;
	int border;

	start = -1;
	border = -1;
	hash_found->hash_first = 0;
	hash_found->hash_second = 0;
	if (fill_borders(str) > 1)
		return (0);
	start = take_next_start(str, start);
	border = take_next_border(str, border);
	hash_found->hash_first = hash_my_name(str, start, border);
	hash_found->first_name = ft_strsub(str, start, border - start);
	start = border;
	start = take_next_start(str, start);
	border = ft_strlen(str);
	hash_found->hash_second = hash_my_name(str, start, border);
	hash_found->second_name = ft_strsub(str, start, border - start);
	return (1);
}

int     error_out_link_create(t_hash *hash_found)
{
	free((*hash_found).first_name);
	free((*hash_found).second_name);
	return (0);
}

int     take_links(t_lemin *lemin, char **spl)
{
	int y;
	t_hash hash_found;
	int links_count;

	y = lemin->start_links - 1;
	links_count = 0;
	while (spl[++y])
	{
		if (spl[y][0] != '#')
		{
			hash_found.first_name = NULL;
			hash_found.second_name = NULL;
			if (!fill_one_link(spl[y], &hash_found, lemin))
				return (0);
			if (!create_link_in_room(lemin, hash_found))
				return (error_out_link_create(&hash_found));
			free(hash_found.first_name);
			free(hash_found.second_name);
			links_count++;
		}
		else if (!ft_strcmp(spl[y], "##start") || !ft_strcmp(spl[y], "##end"))
			return (0);
	}
	if (!links_count)
		return (0);
	return (1);
}