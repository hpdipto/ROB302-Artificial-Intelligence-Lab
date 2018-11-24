#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int>edges[50];
queue< vector<int> >paths;

bool inPath(vector<int>path, int node)
{
	int len = path.size();
	for(int i = 0; i < len; i++) {
		if(path[i] == node)
			return false;
	}
	return true;
}

void bfs(vector<int>graph[], int source, int goal)
{
	vector<int>p;
	p.push_back(source);
	int len = graph[source].size();
	for(int i = 0; i < len; i++) {
		p.push_back(graph[source][i]);
		paths.push(p);
		p.pop_back();
	}
		
	while(!paths.empty()) {
		p = paths.front();
		len = p.size();
		int lastNode = p.back();
		if(lastNode == goal) {
			len = p.size();
			for(int j = 0; j < len; j++)
				cout << p[j] << " ";
			cout << endl;
			paths.pop();
			continue;
		}
		len = graph[lastNode].size();
		for(int i = 0; i < len; i++) {
			int node = graph[lastNode][i];
			if(inPath(p, node)) {
				p.push_back(node);
				paths.push(p);
				p.pop_back();
			}
		}
		paths.pop();
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
	
	bfs(edges, 1, 8);
	
	return 0;
}
