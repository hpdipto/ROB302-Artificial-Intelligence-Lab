#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define V 10

int V2;
vector<int>graph[V];
int color[V];
int m = 3, solution;

bool constraintOk(vector<int>g[], int c, int v, int colr[]);

bool allColored(int colr[]);

void GraphColoring(vector<int>gra[], int clr[], int v)
{
  if(v == V2) {
    for(int p = 0; p < V2; p++)
        cout << clr[p] << " ";
    cout << endl;
    solution++;
    return;
  }

  for(int i = 1; i <= m; i++) {
    if(constraintOk(gra, i, v, clr)) {
      clr[v] = i;
      GraphColoring(gra, clr, v+1);
      clr[v] = 0;
    }
  }
}


bool constraintOk(vector<int>g[], int c, int v, int colr[])
{
    for(int i = 0; i < g[v].size(); i++) {
        if(colr[g[v][i]] == c)
            return false;
    }
    return true;
}

bool allColored(int colr[])
{
    for(int i = 0; i < V2; i++)
        if(colr[i] < 1 || colr[i] > m)
            return false;
    return true;
}

int main()
{
  freopen("input.txt", "r", stdin);
  int node;
  cin >> node >> m;
  V2 = node;
  for(int i = 0; i < node; i++) {
    int source, connectedNode;
    cin >> source >> connectedNode;
    for(int j = 0; j < connectedNode; j++) {
      int n;
      cin >> n;
      graph[source].push_back(n);
    }
  }

    GraphColoring(graph, color, 0);

    if(!solution)
        cout << "No solution!" << endl;

  return 0;
}

