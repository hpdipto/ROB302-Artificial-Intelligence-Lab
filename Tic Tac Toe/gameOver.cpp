#include <cstdio>
#include <iostream>
using namespace std;

int grid[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int winOrLose(int player);
bool gameOver();

int main()
{
	grid[1] = 1, grid[2] = 0, grid[3] = 1;
	grid[4] = 0, grid[5] = 1, grid[6] = -1;
	grid[7] = -1, grid[8] = -1, grid[9] = -1;
	cout << winOrLose(0) << endl;

	return 0;
}


int winOrLose(int player)
{
	int i;
	for(i = 1; i <= 9; i+=3) {
		if((grid[i] == grid[i+1]) && (grid[i+1] == grid[i+2]) && (grid[i] == player))
			return 1;
		else if((grid[i] == grid[i+1]) && (grid[i+1] == grid[i+2]) && (grid[i] == !player)) 
			return -1;
	}
	for(i = 1; i <= 3; i++) {
		if((grid[i] == grid[i+3]) && (grid[i+3] == grid[i+6]) && (grid[i] == player))
			return 1;
		else if((grid[i] == grid[i+3]) && (grid[i+3] == grid[i+6]) && (grid[i] == !player)) 
			return -1;
	}
	if((grid[1] == grid[5]) && (grid[5] == grid[9]) && (grid[1] == player))
		return 1;
	if((grid[1] == grid[5]) && (grid[5] == grid[9]) && (grid[1] == !player))
		return -1;
	if((grid[3] == grid[5]) && (grid[5] == grid[7]) && (grid[3] == player))
		return 1;
	if((grid[3] == grid[5]) && (grid[5] == grid[7]) && (grid[3] == !player))
		return -1;
	return 0;
}

bool gameOver()
{
	for(int i = 0; i < 3; i++) 
		for(int j = 1; j <= 3; j++)
			if(grid[(3*i)+j] == -1)
				return false;
	return true;
}

