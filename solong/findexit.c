#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

# ifndef MAPL
#  define MAPL 80
# endif

# ifndef MAPH
#  define MAPH 40
#endif

# ifndef STARTX
#  define STARTX 1
#endif

# ifndef STARTY
#  define STARTY 1
#endif

typedef struct exitspot {
	int x;
	int y;
} exitspot;

void fill_walls(char map[MAPL][MAPH])
{
	int x = 0;
	int y = 0;

	while(x < MAPL)
		map[x++][0] = 'H';
	x = 0;
	while(x < MAPL)
		map[x++][MAPH - 1] = 'H';
	x = 0;

	while(y < MAPH)
		map[0][y++] = 'H';
	y = 0;
	while(y < MAPH)
		map[MAPL - 1][y++] = 'H';
}

void print_map(char map[MAPL][MAPH])
{
	int x = 0;
	int y = 0;
	while(y < MAPH)
	{
		while(x < MAPL)
			printf("%c", map[x++][y]);
		x = 0;
		printf("\n");
		y++;
	}
}


void fill_map(char map[MAPL][MAPH])
{
	int x = 0;
	int y = 0;
	while(y < MAPH)
	{
		while(x < MAPL && map[x][y] != 'S')
			map[x++][y] = '_';
		x = 0;
		y++;
	}
}

void fill_rnd(char map[MAPL][MAPH])
{
	srand(time(NULL));   // Initialization, should only be called once.
	//printf("%d\n", (rand() % 5));
	(void)map;

	int x = 1;
	int y = 1;
	while(y < MAPH - 1)
	{
		while(x < MAPL - 1 && map[x][y] != 'S')
		{
			if ((rand() % 4) == 3)
				map[x][y] = 'W';
			x++;
		}
		x = 1;
		y++;
	}

}

int floodfill(char map[MAPL][MAPH],int  x,int y)
{
	//print_map(map);
	if (map[x][y] == 'X')
		return(1);
	map[x][y] = 'F';
	if ((map[x + 1][y] == 'X') && (floodfill(map, x + 1, y)))
		return (1);
	else if ((map[x][y + 1] == 'X') && (floodfill(map, x, y + 1)))
		return (1);
	else if ((map[x - 1][y] == 'X') && (floodfill(map, x - 1, y)))
		return (1);
	else if ((map[x][y - 1] == 'X') && (floodfill(map, x, y - 1)))
		return (1);
	else if ((map[x + 1][y] == '_') && (floodfill(map, x + 1, y)))
		return (1);
	else if ((map[x][y + 1] == '_') && (floodfill(map, x, y + 1)))
		return (1);
	else if ((map[x - 1][y] == '_') && (floodfill(map, x - 1, y)))
		return (1);
	else if ((map[x][y - 1] == '_') && (floodfill(map, x, y - 1)))
		return (1);
		return(0);
}

int	main(void)
{
	char map[MAPL][MAPH] = {0};


	exitspot exitpoint;

	exitpoint.x = 5;
	exitpoint.y = 5;

	printf("exit is located at coordinates y = %d, x = %d.\n\n", exitpoint.y, exitpoint.x);
	//print_map(map);
	//printf("\n");
	fill_map(map);
	print_map(map);
	printf("\n");
	fill_walls(map);
	print_map(map);
	printf("\n");
	fill_rnd(map);
	print_map(map);
	printf("\n");
	map[STARTX][STARTY] = 'S';
	// map[MAPL - STARTX - 1][MAPH - STARTY - 1] = 'X'; // map in bottom right
	map[MAPL - (MAPL / 2)][MAPH - (MAPH / 2)] = 'X'; // map in middle
	print_map(map);
	
	printf("%d\n", floodfill(map, STARTX, STARTY));
	print_map(map);
}

