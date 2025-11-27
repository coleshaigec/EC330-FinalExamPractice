#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <tuple>
#include <algorithm>

using namespace std;

void Union(int u, int v, vector<int>& parent, vector<int>& rank){
  if (rank[u] == rank[v]){
    parent[v] = u;
    rank[u]++;
  }
  else if (rank[u] > rank[v]){
    parent[v] = u;
  }
  else {
    parent[u] = v;
  }
} 

int Find(int u, vector<int>& parent){
  if (parent[u] != u){
    parent[u] = Find(parent[u], parent);
  }
  return parent[u];
}

// Custom helper function used to compare edges in terms of weight
// Designed to assign greater precedence to lower-weight edges, efficiently reverse-sorting the edge list
bool compareWeights(const tuple<int,int,int>& a, const tuple<int,int,int>& b){
  int key1 = get<2>(a);
  int key2 = get<2>(b);
  return key1 < key2;
}

// Runs Kruskal's algorithm to generate a MST from an edge list
// The edge list need not be sorted when the function is called
// The edge list is presumed to have entries of the form (origin, destination, weight)
int Kruskal(int V, vector<tuple<int, int, int> > E){
  // Initialization
  int totalCost = 0;
  vector<int> rank(V,0);
  vector<int> parent(V);
  for (int v = 0; v < V; v++){
    parent[v] = v;
  }

  // Sort edge list using custom comparator
  sort(E.begin(), E.end(), compareWeights);

  // Loop over sorted edge list, building MST from bottom upward
  for (int i = 0; i < E.size(); i++){
    tuple<int, int, int> e = E[i];
    int u = get<0>(e);
    int v = get<1>(e);
    int w = get<2>(e);

    int uRoot = Find(u, parent);
    int vRoot = Find(v, parent);

    if (uRoot == vRoot){
      // u and v part of same tree -- cycle detected
      continue; 
    }

    Union(uRoot, vRoot, parent, rank);
    totalCost += w;
  }

  return totalCost;
}

int main(){
  int V = 5;
  vector<tuple<int, int, int> > E;
  E.push_back({0,1,3});
  E.push_back({0,3,8});
  E.push_back({0,4,7});
  E.push_back({1,3,4});
  E.push_back({1,2,1});
  E.push_back({2,3,2});
  E.push_back({3,4,3});

  cout << "MST cost: " << Kruskal(V, E) << endl;

  return 0;
}
