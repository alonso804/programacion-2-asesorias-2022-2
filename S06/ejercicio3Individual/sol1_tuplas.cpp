#include <iostream>
#include <cmath>
#include <tuple>
#include <utility>

#define deb(x) cout << #x << ": " << x << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

using namespace std;

using Planeta = tuple<string, double, double>; // nombre - masa - diametro

double getVolume(const double& diameter) {
  return (4.0/3.0) * M_PI * pow(diameter/2.0, 3);
}

// Inclusivo
int randInt(const int& min, const int& max) {
  return min + rand() % (max - min + 1);
}

bool winner(const Planeta& p1, const Planeta& p2) {
  return get<1>(p1) > get<1>(p2);
}

void colision(Planeta* planetas, int& n, int& count) {
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

  bool p1Winner = winner(planetas[idxPlaneta1], planetas[idxPlaneta2]);

  if (p1Winner) {
    get<1>(planetas[idxPlaneta1]) += get<1>(planetas[idxPlaneta2]) / 2;
    get<2>(planetas[idxPlaneta1]) *= 2;

    get<1>(planetas[idxPlaneta2]) = 0;

    swap(planetas[idxPlaneta2], planetas[n - 1]);
  } else {
    get<1>(planetas[idxPlaneta2]) += get<1>(planetas[idxPlaneta1]) / 2;
    get<2>(planetas[idxPlaneta2]) *= 2;

    get<1>(planetas[idxPlaneta1]) = 0;

    swap(planetas[idxPlaneta1], planetas[n - 1]);
  }

  n--;
}

int main() {
  srand(time(NULL));
  const int TOTAL = 4;

  Planeta* planetas = new Planeta[TOTAL];
  planetas[0] = { "Mercurio", 0.05, 0.4 };
  planetas[1] = { "Venus", 0.8, 0.9 };
  planetas[2] = { "Tierra", 1, 1 };
  planetas[3] = { "Marte", 0.1, 0.5 };

  int planetasRestantes = TOTAL;

  int count = 0;

  FOR(i, 0, TOTAL - 1) {
    colision(planetas, planetasRestantes, count);
  }

  cout << "Sobrevive: " << get<0>(planetas[0]);
  cout << " con masa de " << get<1>(planetas[0]);
  cout << " y volumen de " << getVolume(get<2>(planetas[0]));
  cout << ", luego de " << count * 10 << " colisiones." << endl;

  delete[] planetas;

  return 0;
}

