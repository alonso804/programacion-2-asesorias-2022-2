#include <algorithm>
#include <bits/stdc++.h>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

void print(int* arr, int n) {
  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
}

void insertionSort(int* arr, int n) {
  for (int i = 1; i < n; i++) {
    int actual = arr[i];

    int j = i - 1;

    while (j >= 0 && arr[j] > actual) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = actual;
  }
}

int randInt(const int& min, const int& max) {
  return min + rand() % (max - min + 1);
}

char randChar() {
  return 'a' + rand() % 26;
}

int main() {
  int* arr = new int[10];
  
  FOR(i, 0, 10) {
    arr[i] = randInt(0, 9);
  }

  print(arr, 10);
  cout << endl;

  insertionSort(arr, 10);

  print(arr, 10);
  cout << endl;

  delete[] arr;

  return 0;
}
