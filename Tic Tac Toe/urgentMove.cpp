#include <cstdio>
#include <iostream>
using namespace std;


int grid[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};


int urgentMove(int player);
int winOrLose(int player);


int main()
{
	grid[1] = 1;
	cout << urgentMove(1);
}


int urgentMove(int player)
{
	int i, j;

	for(i = 0; i < 3; i++) {
		for(j = 1; j <= 3; j++){
			if(grid[(3*i)+j] == -1) {
				grid[(3*i)+j] = player;
				if(winOrLose(player)) {
					grid[(3*i)+j] = -1;
					return (3*i)+j;
				}
				grid[(3*i)+j] = -1;
			}
		}
	}

	for(i = 0; i < 3; i++) {
		for(j = 1; j <= 3; j++){
			if(grid[(3*i)+j] == -1) {
				grid[(3*i)+j] = !player;
				if(winOrLose(!player)) {
					grid[(3*i)+j] = -1;
					return (3*i)+j;
				}
				grid[(3*i)+j] = -1;
			}
		}
	}

	return -1;
}


int winOrLose(int player)
{
	int i;
	for(i = 1; i <= 9; i+=3) {
		if(grid[i] == grid[i+1] && grid[i+1] == grid[i+2] && grid[i] != -1)
			if(grid[i] == player)
				return 1;
			else
				return -1;
	}
	for(i = 1; i <= 3; i++) {
		if(grid[i] == grid[i+3] && grid[i+3] == grid[i+6] && grid[i] != -1)
			if(grid[i] == player)
				return 1;
			else
				return -1;
	}
	for(i = 1; i <= 3; i+=2) {
		if(grid[i] == grid[i+4] && (grid[i+4] == grid[i+8]) && grid[i] != -1)
			if(grid[i] == player)
				return 1;
			else
				return -1;
	}
	return 0;
}
