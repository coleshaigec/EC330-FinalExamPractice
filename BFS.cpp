#include <iostream>
#include <climits> // for INT_MAX
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int >>& G, int root){
  if (root > G.size() - 1){
    cout << "Specified root does not exist in graph." << endl;
    return;
  }

  // Initialize BFS
  queue<int> q;
  vector<int> visited(G.size(), 0);
  vector<int> order;
  visited[root] = 1;
  q.push(root);

  while (!q.empty()){
    int currNode = q.front();
    // Enqueue unvisited neighbors of current node, if they exist
      for (int i = 0; i < G[currNode].size(); i++){
	int neighbor = G[currNode][i];
	if (visited[neighbor] == 0){
	  q.push(neighbor);
	  visited[neighbor] = 1;
	}
      }
    order.push_back(currNode);
    q.pop();
  }

  cout << "BFS ORDER FROM ROOT " << root << ": " << order[0];
  for (int j = 1; j < order.size(); j++){
    cout << " --> " << order[j];
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
  
  BFS(G, 1);
  BFS(G ,2);
  BFS(G, 3);
  BFS(G, 4);
  BFS(G, 5);
  BFS(G, 6);
  
  
  return 0;
}
