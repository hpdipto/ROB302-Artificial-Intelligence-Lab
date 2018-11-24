#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


string cities[50];
int index = 0;



vector<int>edges[50], costVector[50];
int visited[50], parent[50];
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

void printRoute(int source, int goal)
{
	vector<int>path;
	if(cost[goal]) {
		while(goal != source) {
			path.push_back(goal);
			goal = parent[goal];
		}
		path.push_back(source);
		int len = path.size();
		for(int i = len-1; i > 0; i--)
			cout << cities[path[i]] << " -> ";
		cout << cities[path[0]] << endl;

	}
}


int cityIndex(string city)
{
	for(int i = 0; i < index; i++)
		if(cities[i] == city)
			return i;
	return -1;
}


int main()
{
	int c, E;
	string city1, city2;
	
	cout << "Enter number of edges: ";
	scanf("%d", &E);
	while(E--) {
		cin >> city1 >> city2 >> c;
		//cout << city1 << city2 << c << endl;
		
		//cout << cityIndex(city1) << " - " << cityIndex(city2) << endl;
		
		if(cityIndex(city1) == -1)
			cities[index++] = city1;
		if(cityIndex(city2) == -1)
			cities[index++] = city2;

			
		int x = cityIndex(city1), y = cityIndex(city2);
		edges[x].push_back(y);
		edges[y].push_back(x);
		costVector[x].push_back(c);
		costVector[y].push_back(c);
	}
	//int i, j;
	
	cout << endl << endl << endl;
	
	/*for(i = 0; i < index; i++) {
		int len = edges[i].size();
		cout << cities[i] << ": ";
		for(j = 0; j < len; j++) {
			cout << cities[edges[i][j]] << "(" << costVector[i][j] << ")  ";
		}
		cout << endl;
	}*/
	
	cout << endl << "Enter goal and destination city: ";
	cin >> city1 >> city2;
	
	dijkstra(edges, cityIndex(city1), cityIndex(city2));
	
	for(int i = 0; i < index; i++)
		cout << cities[i] << ": $" << cost[i] << endl;
		
	cout << endl << endl;
	printRoute(cityIndex(city1), cityIndex(city2));
	cout << endl;
	
	return 0;
}
