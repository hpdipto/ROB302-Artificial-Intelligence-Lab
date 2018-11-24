#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000

vector<int>edges[MAX];
vector<int>parent, visited;
queue<int> frontier;

int BFS(vector<int>graph[], int source, int goal)
{
	parent.resize(MAX);    //tracking the parents
	visited.resize(MAX);   //visited[3]  -- will store on which level we visit node 3, when we mark it as visited.
						   // when initialize it, it will be initialized to its previous level
	frontier.push(source); //typical frontier, so we push source
	
	while(true) {
		int top = frontier.front();
		frontier.pop();
		visited[top]++;   //by incrementing this, we reach to the current level of 'top'
		
		if(top == goal) {
			return visited[top];
		}
		
		int generatedNodesSize = graph[top].size();
		for(int i = 0; i < generatedNodesSize; i++) {
			if(!visited[graph[top][i]]) {				
				frontier.push(graph[top][i]);
				parent[graph[top][i]] = top;
				visited[graph[top][i]] = visited[top];   //here visited stores its parent's level
			}
		}
		
		if(frontier.size() == 0) {
			return 0;
		}
	}
}

void printPath(vector<int>graph[], int source, int goal)
{
	if(BFS(graph, source, goal)) {
		vector<int>printing;
		printing.push_back(goal);
		while(goal != source) {
			goal = parent[goal];
			printing.push_back(goal);
		}
		for(int i = printing.size()-1; i > 0; i--)
			cout << printing[i] << " -> ";
		cout << printing[0] << endl;
	}
	else
		cout << "No solution!" << endl;
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
	
	printPath(edges, 3, 8);
	
	return 0;
}


/*
 
 12 12
 1 2
 1 4
 1 3
 2 6
 4 7
 3 8
 6 10
 7 9
 8 5
 11 12
 3 7
 7 8
 * 
 * 

10 10
3 4
3 7
4 1
4 2
4 6
7 5
6 9
5 10
9 8
10 8

8 7
3 7
3 2
7 5
5 4
6 1
1 9
2 7 

 
 */
