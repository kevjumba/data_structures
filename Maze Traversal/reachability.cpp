#include <iostream>
#include <vector>

using std::vector;
using std::pair;

vector<bool> visited;
int reach(vector<vector<int> > &adj, int x, int y) {
  visited[x]=true;
  for(int i = 0;i<adj[x].size();i++){
    if(!visited[adj[x].at(i)]){
      if(adj[x].at(i)==y) return 1;
      reach(adj, i, y);
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  visited.resize(n);
  for(int i=0;i<n;i++){
    visited[i]=false;
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
