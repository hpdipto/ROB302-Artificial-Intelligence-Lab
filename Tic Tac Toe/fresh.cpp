#include <cstdio>
#include <iostream>
using namespace std;

int grid[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int move, alpha, beta;


int minimax(int player, int mainPlayer);
bool gameOver();
int result(int player);
int test(int player);
void printGrid();


int main()
{

    //grid[2] = 0;
    grid[3] = 1;
    //grid[3] = 1;
    // grid[5] = 1;
    // grid[7] = 0;
    // grid[9] = 1;

    int result = test(0);
    cout << result << endl;

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
	for(int i = 1; i <= 9; i++)
        if(grid[i] == -1)
            return false;
	return true;
}

int result(int player)
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
    for(int i = 1; i <= 9; i++) {
        printf(" ");
        if(grid[i] == 1)
			printf("x");
        else if(grid[i] == 0)
            printf("o");
		else
			printf(" ");

		if(i % 3 != 0)
			printf(" |");

		if(i % 3 == 0 && i != 9)
			printf("\n- - - - - -\n");
	}
	printf("\n\n");
}
