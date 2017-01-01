// C++ program for 3-way quick sort
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int a[], int low, int high, int &i, int &j)
{
    // To handle 2 elements
    if (high - low <= 1)
    {
        if (a[high] < a[low])
            swap(&a[high], &a[low]);
        i = low;
        j = high;
        return;
    }

    int mid = low;
    int pivot = a[high];
    while (mid <= high)
    {
        if (a[mid]<pivot)
            swap(&a[low++], &a[mid++]);
        else if (a[mid]==pivot)
            mid++;
        else if (a[mid]>pivot)
            swap(&a[mid], &a[high--]);
    }

    //update i and j
    i = low-1;
    j = mid; //or high-1
}

// 3-way partition based quick sort
void quicksort3(int a[], int low, int high)
{
    if (low>=high) //1 or 0 elements
        return;

    int i, j;

    // Note that i and j are passed as reference
    partition(a, low, high, i, j);

    // Recur two halves
    quicksort3(a, low, i);
    quicksort3(a, j, high);
}

void display3(int a[], int n) {
  for (int i = 0; i < n; ++i)
    cout << a[i]<<" ";
  cout << endl;
}

int main() {
  int N;
  cin >> N;
  int array[N];
  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }
  quicksort3(array, 0, N);
  display3(array, N);
  return 0;
}
