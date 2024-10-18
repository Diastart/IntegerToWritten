#include "../includes/includes.h"

int	count_lines(char *path)
{
	int		count;
	int		fd;
	int		i;
	size_t	buffer_size;
	ssize_t	bytes_read;
	char	*buffer;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open error\n");
		return (0);
	}
	buffer_size = 1024;
	buffer = (char *)malloc(buffer_size + 1);
	if (!buffer)
	{
		ft_putstr("Memory allocation failed\n");
		return (0);
	}
	count = 0;
	bytes_read = read(fd, buffer, buffer_size);
	while (bytes_read > 0)
	{
		i = 0;
		buffer[buffer_size] = '\0';
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
		bytes_read = read(fd, buffer, buffer_size);
	}
	if (bytes_read == -1)
		ft_putstr("Read error\n");
	free(buffer);
	close(fd);
	return (count);
}

t_dict	**createDict(char *path)
{
	int	nlines;
	t_dict	**dictionary;

	nlines = count_lines(path);
	if (nlines == 0)
		return (NULL);
	dictionary = (t_dict **)malloc(sizeof(t_dict *) * (nlines + 1));
	if (!dictionary)
	{
		ft_putstr("Memory allocation failed\n");
		return (NULL);
	}
	dictionary[nlines] = NULL;
	while (i < nlines)
	{
		dictionary[i] = createStruct(path);
	}
}















