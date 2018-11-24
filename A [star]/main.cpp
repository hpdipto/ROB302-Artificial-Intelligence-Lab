#include <iostream>
#include <vector>
#include <string>
#include "priorityQueue.cpp"
using namespace std;

struct nodePathCost {
    int node, pathCost;
};


vector<int>edges[50];
vector<int>cost[50];
int nodeCost[50];
int visited[50];
int heuristic[50];
vector<string> strNode;

int stringIndexMapping(string str)
{
	int i, len = strNode.size();
	for(i = 0; i < len; i++) {
		if(str == strNode[i])
			return i;
	}
	strNode.push_back(str);
	return i;
}

int main()
{
    int N, E;
    int source, goal;
    string strInput;

    freopen("input.txt", "r", stdin);

    scanf("%d%d",  &N, &E);
    
    for(int i = 1; i <= N; i++) {
		cin >> strInput >> E;
		int parent = stringIndexMapping(strInput), c, child;
		for(int j = 1; j <= E; j++) {
			cin >> strInput >> c;
			child = stringIndexMapping(strInput);
			edges[parent].push_back(child);
			//edges[child].push_back(parent);
			cost[parent].push_back(c);
			//cost[child].push_back(c);
		}
		cin >> E;
		nodeCost[parent] = E;
		heuristic[parent] = E;
	}


    scanf("%d%d", &source, &goal);
    priorityQueue<nodePathCost> frontier, f2;
    nodePathCost npc;


    npc.node = source;
    npc.pathCost = 0 + heuristic[npc.node];
    frontier.enqueu(npc);
    
    while(!frontier.isEmpty()) {
        nodePathCost frontNode = frontier.front();

        int node, nCost, len;
        node = frontNode.node;
        nCost = frontNode.pathCost;
        len = edges[node].size();
        frontier.dequeu();
        visited[node] = 1;
        for(int i = 0; i < len; i++) {
            npc.node = edges[node][i];
            npc.pathCost = nCost + cost[node][i] + heuristic[npc.node];
            if(visited[npc.node])
                continue;

            if((nodeCost[npc.node] == heuristic[npc.node]) || (npc.pathCost < nodeCost[npc.node])) {
                nodeCost[npc.node] = npc.pathCost;
				frontier.enqueu(npc);
			}
        }
    }

    for(int i = 0; i < N; i++)
        cout << strNode[i] << " = " << nodeCost[i] << "      ";

    return 0;
}
