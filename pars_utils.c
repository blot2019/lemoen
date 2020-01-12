//
// Created by Grass Emerald on 25/12/2019.
//

#include "lemin.h"
#include <stdio.h>

void     ft_atoi_mark(char *str, int *i, int *mark)
{
	if (str[*i] == '-')
		*mark = -1;
	(*i)++;
}

int		ft_atoi_push(char *str, int *i, int *ower)
{
	int		mark;
	long	result;
	int     dig;

	result = 0;
	mark = 1;
	dig = 0;
	while ((str[*i] == '\f' || str[*i] == '\n' || str[*i] == '\r' ||
	        str[*i] == '\v' || str[*i] == '\t' || str[*i] == ' '))
		(*i)++;
	if ((str[*i] == '-') || (str[*i] == '+'))
		ft_atoi_mark(str, i, &mark);
	while ((str[*i] >= '0') && (str[*i] <= '9'))
	{
		dig++;
		if ((result * 10) < result)
			*ower = 0;
		result = (result * 10) + (str[*i] - '0');
		(*i)++;
	}
	if (result * mark > 2147483647 || result * mark < -2147483648 || !dig)
		*ower = 0;
	return (result * mark);
}

void        print_rooms(t_lemin *lemin)
{
	int i;
	t_links *list;

	i = 0;
	while (i < lemin->rooms_len)
	{
		list = lemin->rooms[i].links;
		printf("room index = %d\n", lemin->rooms[i].index);
		printf("room name = %s\n", lemin->rooms[i].name);
		while (list)
		{
			printf("room nextdoor = %d\n", list->link->index);
			list = list->next;
		}
		i++;
	}
}

int         make_free_lemin(t_lemin *lemin)
{
	free_for_all(lemin);
	return (0);
}

int         init_lemin(t_lemin *lemin, char **spl)
{
	int end;

	end = 1;
	lemin->initial_text = spl;
	lemin->rooms_len = 0;
	//ft_print_char_arr(spl);
	null_pointer_upload(lemin);
	if (!take_ants(lemin, spl))
		return (make_free_lemin(lemin));
	if (!take_rooms(lemin, spl))
		return (make_free_lemin(lemin));
	hash_table_upload(lemin);
	if (!check_rooms(lemin))
		return (make_free_lemin(lemin));
	if (end && !take_links(lemin, spl))
		return (make_free_lemin(lemin));
	//print_rooms(lemin);
	return (1);
}