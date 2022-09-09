#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

void print(int* arr, int n) {
  FOR(i, 0, n) {
    cout << arr[i] << " ";
  }

  cout << endl;
}

void suma(int* arr, int* arr1, int* arr2, int n) {
  FOR(i, 0, n) {
    if (i % 2 == 0) {
      arr[i] = arr1[i] + arr2[i];
    }
    else {
      arr[i] = arr1[i] - arr2[i];
    }
  }
}

int main(int argc, char const* argv[]) {
  srand(time(0));

  int n;
  cin >> n;

  int arr1[n];
  int arr2[n];
  int arr[n];

  FOR(i, 0, n) {
    arr1[i] = rand() % 10;
    arr2[i] = rand() % 10;
  }

  suma(arr, arr1, arr2, n);

  print(arr1, n);
  print(arr2, n);
  cout << endl;
  print(arr, n);

  return 0;
}