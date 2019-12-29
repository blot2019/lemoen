//
// Created by Grass Emerald on 24/12/2019.
//

#include "lemin.h"

int err_out(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}



int main(int ac, char **av)
{
	if (!lets_read())
		return (err_out());
	return (0);
}