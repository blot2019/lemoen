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
	char            *first_name;
	int             hash_second;
	char            *second_name;
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
	int                     dead;
	struct s_links         *next;
};

typedef struct      s_hash_table
{
	t_room              *link;
	struct s_hash_table *next;

}                   t_hash_table;

typedef struct      s_way
{
	t_links         *ways;
	int             way_count;
	int             step_on_way;
	int             step_lvl;
	struct s_way    *next;
	struct s_way    *prev;
}                   t_way;

typedef struct      s_lemin
{
	int             ant_count;
	t_room          *rooms;
	t_hash_table    *table_hashes[4096];
	int             rooms_len;
	int             start_links;
	int             start_rooms;
	int             start;
	int             end;
	t_way           path;
	char            **initial_text;
}                   t_lemin;



int		ft_atoi_push(char *str, int *i, int *ower);
char			**ft_strsplit_lem(char const *str, char c);
int     lets_read(t_lemin *lemin);
int         init_lemin(t_lemin *lemin, char **spl);
int     take_ants(t_lemin *lemin, char **spl);
int     take_rooms(t_lemin *lemin, char **spl);
int     take_links(t_lemin *lemin, char **spl);
int     hash_my_name(char *str, int start, int border);
int     create_link_in_room(t_lemin *lemin, t_hash hash_found);
void    null_pointer_upload(t_lemin *lemin);
void    hash_table_upload(t_lemin *lemin);
int     err_out(void);
void        free_for_all(t_lemin *lemin);
void    del_list_links(t_links **begin_list);
int         check_rooms(t_lemin *lemin);

#endif
