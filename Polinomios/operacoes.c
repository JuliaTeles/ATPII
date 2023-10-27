#include "info.h"
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Resolve o polinômio para um determinado x
float resolver(polinomio poli, float x) {
  float soma;
  for (int i = 0; i < poli.n; i++) {
    soma = soma + (poli.coef[i] * pow(x, i));
  }
  return soma;
}

// --- Deriva o polinômio
polinomio derivada(polinomio poli) {
  // Cria o polinômio de resposta com um grau a menos
  polinomio derivado = novoPolinomio(poli.n - 1);

  // Calcula a derivada
  for (int i = 1; i < poli.n; i++) {
    derivado.coef[i - 1] = i * poli.coef[i];
  }
  return derivado;
}

// --- Integra o polinômio
polinomio integral(polinomio poli, float k) {
  // Cria o polinômio de resposta com um grau
  // a mais  (por conta da constante)
  polinomio integrado = novoPolinomio(poli.n + 1);

  // Calcula a integral de cada coeficiente
  for (int i = 0; i < poli.n; i++) {
    integrado.coef[i + 1] = (poli.coef[i]) / (i + 1);
  }
  // Adiciona a constante ao polinômio
  integrado.coef[0] = k;
  return integrado;
}

// --- Integra definidamente o polinômio
float integralDef(polinomio poli, float a, float b) {
  float integrado, sup = 0, inf = 0;
  // Calcula a integral para o limite superior e inferior
  for (int i = 0; i < poli.n; i++) {
    sup = sup + ((poli.coef[i]) * (pow(a, i + 1)) / (i + 1));
    inf = inf + ((poli.coef[i]) * (pow(b, i + 1)) / (i + 1));
  }
  // Calcula a integral definida, subtraindo do resultado da
  // integral com o limite superior o resultado da integral com
  // o limite inferior
  integrado = sup - inf;
  return integrado;
}

/* Usei duas funções para calcular qual é o menor e qual é o maior
   polinômio para decidir o tamanho dos polinômios a serem criados e
   a "duração" dos for nas operações de soma, subtração e multiplicação. */

// Retorna o tamanho do maior polinômio
polinomio maiorPoli(polinomio um, polinomio dois) {
  if (um.n > dois.n)
    return um;
  else
    return dois;
}

// Retorna o tamanho do menor polinômio
polinomio menorPoli(polinomio um, polinomio dois) {
  if (um.n < dois.n)
    return um;
  else
    return dois;
}

// --- Soma dois polinômios
polinomio soma(polinomio um, polinomio dois) {
  // Cria-se dois polinomios referentes ao maior e ao menor entre "um" e
  // "dois"
  polinomio maior = maiorPoli(um, dois);
  polinomio menor = menorPoli(um, dois);
  // Cria-se um polinômio de resposta com o tamanho do maior
  polinomio somatorio = novoPolinomio(maior.n);
  for (int i = 0; i < maior.n; i++) {
    // Soma os números que tenham o mesmo grau
    somatorio.coef[i] = maior.coef[i] + menor.coef[i];
  }
  return somatorio;
}

// --- Subtrai dois polinômios
polinomio subtracao(polinomio um, polinomio dois) {
  /* A mesma ideia da soma, porém com - ao invés de +, quis seguir o padrão
    do print do professor então fiz o primeiro polinômio digitado menos o
    segundo, porém daria para otimizar mais essas três operações básicas
    se pudesse fazer o maior - menor */
  polinomio maiorsub = maiorPoli(um, dois);
  polinomio subtraido = novoPolinomio(maiorsub.n);
  for (int i = 0; i < maiorsub.n; i++) {
    subtraido.coef[i] = um.coef[i] - dois.coef[i];
  }
  return subtraido;
}

// --- Newton-Raphson
float newtonRaphson(polinomio poli, float x, float epsilon, int iterar) {
  float antigo = 0, denominador = 0, numerador = 0;
  for (int i = 0; i < iterar; i++) {
    if (fabs(x - antigo) >= epsilon) {
      denominador = (resolver(derivada(poli), x));
      if (denominador != 0) {
        antigo = x;
        numerador = resolver(poli, x);
        x = x-(numerador/denominador);
      } else {
        printf("Não há raiz, divisão por 0. \n");
        return 0;
      }
    } else {
      return x;
    }
  }

  return x;
}

// --- Multiplica dois polinômios
polinomio multiplicacao(polinomio um, polinomio dois) {
  polinomio maiormult = maiorPoli(um, dois);
  polinomio menormult = menorPoli(um, dois);
  /* O maior coeficiente gerado em uma multiplicação de polinômios será
     o da multiplicação entre os últimos coeficientes de cada polinômio,
     que resultará na soma entre esses dois coeficientes */
  polinomio multiplicado = novoPolinomio(maiormult.n + menormult.n - 1);
  for (int j = 0; j < maiormult.n + menormult.n - 1; j++) {
    multiplicado.coef[j] = 0;
  }

  for (int i = 0; i < menormult.n; i++) {
    for (int j = 0; j < maiormult.n; j++) {
      // Fiz [i + j] pois há mais de uma operação que resultará
      // no mesmo coeficiente
      multiplicado.coef[i + j] = multiplicado.coef[i + j] + (maiormult.coef[j] * menormult.coef[i]);
    }
  }
  return multiplicado;
}


