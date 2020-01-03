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

void    del_list_links(t_links **begin_list)
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

int    push_link(t_links **begin_list, t_room *room)
{
	t_links *list;

	list = *begin_list;
	if (list != NULL)
	{
		while (list->next)
		{
			if (list->link == room)
				return (0);
			list = list->next;
		}
		if (!(list->next = create_link(room)))
			del_list_links(begin_list);
	}
	else
	{
		if (!(*begin_list = create_link(room)))
			del_list_links(begin_list);
	}
	return (1);
}

t_room  *search_in_table(t_lemin *lemin, int hash, char *hash_name)
{
	t_hash_table *list;

	list = lemin->table_hashes[hash];
	if (!list)
		return (NULL);
	while (list)
	{
		if (!ft_strcmp(hash_name, list->link->name))
			return (list->link);
		list = list->next;
	}
	return (NULL);
}

int     create_link_in_room(t_lemin *lemin, t_hash hash_found)
{
	t_room *first_room;
	t_room *second_room;

	first_room = search_in_table(lemin, hash_found.hash_first, hash_found.first_name);
	second_room = search_in_table(lemin, hash_found.hash_second, hash_found.second_name);
	if (!push_link(&first_room->links, second_room))
		return (0);
	if (!push_link(&second_room->links, first_room))
		return (0);
	return (1);
}