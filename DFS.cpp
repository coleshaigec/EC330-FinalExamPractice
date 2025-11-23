#include <iostream>
#include <climits> // for INT_MAX
#include <vector>
#include <stack>
#include <tuple>

using namespace std;

void DFS(const vector<vector<int >>& G, int root){
  if (root < 0 || root  > G.size() - 1){
    cout << "Specified root not found in graph" << endl;
    return;
  }

  // Initialization
  stack<int> s;
  s.push(root);
  vector<int> visited(G.size(), 0);
  visited[root] = 1;
  vector<int> order;
  vector<int> parent(G.size(), -1);

  // Perform DFS from root
  while (!s.empty()){
    int currNode = s.top();
    s.pop();
    for (int i = 0; i < G[currNode].size(); i++){
      int neighbor = G[currNode][i];
      if (visited[neighbor] == 0){
	parent[neighbor] = currNode;
	visited[neighbor] = 1;
	s.push(neighbor);
      }
    }
    order.push_back(currNode);
  }
  
  cout << "DFS order: " << root;
  for (int i = 1; i < order.size(); i++){
    cout << " --> " << order[i];
  }

  cout << endl;
  
}

int main() {
  // Initialize graph as adjacency list
  int V = 7;
  vector<vector<int> > G(V);
  G[0].push_back(1);
  G[1].push_back(0);
  G[1].push_back(2);
  G[1].push_back(3);
  G[2].push_back(1);
  G[2].push_back(3);
  G[2].push_back(4);
  G[3].push_back(1);
  G[3].push_back(2);
  G[4].push_back(2);
  G[4].push_back(6);
  G[5].push_back(6);
  G[6].push_back(5);
  G[6].push_back(4);
  
  DFS(G, 1);
  DFS(G ,2);
  DFS(G, 3);
  DFS(G, 4);
  DFS(G, 5);
  DFS(G, 6);
  
  
  return 0;
}
