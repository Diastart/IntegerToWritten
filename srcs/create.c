#include "../includes/includes.h"

char *remove_spaces(char *str)
{
	int i = 0, j = 0;
	char *new_str = malloc(ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] != ' ')
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*new;

	len = 0;
	while (s[len])
		len++;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

t_dict	*create_structure(char *filename, int number_of_lines)
{
	int		fd;
	t_dict	*dict;
	char	c;
	char	*sep;
	char	line[1024];
	int		line_pos;
	int		index;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error opening file\n");
		return (NULL);
	}
	dict = malloc(sizeof(t_dict) * (number_of_lines));
	if (dict == NULL)
	{
		ft_putstr("Memory allocation failed\n");
		return (NULL);
	}
	line_pos = 0;
	index = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c != '\n')
			line[line_pos++] = c;
		else
		{
			line[line_pos] = '\0';
			sep = line;
			while (*sep && *sep != ':')
				sep++;
			if (*sep == ':')
			{
				*sep = '\0';
				dict[index].index = remove_spaces(ft_strdup(line));
				dict[index].value = remove_spaces(ft_strdup(sep + 1));
				index++;
			}
			line_pos = 0;
		}
	}
	dict[index].index = NULL;
	dict[index].value = NULL;
	close(fd);
	return (dict);
}

int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	buffer[1024];
	ssize_t	bytes_read;
	ssize_t	i;

	fd = open (filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error opening file\n");
		return (-1);
	}
	count = 0;
	bytes_read = read (fd, buffer, 1024);
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
		if (bytes_read == -1)
		{
			ft_putstr("Error reading file\n");
			close (fd);
			return (-1);
		}
		bytes_read = read (fd, buffer, 1024);
	}
	close (fd);
	return (count);
}

t_dict	*createDict(char *filename)
{
	t_dict	*head;
	int		number_of_lines;

	number_of_lines = count_lines(filename);
	if (number_of_lines < 0)
	{
		return (NULL);
	}
	head = create_structure(filename ,number_of_lines);
	return (head);
}
