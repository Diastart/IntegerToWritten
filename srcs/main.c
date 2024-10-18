#include "../includes/includes.h"

int	main(int ac, char **av)
{
	if (ac == 3)
		launch(av[1], av[2]);
	else
		ft_putstr("Incorrect input, for correct type look up in README file.\n");
	return (0);
}
