#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define V 10

vector<int>graph[V];
int color[V];
int m = 3, V2;

bool constraintOk(vector<int>g[], int c, int v, int colr[]);

bool GraphColoring(vector<int>gra[], int clr[], int v)
{
  if(v == V)
    return true;

  for(int i = 1; i <= m; i++) {
    if(constraintOk(gra, i, v, clr)) {
      clr[v] = i;
      if(GraphColoring(gra, clr, v+1))
        return true;
      clr[v] = 0;
    }
  }
  //cout << "Backtrack: " << v << endl;
  return false;
}


bool constraintOk(vector<int>g[], int c, int v, int colr[])
{
    for(int i = 0; i < g[v].size(); i++) {
        if(colr[g[v][i]] == c)
            return false;
    }
    return true;
}


int main()
{
  freopen("input.txt", "r", stdin);
  int node;
  V2 = node;
  cin >> node >> m;
  for(int i = 0; i < node; i++) {
    int source, connectedNode;
    cin >> source >> connectedNode;
    for(int j = 0; j < connectedNode; j++) {
      int n;
      cin >> n;
      graph[i].push_back(n);
    }
  }

  /*for(int i = 0; i < node; i++) {
      cout << i << "   -   ";
      for(int j = 0; j < graph[i].size(); j++)
        cout << graph[i][j] << " ";
      cout << endl;
  }*/

  if(GraphColoring(graph, color, 0)) {
    for(int i = 0; i < node; i++)
        cout << color[i] << " ";
  }
  else
    cout << "No possible solution!" << endl;

  return 0;
}
