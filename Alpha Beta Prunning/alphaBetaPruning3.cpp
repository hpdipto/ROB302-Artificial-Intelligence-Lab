#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int depth, branchingFactor, terminal[50], alpha, beta;

int alphaBeta(int d, int index)
{
	if(d == depth)
		return terminal[index];

	int j = (index*branchingFactor), v, intermediateMax, intermediateMin;
	if(d % 2 == 0) {
		v = -100000, alpha = -100000, intermediateMax = -100000;
		for(int i = j; i < (j+branchingFactor); i++) {
			alpha = max(v, alphaBeta(d+1, i));
			if(v < alpha)
				v = alpha;

			if(v >= intermediateMax)   //prunning happened here!
				intermediateMax = v;
			else
				break;
		}
	}
	else {
		v = 100000, beta = 100000, intermediateMin = 100000;
		for(int i = j; i < (j+branchingFactor); i++) {
			beta = min(v, alphaBeta(d+1, i));
			if(v > beta)
				v = beta;

			if(v <= intermediateMin)   //prunning happened here!
				intermediateMin = v;
			else
				break;
		}
	}
	return v;
}


int main()
{
	int i;

	//result for default inpute file is    2
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &depth, &branchingFactor);
	for(i = 0; i < (int)pow(branchingFactor, depth); i++)
		scanf("%d", &terminal[i]);

	cout << alphaBeta(0, 0) << endl;

	return 0;
}
