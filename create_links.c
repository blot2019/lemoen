//
// Created by Grass Emerald on 29/12/2019.
//

#include "lemin.h"

t_links  *create_link(t_room *room)
{
	t_links  *link;

	if (!(link = (t_links *)malloc(sizeof(t_links))))
		return (NULL);
	link->link = room;
	link->next = NULL;
	return (link);
}

void    del_list(t_links **begin_list)
{
	t_links	*link;
	t_links	*f_link;

	link = *begin_list;
	while (link != NULL)
	{
		f_link = link->next;
		free(link);
		link = f_link;
	}
}

void    push_link(t_links **begin_list, t_room *room)
{
	t_links *list;

	list = *begin_list;
	if (list != NULL)
	{
		while (list->next)
			list = list->next;
		if (!(list->next = create_link(room)))
			del_list(begin_list);
	}
	else
	{
		if (!(*begin_list = create_link(room)))
			del_list(begin_list);
	}
}

int     create_link_in_room(t_lemin *lemin, t_hash hash_found)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < lemin->rooms_len && lemin->rooms[i].hash != hash_found.hash_first)
		i++;
	while (j < lemin->rooms_len && lemin->rooms[j].hash != hash_found.hash_second)
		j++;
	push_link(&lemin->rooms[i].links, &lemin->rooms[j]);
	push_link(&lemin->rooms[j].links, &lemin->rooms[i]);
	return (1);
}