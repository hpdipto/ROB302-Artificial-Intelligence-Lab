#include <iostream>
#include "priorityQueue.cpp"
using namespace std;

struct nodePathCost {
	int node, pathCost;
};

int main()
{
	priorityQueue<nodePathCost>pq;
	nodePathCost npc;
	
	for(int i = 0; i < 5; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		npc.node = x;
		npc.pathCost = y;
		pq.enqueu(npc);
	}
	
	cout << endl << endl;
	
	while(!pq.isEmpty()) {
		npc = pq.front();
		cout << npc.node << " " << npc.pathCost << endl;
		pq.dequeu();
	
	}
	
	
	return 0;
}
