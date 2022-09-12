#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {
  srand(time(0));

  int n;
  cin >> n;

  int arr1[n];
  int arr2[n];

  FOR(i, 0, n) {
    arr1[i] = rand() % 10;
    arr2[i] = rand() % 10;
  }

  int arr[n * 2];

  FOR(i, 0, n) {
    arr[i * 2] = arr1[i];
    arr[i * 2 + 1] = arr2[i];
  }

  FOR(i, 0, n) {
    cout << arr1[i] << " ";
  }
  cout << endl;

  FOR(i, 0, n) {
    cout << arr2[i] << " ";
  }
  cout << endl;

  cout << endl;
  FOR(i, 0, n * 2) {
    cout << arr[i] << " ";
  }

  return 0;
}
