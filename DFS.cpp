#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

#define MAX 1000

vector<int>edges[MAX];
vector<int>visited, parent;
stack<int>frontier;

int DFS(vector<int>graph[], int source, int goal)
{
	parent.resize(MAX);    //tracking the parents
	visited.resize(MAX);   //visited[3]  -- will store on which level we visit node 3, when we mark it as visited.
						   // when initialize it, it will be initialized to its previous level
	frontier.push(source); //typical frontier, so we push source
	
	while(true) {
		int top = frontier.top();
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
	
	cout << DFS(edges, 1, 7);
	
	return 0;
}
