#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

struct comparePQ {
	bool operator () (const pii &p1, const pii &p2) {
		return p1.second > p2.second;
	}
};



string cities[50];
int index = 0;


vector<int>edges[50], costVector[50];

int visited[50], cost[50], parent[50];


void dijkstra(vector<int>graph[], int source, int goal)
{
	priority_queue<pii, vector<pii>, comparePQ> cpq;
	vector<pii>pqv[50];
	pii top;
	top.first = source;
	top.second = 0;
	cost[source] = 0;
	cpq.push(top);
	
	while(!cpq.empty()) {
		top = cpq.top();
		if(!visited[top.first]) {
			int len = edges[top.first].size();
			for(int i = 0; i < len; i++) {
				pii temp;
				if(visited[edges[top.first][i]])
					continue;
				temp.first = edges[top.first][i];
				if((cost[temp.first] == 0) || (cost[top.first]+costVector[top.first][i] < cost[temp.first]) ){
					temp.second = costVector[top.first][i] + cost[top.first];
					cost[temp.first] = temp.second;
					parent[temp.first] = top.first;
				}
				cpq.push(temp);
			}
			visited[top.first] = 1;
		}
		cpq.pop();
	}
	if(cost[goal])
		cout << cost[goal] << endl;
	else
		cout << "No solution" << endl;
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
