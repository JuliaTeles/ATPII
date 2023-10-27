#include "info.h"
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  char arquivo1[50];
  char arquivo2[50];
  setlocale(LC_ALL, "Portuguese");

  // Primeiro polinômio
  printf("--- Cálculos com Polinômios ---\n");
  printf("Informe o nome do primeiro arquivo: \n");
  scanf("%s", arquivo1);
  polinomio um = readFile(arquivo1);

  
  printf("b) Digite um x para resolver o polinômio: ");
  float x;
  scanf("%f", &x);
  printf("   p(%.2f) = %.2f \n", x, resolver(um, x));
  printf("c) Derivada: \n");
  coeficientes(derivada(um));
  printf("d) Integral, digite a constante de integração: ");
  float k;
  scanf("%f", &k);
  coeficientes(integral(um, k));
  float a, b;
  printf("e) Integral Definida, digite o limite superior: ");
  scanf("%f", &a);
  printf("   Digite o limite inferior: ");
  scanf("%f", &b);
  printf("   Integral Definida = %.2f \n", integralDef(um, a, b));
  
  printf("----------\n");

  // Segundo polinômio
  printf("Informe o nome do segundo arquivo: \n");
  scanf("%s", arquivo2);
  polinomio dois = readFile(arquivo2);

  printf("b) Digite um x para resolver o polinômio: ");
  scanf("%f", &x);
  printf("   p(%.2f) = %.2f \n", x, resolver(dois, x));
  printf("c) Derivada: \n");
  coeficientes(derivada(dois));
  printf("d) Integral, digite a constante de integração: ");
  scanf("%f", &k);
  coeficientes(integral(dois, k));
  printf("e) Integral Definida, digite o limite superior: ");
  scanf("%f", &a);
  printf("   Digite o limite inferior: ");
  scanf("%f", &b);
  printf("   Integral Definida = %.2f \n", integralDef(dois, a, b));

  printf("----------\n");
  /*
  // Operações com polinômios
  printf("1) Soma dos polinômios: \n");
  coeficientes(soma(um, dois));
  printf("2) Subtração dos polinômios: \n");
  coeficientes(subtracao(um, dois));
  printf("3) Multiplicação dos polinômios: \n");
  coeficientes(multiplicacao(um, dois));
  printf("----------\n"); */
  

  // Newton-Raphson
  printf("-> Método de Newton-Raphson \n");
  printf("a) Digite o valor inicial de x: \n");
  float newtX;
  scanf("%f", &newtX);
  printf("b) Digite o valor da precisão númerica de epsilon: \n");
  float epsilon;
  scanf("%f", &epsilon);
  printf("c) Número máximo de iterações: \n");
  int iterar;
  scanf("%d", &iterar);
  float resultado;
  resultado = newtonRaphson(um, newtX, epsilon, iterar);
  printf("Uma raíz do 1° polinômio é aprox.: %f\n", resultado);
  resultado = newtonRaphson(dois, newtX, epsilon, iterar);
  printf("Uma raíz do 2° polinômio é aprox.: %f\n", resultado);
  printf("----------\n");

  return 0;
}
