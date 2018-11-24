#include <cstdio>
#include <iostream>
using namespace std;

int grid[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int depth, alpha, beta, branchingFactor = 9;
//int solution;
int winingHeuristic, losingHeuristic, losingStateIndex, winingStateIndex;
int flag;
int solve;

void alphaBeta(int player, int mainPlayer);
bool gameOver();
int nextPossibleGrid();
int winOrLose(int player);
void printGrid();

bool specialTest();


int main()
{
	int userInput, option, possibleMove = 1;


	// grid[3] = 1;
	// grid[5] = 0;
	// grid[7] = 1;

	// grid[3] = 1;
	// grid[5] = 0;
	// grid[7] = 1;
	// grid[4] = 0;
	// grid[6] = 1;
	// grid[9] = 0;
	// grid[1] = 1;



	losingHeuristic = winingHeuristic = 10;


	grid[1] = 0;
	grid[7] = 0;
	grid[5] = 1;
	grid[9] = 1;

	//grid[3] = 1;

	 alphaBeta(1, 1 , 5, 1);

	cout << solve << endl;

	return 0;
}


void alphaBeta(int player, int mainPlayer)
{
	if(!winOrLose(player) && gameOver()) {
		return ;
	}
	if(winOrLose(player)) {
		//we always get the losing result here
		if(player == mainPlayer) {
			flag = 1;
		}
		if(player != mainPlayer) {

		}
		return;
	}

	int i;
	for(i = 1; i <= 9; i++) {
		if(grid[i] == -1) {
			grid[i] = player;
			alphaBeta(!player, mainPlayer)
		}
	}
}


bool gameOver()
{
	for(int i = 0; i < 3; i++)
		for(int j = 1; j <= 3; j++)
			if(grid[(3*i)+j] == -1)
				return false;
	return true;
}

int nextPossibleGrid()
{
	for(int i = 0; i < 3; i++)
		for(int j = 1; j <= 3; j++)
			if(grid[(3*i)+j] == -1)
				return (3*i)+j;
	return -1;
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

void printGrid()
{
	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 1; j <= 3; j++) {
			printf(" ");

			if(grid[(3*i)+j] != -1) {
				if(grid[(3*i)+j] == 1)
					printf("x");
				else
					printf("o");
			}
			else
				printf(" ");

			if(j != 3)
				printf(" |");
		}
		if(i != 2)
			printf("\n- - - - - -\n");
	}
	printf("\n");
}



bool specialTest()
{
	if( grid[1] == 0 &&
		grid[2] == -1 &&
		grid[3] == -1 &&
		grid[4] == 1 &&
		grid[5] == 1 &&
		grid[6] == -1 &&
		grid[7] == 0 &&
		grid[8] == -1 &&
		grid[9] == 1)
		return true;
		//printGrid();
	else
		return false;
}
