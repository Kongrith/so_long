#include "so_long.h"

/*
There will be 1 exit, 1 player and at least 1 collectible item
*/
void read_EPC(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->col)
		{
			if (data->map[i][j] != 'E' && data->map[i][j] != 'P' && data->map[i][j] != 'C' && data->map[i][j] != '0' && data->map[i][j] != '1')
				err_handler("No EPC\n");
			if (data->map[i][j] == 'E')
				data->exit += 1;
			if (data->map[i][j] == 'P')
				data->player += 1;
			if (data->map[i][j] == 'C')
				data->collect += 1;
			j++;
		}
		i++;
	}
	if (data->exit != 1)
		err_handler("Exit Not Equal to 1\n");
	if (data->player != 1)
		err_handler("Player Not Equal to 1\n");
	if (data->collect == 0)
		err_handler("Collectable at least 1\n");
}

void get_column(t_data *data)
{
	int i;
	int prev_col;
	int current_col;

	i = 0;
	while (i < data->row)
	{
		if (i == 0)
			prev_col = ft_strlen(data->map[i]) - 1;
		else
		{
			current_col = ft_strlen(data->map[i]) - 1;
			if (current_col == prev_col)
				prev_col = current_col;
			else
				err_handler("column not equal\n");
		}
		i++;
	}
	data->col = current_col;
}

void read_map(t_data *data, char argv[])
{
	int i;
	int fd;
	char *line;

	line = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		err_handler("No FILE\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		data->row += 1;
	}
	data->map = (char **)malloc(sizeof(char *) * (data->row + 1));
	fd = open(argv, O_RDONLY);
	i = 0;
	while (i < data->row)
	{
		line = get_next_line(fd);
		data->map[i] = line;
		i++;
	}
	data->map[i] = '\0';
	get_column(data);
}

void init_map(t_data *data, char argv[])
{
	read_map(data, argv);
	read_EPC(data);
}
