#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

double final(double ec, double p, double ep, double ef, double r) {
  return 0.15 * ec + 0.2 * p + 0.3 * ep + 0.3 * ef + 0.05 * r;
}

int main(int argc, char const* argv[]) {
  double ec, p, ep, ef, r;

  cin >> ec >> p >> ep >> ef >> r;

  double f;

  double DESAPROBADO = 10.5;

  if (ec < DESAPROBADO || p < DESAPROBADO || ep < DESAPROBADO || ef < DESAPROBADO) {
    f = 10;
    printf("La nota final es: %.0f\n", f);
    return 0;
  }

  DESAPROBADO = 14;

  if (ec < DESAPROBADO || p < DESAPROBADO || ep < DESAPROBADO || ef < DESAPROBADO) {
    f = final(ec, p, ep, ef, 0);

    printf("La nota final es: %.0f\n", f);
    return 0;
  }

  f = final(ec, p, ep, ef, r);
  printf("La nota final es: %.0f\n", f);

  return 0;
}