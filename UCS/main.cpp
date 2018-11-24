#include <iostream>
#include <vector>
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

int main()
{
    int N, E;
    int source, goal;

    freopen("inputQ.txt", "r", stdin);

    scanf("%d%d",  &N, &E);
    for(int i = 1; i <= E; i++) {
        int x, y, c, h;
        scanf("%d%d%d", &x, &y, &c);
        edges[x].push_back(y);
        edges[y].push_back(x);
        cost[x].push_back(c);
        cost[y].push_back(c);
    }

    scanf("%d%d", &source, &goal);
    priorityQueue<nodePathCost> frontier, f2;
    nodePathCost npc;


    npc.node = source;
    npc.pathCost = 0;

    frontier.enqueu(npc);
    nodeCost[source] = 0;
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
            npc.pathCost = cost[node][i] + nCost;
            if(visited[npc.node])
                continue;

            if((nodeCost[npc.node] == 0) || (npc.pathCost < nodeCost[npc.node])) {
                nodeCost[npc.node] = npc.pathCost;
				frontier.enqueu(npc);
			}
        }
    }

    for(int i = 1; i <= N; i++)
        cout << nodeCost[i] << " ";

    return 0;
}
