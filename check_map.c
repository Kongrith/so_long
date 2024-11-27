#include "so_long.h"

void create_map(t_data *data, char argv[])
{
	int i;
	int fd;
	char *line;

	i = 0;
	line = NULL;
	fd = open(argv, O_RDONLY);
	// line = get_next_line(fd);
	// if (line != NULL)
	// 	data->map[0] = line;
	// printf("%d\n", data->row);
	while (i < data->row)
	{
		line = get_next_line(fd);
		data->map[i] = line;
		// printf("[%d]%s", i, line);
		i++;
		// if (line != NULL)
		// {
		// 	data->map[i] = line;
		// 	printf("[%d]%s", i, line);
		// 	i++;
		// }
	}
	data->map[i] = '\0';
}

void read_map(t_data *data, char argv[])
{
	// int i;
	int fd;
	char *line;

	// i = 0;
	line = NULL;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		data->row += 1;
	}
	data->map = (char **)malloc(sizeof(char *) * (data->row + 1));
}

void check_map(t_data *data, char argv[])
{
	data->moves = 0;
	data->row = 0;
	data->col = 0;
	data->map = NULL;

	read_map(data, argv);
	create_map(data, argv);

	ft_printf("%s", data->map[0]);
	ft_printf("%s", data->map[1]);
	ft_printf("%s", data->map[2]);
	ft_printf("%s", data->map[3]);
	ft_printf("%s", data->map[4]);
	ft_printf("%s", data->map[5]);
}
