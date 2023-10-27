#include "info.h"
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------- Imprime os coeficientes do polinômio
void coeficientes(polinomio poli) {
  // O primeiro tem x^0 que é = a 1
  printf("   p(x) = %.2f", poli.coef[0]);
  // Imprime os demais coeficientes e seus respectivos x^n
  for (int i = 1; i < poli.n; i++) {
    // Confere se o número é negativo ou positivo
    if (poli.coef[i] > 0) {
      printf(" + %.2fx^%d", poli.coef[i], i);
    } else {
      printf(" + (%.2fx^%d)", poli.coef[i], i);
    }
  }
  printf("\n");
}

polinomio novoPolinomio(int n) {
  // Cria um polinômio
  polinomio poli;

  // Atribui a quantidade de coeficientes
  poli.n = n;
  // Aloca o espaço na memória
  poli.coef = malloc(n * sizeof(float));
  for(int i =0; i<poli.n; i++){
  	poli.coef[i]=0;
  }

  return poli;
}

// Libera a memória
void freePoli(polinomio *p) {
  if (p->coef != NULL) {
    free(p->coef);
    p->coef = NULL;
  }
}

// -------- Pega o polinômio do arquivo
polinomio readFile(char *filename) {
  // Lê o arquivo
  FILE *file = fopen(filename, "r");
  // Criando um polinomio nulo pq a função tem que
  // retornar um polinomio, mesmo que seja nulo
  polinomio poli = novoPolinomio(0);

  // Verifica se conseguiu abrir o arquivo
  if (file == NULL) {
    printf("Erro em abrir o aquivo, tente novamente.\n");
    printf("---------------\n");
    exit(0);
  } else {
    // Liberando o espaço na memória do polinomio nulo
    freePoli(&poli);
    // Variáveis auxiliares
    float aux = 0;
    char tam[100];
    int n = 0;

    // Lê o arquivo e a cada linha adiciona um em n,
    // usaremos n para saber quantos coeficientes tem
    while (fgets(tam, sizeof(tam), file) != NULL) {
      if (strcmp(tam, "\n") != 0) {
        n++;
      }
    }
    polinomio poli = novoPolinomio(n);
    if (n != 0) {
      // Reinicia a leitura do arquivo
      fseek(file, 0, SEEK_SET);

      n = 0;
      // Lê novamentr o arquivo e atribui os números a coef
      while (!feof(file)) {
        fscanf(file, "%f", &aux);
        poli.coef[n] = aux;
        n++;
      }
      printf("---------- \n");
      printf("a) Polinômio: \n");
      coeficientes(poli);
      // Fecha o arquivo
      fclose(file);
      return poli;
    } else {
      printf("O polinômio é nulo\n");
      printf("a) Polinômio: \n");
      coeficientes(poli);
    }
  }
  // Fecha o arquivo
  fclose(file);
  return poli;
}
