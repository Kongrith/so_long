#include "so_long.h"

/*
Encodes four individual bytes into an int.
*/
int get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void err_handler(char *cmd_failure)
{
	write(1, cmd_failure, ft_strlen(cmd_failure));
	exit(EXIT_FAILURE);
}



// void chk_input(char argv[])
// {
// 	printf("%s", argv);
// }
