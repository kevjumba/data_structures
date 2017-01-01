#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
typedef unsigned long long ull;


unsigned long long hashS(string S) {
  unsigned long long num = 0;
  for (int i = (S.length() - 1); i >= 0; i = i - 1) {
    num = (num * 263 % 1000000007) + S[i] % 1000000007;
  }
  return num % 5;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cout<<hashS("world")<<endl;
  cout<<hashS("HellO");
  int x;
  cin>>x;
}
