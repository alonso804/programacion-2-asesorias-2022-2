#include <iostream>
#include <cmath>
#include <utility>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

double getVolume(const double& diameter) {
  return (4.0/3.0) * M_PI * pow(diameter/2.0, 3);
}

// Inclusivo
int randInt(const int& min, const int& max) {
  return min + rand() % (max - min + 1);
}

bool winner(const double& masa1, const double& masa2) {
  return masa1 > masa2;
}

void colision(string* nombres, double* masas, double* diametros, int& n, int& count) {
  double randDouble;
  do {
    randDouble = randInt(0, 300) / 10.0;
    count++;
  } while (randDouble >= 0.5);

  int idxPlaneta1 = randInt(0, n - 1);
  int idxPlaneta2;

  do {
    idxPlaneta2 = randInt(0, n - 1);
  } while (idxPlaneta1 == idxPlaneta2);

  bool p1Winner = winner(masas[idxPlaneta1], masas[idxPlaneta2]);

  if (p1Winner) {
    masas[idxPlaneta1] += masas[idxPlaneta2] / 2;
    diametros[idxPlaneta1] *= 2;

    masas[idxPlaneta2] = 0;

    swap(nombres[idxPlaneta2], nombres[n - 1]);
    swap(masas[idxPlaneta2], masas[n - 1]);
    swap(diametros[idxPlaneta2], diametros[n - 1]);
  } else {
    masas[idxPlaneta2] += masas[idxPlaneta1] / 2;
    diametros[idxPlaneta2] *= 2;

    masas[idxPlaneta1] = 0;

    swap(nombres[idxPlaneta1], nombres[n - 1]);
    swap(masas[idxPlaneta1], masas[n - 1]);
    swap(diametros[idxPlaneta1], diametros[n - 1]);
  }

  n--;
}

int main() {
  srand(time(NULL));
  const int TOTAL = 4;

  string* nombres = new string[TOTAL];
  double* masas = new double[TOTAL];
  double* diametros = new double[TOTAL];

  nombres[0] = "Mercurio";
  nombres[1] = "Venus";
  nombres[2] = "Tierra";
  nombres[3] = "Marte";

  masas[0] = 0.05;
  masas[1] = 0.8;
  masas[2] = 1;
  masas[3] = 0.1;

  diametros[0] = 0.4;
  diametros[1] = 0.9;
  diametros[2] = 1;
  diametros[3] = 0.5;

  int planetasRestantes = TOTAL;

  int count = 0;

  FOR(i, 0, TOTAL - 1) {
    colision(nombres, masas, diametros, planetasRestantes, count);
  }

  cout << "Sobrevive: " << nombres[0];
  cout << " con masa de " << masas[0];
  cout << " y volumen de " << getVolume(diametros[0]);
  cout << ", luego de " << count * 10 << " colisiones." << endl;

  delete[] nombres;
  delete[] masas;
  delete[] diametros;

  return 0;
}

