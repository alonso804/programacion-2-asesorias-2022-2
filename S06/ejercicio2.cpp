#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int filas = 3;
  int columnas = 3;

  string** permisos = new string*[filas];

  for (int i = 0; i < filas; i++) {
    permisos[i] = new string[columnas];
  }

  permisos[0][0] = "r-d";
  permisos[0][1] = "-w-";
  permisos[0][2] = "r--";
  permisos[1][0] = "-wd";
  permisos[1][1] = "rwd";
  permisos[1][2] = "rw-";
  permisos[2][0] = "--d";
  permisos[2][1] = "-wd";
  permisos[2][2] = "r--";

  string* nombres = new string[filas];
  nombres[0] = "Jose";
  nombres[1] = "Pedro";
  nombres[2] = "Luis";

  string* archivos = new string[columnas];
  archivos[0] = "misNotax.txt";
  archivos[1] = "tarea1.pdf";
  archivos[2] = "ataque.sh";

  return 0;
}