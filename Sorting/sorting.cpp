#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition(vector<int> &a, int left, int right) {
  int x = a[left];
  int i = left - 1;
  int j = right + 1;
  while (true) {
    do {
      j = j - 1;
    } while (a[j] <= x);
    do {
      i++;
    } while (a[i] >= x);
    if (i < j) {
      int temp = a[left];
      a[left] = a[j];
      a[j] = temp;
    } else {
      return j;
    }
  }
}
vector<int> partition3(vector<int> &a, int left, int right) {
  int j = left, k = left;
  int x = a[left];
  for (int i = left + 1; i <= right; i++) {
    if (a[i] <= x) {
      j += 1;
      k++;
      int temp = a[j];
      a[j] = a[i];
      a[i] = temp;
    } else if (a[i] == x) {
      k++;
      int temp = a[k];
      a[k] = a[i];
      a[i] = temp;
    }

  }
  int temp = a[left];
  a[left] = a[j];
  a[j] = temp;
  vector<int> m;
  m.push_back(j);
  m.push_back(k);
  return m;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main2() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
