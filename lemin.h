//
// Created by Grass Emerald on 25/12/2019.
//

#ifndef LEMIN_LEMIN_H
# define LEMIN_LEMIN_H

#include "libft/libft.h"

//typedef struct      s_node
//{
//	int             index;
//	char            *name;
//	t_stack         *adjacent_nodes;
//	t_ant           *ant;
//}                   t_node;

typedef struct s_links t_links;

typedef struct      s_hash
{
	int             hash_first;
	int             hash_second;
}                   t_hash;

typedef struct      s_room
{
	int             index;
	int             hash;
	int             x_coord;
	int             y_coord;
	int             part;
	char            *name;
	t_links         *links;
	int             links_len;
}                   t_room;

struct              s_links
{
	t_room                 *link;
	struct s_links         *next;
};

typedef struct      s_lemin
{
	int             ant_count;
	t_room          *rooms;
	int             rooms_len;
	int             start_links;
	int             start_rooms;
	int             start;
	int             end;
}                   t_lemin;

int		ft_atoi_push(char *str, int *i, int *ower);
int lets_read(void);
int         init_lemin(t_lemin *lemin, char **spl);
int     take_ants(t_lemin *lemin, char **spl);
int     take_rooms(t_lemin *lemin, char **spl);
int     take_links(t_lemin *lemin, char **spl);
int     hash_my_name(char *str, int start, int border);
int     create_link_in_room(t_lemin *lemin, t_hash hash_found);

#endif
