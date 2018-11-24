#include <cstdio>
#include <iostream>
using namespace std;

int grid[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

void printGrid();

int main()
{
	grid[2] = 1;
	grid[5] = 0;
	grid[4] = 0;
	grid[1] = 1;
	grid[7] = 1;
	printGrid();

	cout << endl << endl;

	return 0;
}


void printGrid()
{
	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 1; j <= 3; j++) {
			printf(" ");

			if(grid[(3*i)+j] != -1)
				printf("%d", grid[(3*i)+j]);
			else
				printf(" ");

			if(j != 3)
				printf(" |");
		}
		if(i != 2)
			printf("\n- - - - - -\n");
	}
}