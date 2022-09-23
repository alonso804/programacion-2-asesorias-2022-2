#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int filas = 4;
  int columnas = 4;

  int matriz[filas][columnas] = {
    { 3, 5, 6, 9 },
    { 4, 1, 5, 6 },
    { 1, 2, 4, 6 },
    { 8, 5, 7, 2 },
  };

  int* ptr = matriz[0];
  ptr += 1;
  ptr++;
  ptr + 2;
  ptr--;
  cout << *(ptr + 1) << endl;

  return 0;
}