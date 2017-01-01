#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using std::floor;
using std::system;
using std::max;

class HeapBuilder {
private:
  vector<int> data_;
  vector<pair<int, int> > swaps_;

  int LeftChild(int i) {
    return 2 * i + 1;
  }

  int RightChild(int i) {
    return 2 * i + 2;
  }

  int parent(int i) {
    return floor((i - 1) / 2);
  }

  void SiftDown(int i) {
    int maxIndex = i;
    int l = LeftChild(i);
    if (l < data_.size() && data_.at(l) < data_.at(maxIndex)) {
      maxIndex = l;
    }
    int r = RightChild(i);
    if (r < data_.size() && data_.at(r) < data_.at(maxIndex)) {
      maxIndex = r;
    }
    if (i != maxIndex) {
      swap(data_[i], data_[maxIndex]);
      swaps_.push_back(make_pair(i, maxIndex));
      SiftDown(maxIndex);
    }
  }

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void GenerateSwaps() {
    int size = data_.size();
    for (int i = floor((size - 1) / 2); i >=0; i--) {
      SiftDown(i);
    }
  }

public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
