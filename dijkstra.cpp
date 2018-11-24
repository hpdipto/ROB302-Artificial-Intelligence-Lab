#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int>edges[50], costVector[50];
int visited[50];
int cost[50];
queue<int>costQ, nodeQ;

void parallelSorting()
{
	queue<int>n, c;
	vector<int>nv, cv, cv2;
	n = nodeQ;
	c = costQ;
	while(!n.empty()) {
		nv.push_back(n.front());
		cv.push_back(c.front());
		n.pop();
		c.pop();
	}
	cv2 = cv;
	sort(cv.begin(), cv.end());
	
	int len = cv.size();
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len; j++) {
			if(cv[i] == cv2[j]) {
				n.push(nv[j]);
				c.push(cv[i]);
				cv2[j] = -1;
				break;
			}
		}
	}
	nodeQ = n;
	costQ = c;
}

void dijkstra(vector<int>graph[], int source, int goal)
{
	cost[source] = 0;
	costQ.push(cost[source]);
	nodeQ.push(source);
	int solution = 0;
	
	while(!nodeQ.empty()) {
		int top = nodeQ.front();
		cout << top << ": " << cost[top] << endl;
		int len = graph[top].size();
		if(visited[top]) {
			nodeQ.pop();
			costQ.pop();
			continue;
		}
		for(int i = 0; i < len; i++) {
			int node = graph[top][i];
			if(visited[node])
				continue;
			if((cost[node] == 0) || (cost[top]+costVector[top][i] < cost[node])) {
				costQ.push(cost[top]+costVector[top][i]);
				cost[node] = cost[top] + costVector[top][i];
				nodeQ.push(node);
			}
		}
		if(top == goal) {
			cout << cost[top] << endl;
			solution = 1;
			break;
		}
		nodeQ.pop();
		costQ.pop();
		visited[top] = 1;
		parallelSorting();
	}
	if(!solution)
		printf("No solutions\n");
}


int main()
{
	int N, E, i;
	
	scanf("%d%d", &N, &E);
	for(i = 1; i <= E; i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		edges[x].push_back(y);
		edges[y].push_back(x);
		costVector[x].push_back(c);
		costVector[y].push_back(c);
	}
	
	dijkstra(edges, 1, 9);
	
	return 0;
}
