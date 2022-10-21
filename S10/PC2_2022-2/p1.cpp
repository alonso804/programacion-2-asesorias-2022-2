#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <pthread.h>

#include "prettyprint.hpp"

#define N 10
// const int N = 10;

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int** reservar(int n) {
  int** arr = new int*[N];

  FOR(i, 0, N) {
    arr[i] = new int[N];
  };

  return arr;
}

void liberar(int** matriz, int n) {
  FOR(i, 0, n) {
    delete[] matriz[i];
  }

  delete[] matriz;
}

void print(int** matriz, int n) {
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
}

void print(int* arr, int n) {
  FOR(i, 0, n) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

vector<pair<int, int>> ordenar(int* arr, int n) {
  vector<pair<int, int>> pares;

  FOR(i, 0, n) {
    pares.push_back({arr[i], i});
  }

  sort(pares.begin(), pares.end(), [](pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
  });

  return pares;
}

int main() {
  int arr1[] = {2, 5, 1, 3, 6, 8, 7, 9, 4, 1};

  int** matriz = reservar(N);

  FOR(i, 0, N) {
    FOR(j, 0, N) {
      /* if (arr1[i] >= arr1[j]) {
        matriz[i][j] = 1;
      } else {
        matriz[i][j] = 0;
      } */

      matriz[i][j] = arr1[i] >= arr1[j] ? 1 : 0;
      // condicion ? verdadero : falso;
    }
  }

  int sumas[N];
  FOR(i, 0, N) {
    int suma = 0;

    FOR(j, 0, N) {
      suma += matriz[i][j];
    }

    sumas[i] = suma;
  }

  int maximus = INT_MIN;
  int maximoIdx = -1;

  FOR(i, 0, N) {
    if (sumas[i] > maximus) {
      maximus = sumas[i];
      maximoIdx = i;
    }
  }

  auto pares = ordenar(sumas, N);

  print(arr1, N);
  cout << "========" << endl;
  print(matriz, N);
  cout << "========" << endl;
  print(sumas, N);
  cout << "========" << endl;
  cout << "[" << maximoIdx << "]: " << arr1[maximoIdx] << endl;
  cout << "========" << endl;
  FOR(i, 0, pares.size()) {
    int idx = pares[i].second;
    cout << arr1[idx] << " ";
  }
  cout << endl;

    cout << pares << endl;

  liberar(matriz, N);

  return 0;
}
