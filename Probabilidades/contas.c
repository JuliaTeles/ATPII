#include "contas.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float fatorial(int n) {
  float resposta;
  for (int aux = 0; aux < n; aux++) {
    resposta = aux * n;
  }
  return resposta;
}

float combinacao(int cima, int baixo) {
  float resposta;
  resposta = fatorial(cima) / (fatorial(baixo) - fatorial(cima - baixo));
  return resposta;
}

void bernoulli() {
  float p;
  printf("Informe a probabilidade: \n");
  scanf("%f", &p);

  int x;
  printf("Qual o seu X? \n");
  scanf("%d", &x);

  float resposta;
  resposta = pow(p, x) * pow(1 - p, (1 - x));
  printf("P(X = %d) = %.4f \n", x, resposta);
  printf("E(X) = %.4f \n", p);
  printf("V(X) = %.4f \n\n", p * (1 - p));
}

void binomial() {
  float p;
  printf("Informe a probabilidade: \n");
  scanf("%f", &p);

  int n;
  printf("Até qual número deve-se calcular? \n");
  scanf("%d", &n);

  float somatorio;
  for (int aux = 0; aux < n; aux++) {
    somatorio =
        somatorio + combinacao(n, aux) * (pow(p, aux) * pow(1 - p, (n - aux)));
  }

  printf("Probabilidade = %.4f \n", somatorio);
  printf("E(X) = %.4f \n", n * p);
  printf("V(X) = %.4f \n\n", n * p * (1 - p));
}

void poisson() {
  float lambida;
  printf("Informe seu lambida: \n");
  scanf("%f", &lambida);

  int x;
  printf("Qual o seu X? \n");
  scanf("%d", &x);

  float resposta;
  resposta = pow(lambida, x) * exp(-lambida) / fatorial(x);

  printf("Probabilidade = %.4f \n", resposta);
  printf("E(X) = %.4f \n", lambida);
  printf("V(X) = %.4f \n\n", lambida);
}

void geometrica() {
  float p;
  printf("Informe a probabilidade: \n");
  scanf("%f", &p);

  int x;
  printf("Qual o seu X? \n");
  scanf("%d", &x);

  float resposta;
  resposta = pow(1 - p, x - 1) * p;

  printf("Probabilidade = %.4f \n", resposta);
  printf("E(X) = %.4f \n", 1 / p);
  printf("V(X) = %.4f \n\n", (1 - p) / pow(p, 2));
}

void pascal() {
  float p;
  printf("Informe a probabilidade: \n");
  scanf("%f", &p);

  int r;
  printf("Qual o número de sucessos? \n");
  scanf("%d", &r);

  int x;
  printf("Qual o seu X? \n");
  scanf("%d", &x);

  int n;
  printf("Qual o número total? \n");
  scanf("%d", &n);

  float resposta;
  resposta = combinacao(x - 1, r - 1) * pow(p, r) * pow(1 - p, x - r);
}