#include "../includes/includes.h"

void	launch(char *language, char *number)
{
	t_dict	*dictionary;

	if (ft_strcmp("english", language) == 0)
		dictionary = createDict("../data/english.dict");
	else if (ft_strcmp("spanish", language) == 0)
		dictionary = createDict("../data/spanish.dict");
	else if (ft_strcmp("french", language) == 0)
		dictionary = createDict("../data/french.dict");
	else if (ft_strcmp("german", language) == 0)
		dictionary = createDict("../data/german.dict");
	else
	{
		ft_putstr("language is provided incorrectly!\n");
		return ;
	}
	display(number, dictionary);
}
