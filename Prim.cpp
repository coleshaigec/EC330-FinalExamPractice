#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#include <functional>
#include <numeric>

using namespace std;

// Run Prim's algorithm from specified root
// Returns MST
vector<vector<pair<int,int> > > Prim(const vector<vector<pair<int, int> > >& G, int root){
  // Initialization
  priority_queue<
    pair<int, int>,
    vector<pair<int, int> >,
    greater<pair<int, int> >
    > pq; // Empty priority queue as minheap
  vector<bool> visited (G.size(), false);
  vector<int> parent(G.size(), -1);
  vector<int> key(G.size(), INT_MAX);
  vector<vector<pair<int,int> > > tree(G.size(), vector<pair<int, int> >()); // use this to store the MST
  key[root] = 0;
  pq.push({0, root});

  // Main loop
  while (!pq.empty()){
    // Pop first element from priority queue
    pair<int, int> e = pq.top();
    int u = e.second;
    pq.pop();

    // Don't relax on nodes that have already been visited
    if (visited[u]){
      continue;
    }

    // Loop over neighbors of u in adjacency list
    // If node is unvisited, relax
    for (int i = 0; i < G[u].size(); i++){
      int v = G[u][i].first;
      int w = G[u][i].second;
      if (w < key[v] && !visited[v]){
	key[v] = w;
	parent[v] = u;
	pq.push({key[v],v});
      }
    }
    // Mark u visited after relaxing
    visited[u] = true;
  }

  for (int v = 0; v < G.size(); v++){
    int u = parent[v];
    if (u != -1){
      tree[u].push_back({v, key[v]});
      tree[v].push_back({u, key[v]});
    }
  }
  cout << "Total MST cost: " << accumulate(key.begin(), key.end(), 0) << endl;
  return tree;
}

int main(){
  int V = 9;
  vector<vector<pair<int, int> > > G(V);
  G[0].push_back({1,4});
  G[0].push_back({2,8});
  G[1].push_back({0,4});
  G[1].push_back({2,11});
  G[1].push_back({3,9});
  G[1].push_back({4,8});
  G[2].push_back({0,8});
  G[2].push_back({1,11});
  G[2].push_back({3,7});
  G[3].push_back({1,9});
  G[3].push_back({2,7});
  G[3].push_back({4,2});
  G[3].push_back({5,6});
  G[4].push_back({1,8});
  G[4].push_back({3,2});
  G[4].push_back({5,5});
  G[4].push_back({6,7});
  G[4].push_back({7,4});
  G[5].push_back({2,1});
  G[5].push_back({3,6});
  G[5].push_back({4,5});
  G[5].push_back({7,2});
  G[6].push_back({4,7});
  G[6].push_back({7,14});
  G[6].push_back({8,9});
  G[7].push_back({4,4});
  G[7].push_back({5,2});
  G[7].push_back({6,14});
  G[7].push_back({8,10});
  G[8].push_back({7,10});
  G[8].push_back({6,9});

  for (int i = 0; i < V; i++){
    Prim(G, i);
  }
  
  return 0;
}
