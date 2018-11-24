#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX 1000

vector<int>edges[MAX];
vector<int>visited, parent;
vector<int>frontier;
int depth;

int DFSr(vector<int>graph[], int source, int goal)
{	
	depth++;
	if(source == goal)
		return depth;
	int temp;
		
	int generatedNodeSize = graph[source].size();
	visited[source] = 1;
	for(int i = 0; i < generatedNodeSize; i++) {
		if(!visited[graph[source][i]]) {
			int top = graph[source][i];
			parent[top] = source;
			temp = DFSr(graph, top, goal);
			if(temp != -1) {
				depth = temp;
				return depth;
			}
			else
				--depth;
		}
	}
	return -1;
}

void pathPrinting(vector<int>graph[], int source, int goal)
{
	if(DFSr(graph, source, goal) != -1) {
		vector<int>path;
		path.push_back(goal);
		while(goal != source) {
			goal = parent[goal];
			path.push_back(goal);
		}
		int size = path.size(), i;
		for(i = size - 1; i > 0; i--)
			cout << path[i] << " -> ";
		cout << path[i] << endl;
	}
	else {
		cout << "No path is possible!" << endl;
	}
			
}


int main()
{
	int N, E, i;
	
	scanf("%d%d", &N, &E);
	for(i = 1; i <= E; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	visited.resize(MAX);
	parent.resize(MAX);
	pathPrinting(edges, 7, 4);
	//pathPrinting(edges, 3, 5);
	//pathPrinting(edges, 9, 3);
	//pathPrinting(edges, 9, 6);
	
	return 0;
}
