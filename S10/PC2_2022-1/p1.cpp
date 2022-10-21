#include <iostream>

#define PERMISOS 3
#define ARCHIVOS 3
#define USUARIOS 3


#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

int buscarStr(string* arr, int size, string valor) {
  FOR(i, 0, size) {
    if (arr[i] == valor) {
      return i;
    }
  }

  return -1;
}

int buscarChar(char* arr, int size, char valor) {
  FOR(i, 0, size) {
    if (arr[i] == valor) {
      return i;
    }
  }

  return -1;
}

void modificar(string** matriz, char* permisos, string* archivos, string* usuarios, bool esAgregar) {
  char permiso;
  string usuario;
  string archivo;

  cout << "Elija el tipo de permiso: ";
  cin >> permiso;

  cout << "Elija un usuario: ";
  cin >> usuario;

  cout << "Elija un archivo: ";
  cin >> archivo;

  int permisoIndex = buscarChar(permisos, PERMISOS, permiso);
  int usuarioIndex = buscarStr(usuarios, USUARIOS, usuario);
  int archivoIndex = buscarStr(archivos, ARCHIVOS, archivo);

  if (permisoIndex == -1 || usuarioIndex == -1 || archivoIndex == -1) {
    return;
  }

  matriz[usuarioIndex][archivoIndex][permisoIndex] = esAgregar ? permiso : '-';
}

void print(string** matriz) {
  FOR(i, 0, USUARIOS) {
    FOR(j, 0, ARCHIVOS) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  string** matriz = new string*[USUARIOS];

  FOR(i, 0, USUARIOS) {
    matriz[i] = new string[ARCHIVOS];
  }

  matriz[0][0] = "r-d"; matriz[0][1] = "-w-"; matriz[0][2] = "r--";
  matriz[1][0] = "-wd"; matriz[1][1] = "rwd"; matriz[1][2] = "rw-";
  matriz[2][0] = "--d"; matriz[2][1] = "-wd"; matriz[2][2] = "---";

  char* permisos = new char[PERMISOS];
  permisos[0] = 'r';
  permisos[1] = 'w';
  permisos[2] = 'd';

  string* archivos = new string[ARCHIVOS];
  archivos[0] = "misNotas.txt";
  archivos[1] = "tarea1.pdf";
  archivos[2] = "ataque.sh";

  string* usuarios = new string[USUARIOS];
  usuarios[0] = "Jose";
  usuarios[1] = "Pedro";
  usuarios[2] = "Luis";

  print(matriz);

  char tipo;
  while (true) {
    cout << "Desea agregar o remover un permiso? ";
    cin >> tipo;

    if (tipo != 'A' && tipo != 'R') {
      break;
    }

    modificar(matriz, permisos, archivos, usuarios, tipo == 'A');
  }

  print(matriz);

  FOR(i, 0, USUARIOS) {
    delete[] matriz[i];
  }

  delete[] matriz;
  delete[] permisos;
  delete[] archivos;
  delete[] usuarios;

  return 0;
}
