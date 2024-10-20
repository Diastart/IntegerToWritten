#include "../includes/includes.h"

void	display(t_dict *dictionary, char *number)
{
	int	i;
	int	length;

	length = ft_strlen(number);
	i = 1;
	while (i <= ((length / 3) + 1))
		spell(number + (length - (i++) * 3));
}
