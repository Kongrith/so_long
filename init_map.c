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
	int i;
	int fd;
	char *line;

	i = 0;
	line = NULL;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		data->row += 1;
	}
	data->map = (char **)malloc(sizeof(char *) * (data->row + 1));
	fd = open(argv, O_RDONLY);
	line = NULL;
	while (i < data->row)
	{
		line = get_next_line(fd);
		data->map[i] = line;
		i++;
	}
	data->map[i] = '\0';
	data->col = data->row;
}

void init_map(t_data *data, char argv[])
{
	void *mlx;

	read_map(data, argv);
	mlx = mlx_init(WIDTH*data->col, HEIGHT*data->row, "Cat Me If U Can", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	data->mlx = mlx;

	ft_printf("%s", data->map[0]);
	ft_printf("%s", data->map[1]);
	ft_printf("%s", data->map[2]);
	ft_printf("%s", data->map[3]);
	ft_printf("%s", data->map[4]);
	ft_printf("%s", data->map[5]);
}
