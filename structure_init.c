//
// Created by Grass Emerald on 28/12/2019.
//

#include "lemin.h"

int     take_ants(t_lemin *lemin, char **spl)
{
	int y;
	int x;
	int ower;

	y = -1;
	x = 0;
	ower = 1;
	lemin->ant_count = -2;
	while (spl[++y] && lemin->ant_count == -2)
	{
		if (spl[y][x] != '#' && spl[y][x])
		{
			lemin->ant_count = ft_atoi_push(spl[y], &x, &ower);
			if (lemin->ant_count  < 1 || !ower )
				return (0);
		}
	}
	lemin->start_rooms = y;
	return (1);
}

void    find_borders(t_lemin *lemin, char **spl)
{
	int y;
	int rooms_count;

	y = lemin->start_rooms - 1;
	rooms_count = 0;
	while (spl[++y])
	{
		if (spl[y][0] != '#' && !ft_strchr(spl[y], ' '))
			break ;
		if (spl[y][0] != '#')
			rooms_count++;
		if (spl[y][0] == '#')
		{
			if (!ft_strncmp(spl[y], "##start", 7) && spl[y + 1] && spl[y + 1][0] != '#')
				lemin->start = y + 1;
		}
		if (spl[y][0] == '#')
		{
			if (!ft_strncmp(spl[y], "##end", 5) && spl[y + 1] && spl[y + 1][0] != '#')
				lemin->end = y + 1;
		}
	}
	lemin->rooms_len = rooms_count;
	lemin->start_links = y;
}

int    remember_room_name(char *str, char **room_name, int *i)
{
	int end;
	int j;

	end = *i;
	j = 0;
	while(str[end] && str[end] != ' ')
		end++;
	if (!((*room_name) = (char *)malloc(sizeof(char) * (end + 1))))
		return (0);
	while (str[*i] && (*i) < end)
		(*room_name)[j++] = str[(*i)++];
	return (1);
}

int     hash_my_name(char *str, int start, int border)
{
	int len;
	int hash;

	len = border - start;
	hash = 0;
	while(start < border)
	{
		hash += (str[start++] * (len--));
	}
	return (hash);
}

t_room  charge_room(char *str, int index_room)
{
	t_room room;
	int     ower;
	int     i;

	room.index = index_room;
	room.part = 0;
	ower = 1;
	i = 0;
	if (!remember_room_name(str, &room.name, &i))
		exit (-1);
	room.x_coord = ft_atoi_push(str, &i, &ower);
	room.y_coord = ft_atoi_push(str, &i, &ower);
	if (!ower)
		exit (-11);
	room.hash = hash_my_name(room.name, 0, ft_strlen(room.name));
	return (room);
}

int     take_rooms(t_lemin *lemin, char **spl)
{
	int y;
	int room;

	find_borders(lemin, spl);
	room = 0;
	if (!(lemin->rooms = (t_room *)malloc(sizeof(t_room) * lemin->rooms_len)))
		return (0);
	y = lemin->start_rooms - 1;
	while (++y < lemin->start_links)
	{
		if (spl[y][0] != '#')
		{
			lemin->rooms[room] = charge_room(spl[y], room);
			lemin->rooms[room].links = NULL;
			if (y == lemin->start)
			{
				lemin->rooms[room].part = 1;
				lemin->start = room;
			}
			if (y == lemin->end)
			{
				lemin->rooms[room].part = -1;
				lemin->end = room;
			}
			room++;
		}
	}
	return (1);
}