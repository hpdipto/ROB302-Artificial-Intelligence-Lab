#include <cstdio>
#include <iostream>
using namespace std;

int grid[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int depth, alpha, beta, branchingFactor = 9;
int solution;
int winingHeuristic, losingHeuristic, losingStateIndex, winingStateIndex;

int minimax(int, int);
bool gameOver();
int test(int);
int result(int player);
void printGrid();


int main()
{
	int userInput, option, possibleMove = 1;


	cout << "Chose an option:\n";
	cout << "  1. CPU First\n";
	cout << "  2. Human First\n";
	cin >> option;

	while(1) {
		if(option == 1) {
			cout << "CPU: " << endl;
			grid[possibleMove] = 0;
			option = 0;
			printGrid();
			cout << endl << endl;;
		}
		cout << "Enter a grid number: ";
		cin >> userInput;
		grid[userInput] = 1;
		cout << "Human: " << endl;
		printGrid();
		cout << endl << endl;

		grid[test(0)] = 0;

		cout << "CPU: " << endl;
		printGrid();
		cout << endl << endl;

		if(result(0) == 1) {
			cout << "CPU won!" << endl;
			break;
		}
		if(gameOver() && result(0) == 0) {
			cout << "Match draw!" << endl;
			break;
		}
	}

	return 0;
}


int minimax(int player, int mainPlayer)
{
    if(!result(player) && gameOver())
        return 0;
    if(result(player)) {
        //we always get losing result here
        if(player == mainPlayer)
            return -1;
        else
            return 1;
    }


    int v, i;
    if(player == mainPlayer) {
        v = -5;
        for(i = 1; i <= 9; i++) {
            if(grid[i] == -1) {
                grid[i] = player;
                v = max(v, minimax(!player, mainPlayer));
                grid[i] = -1;
            }
        }
        return v;
    }
    else {
        v = 5;
        for(i = 1; i <= 9; i++) {
            if(grid[i] == -1) {
                grid[i] = player;
                v = min(v, minimax(!player, mainPlayer));
                grid[i] = -1;
            }
        }
        return v;
    }
}

int test(int player)
{
    int v = -5, i, move;
    for(i = 1; i <= 9; i++) {
        if(grid[i] == -1) {
            grid[i] = player;
            int v2 = minimax(!player, player);
            grid[i] = -1;
            if(v2 > v) {
                v = v2;
                move = i;
            }
        }
    }
    return move;
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
	printf("\n");
}
