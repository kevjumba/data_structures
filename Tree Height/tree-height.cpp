#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class TreeHeight {
  int n;
  vector<int> parent;
  vector<vector<int> > children;

public:
  int root;
  void read() {
    cin >> n;
    parent.resize(n);
    for (int i = 0; i < n; i++)
      cin >> parent[i];
    children.resize(n);
  }

  void fillChildren() {
    for (int i = 0; i < n; i++) {
      if (parent[i] == -1) {
        root = i;
      } else
        children.at(parent[i]).push_back(i);
    }
  }

  int compute_height(int child) {
    // Replace this code with a faster implementation
    if (children[child].size() <= 0)
      return 0;
    int max = 0;
    for (int i = 0; i < children.at(child).size(); i++) {
      max = std::max(max, compute_height(children[child][i]));
    }
    return 1 + max;
  }
};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  tree.fillChildren();
  std::cout << tree.compute_height(tree.root) + 1<< std::endl;
}
