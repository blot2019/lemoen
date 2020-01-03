//
// Created by Grass Emerald on 01/01/2020.
//

#include "lemin.h"

void    fill_sqr_table(int sqr_table[])
{
	int i;

	i = 0;
	sqr_table[i++] = 97;
	while (i < 100)
	{
		sqr_table[i] = sqr_table[i - 1] * 97;
		i++;
	}
}

int     hash_my_name(char *str, int start, int border)
{
	int len;
	int hash;
	int i;
	static int sqr_table[100];

	if (!sqr_table[0])
		fill_sqr_table(sqr_table);
	i = 0;
	len = border - start;
	hash = 0;
	while(start < border)
	{
		if (i > 99)
			i = 0;
		hash += (str[start++] * sqr_table[i++]);
	}
	hash %= 4096;
	return (hash);
}