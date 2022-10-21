#include <iostream>
#include <climits>
#include <random>

#define MIN 1
#define MAX 12

#define JUGADORES 3

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

class Dodecaedro {
  int total;

public:
  Dodecaedro() {
    total = 0;
  }

  int tirarDado() {
    return MIN + rand() % (MAX - MIN + 1);
  }

  void jugar(int& prediccion, const int& jugadas) {
    FOR(i, 0, jugadas) {
      int cara = tirarDado();
      int puntos = abs(cara - prediccion);
      total += puntos;

      cout << "Intento " << i + 1 << ": " << cara << ", " << prediccion << ", " << puntos << endl;

      prediccion++;
    }
    cout << "Puntaje: " << total << endl;
  }

  int getTotal() {
    return total;
  }

  ~Dodecaedro() = default;
};

int main() {
  srand(time(NULL));

  int idxGanador;
  int puntajeMenor = INT_MAX;

  FOR(i, 0, JUGADORES) {
    Dodecaedro juego;

    int jugadas;
    cout << "Jugador " << i + 1 << " ¿Cuantas veces tirara el dado?" << endl;
    cin >> jugadas;

    int prediccion;
    cout << "Cual es su prediccion?" << endl;
    cin >> prediccion;

    juego.jugar(prediccion, jugadas);

    if (juego.getTotal() < puntajeMenor) {
      puntajeMenor = juego.getTotal();
      idxGanador = i;
    }
  }

  cout << "El jugador es: " << idxGanador + 1 << endl;

  return 0;
}
