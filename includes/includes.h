#ifndef INCLUDES_H
# define INCLUDES_H
# include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_dict
{
	char	*index;
	char	*value;
}				t_dict;

void	ft_putnbr(int nbr);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(char c);
void	ft_putstr(char *str);
t_dict	*createDict(char *path);
void	launch(char *language, char *number);

#endif
