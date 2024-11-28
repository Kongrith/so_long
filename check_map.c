#include "so_long.h"

void check_wall(t_data *data)
{
	(void)data;
}

void check_valid_path(t_data *data)
{
	(void)data;
}

void check_size(t_data *data)
{
	if (data->col == data->row)
		err_handler("No EPC\n");
	if (data->col <= 2 || data->row <= 2)
		err_handler("No EPC\n");
}

void check_map(t_data *data)
{
	check_size(data);
	check_wall(data);
	check_valid_path(data);
}
