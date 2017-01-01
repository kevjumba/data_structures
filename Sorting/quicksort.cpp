#include <iostream>
#include <vector>
using namespace std;

vector<int> partition3(int a[], int left, int right) {
  int m1 = left - 1, m2 = right;
  int p = left - 1, q = right;
  int v = a[right];

  while (true) {
    while (a[++m1] < v)
      ;

    while (v < a[--m2])
      if (m2 == left)
        break;

    if (m1 >= m2)
      break;
    swap(a[m1], a[m2]);

    if (a[m1] == v) {
      p++;
      swap(a[p], a[m1]);
    }

    if (a[m2] == v) {
      q--;
      swap(a[m2], a[q]);
    }
  }

  swap(a[m1], a[right]);

  m2 -= 1;
  for (int k = left; k < p; k++, m2--)
    swap(a[k], a[m2]);

  m1 += 1;
  for (int k = right - 1; k > q; k--, m1++)
    swap(a[m1], a[k]);

  vector<int> result;
  result.push_back(m1);
  result.push_back(m2);
  return result;
}

void quicksort2(int a[], int left, int right) {
  if (right <= left)
    return;

  vector<int> result;
  result = partition3(a, left, right);

  quicksort2(a, left, result[1]);
  quicksort2(a, result[0], right);
}

void display2(int a[], int n) {
  for (int i = 0; i < n; ++i)
    cout << a[i]<<" ";
  cout << endl;
}

int main3() {
  int N;
  cin >> N;
  int array[N];
  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }
  quicksort2(array, 0, N);
  display2(array, N);
  return 0;
}
