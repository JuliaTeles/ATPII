#include "contas.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  setlocale(LC_ALL, "Portuguese");
  printf("--- Cálculo de Probabilidade ---\n");
  printf("1 - Bernoulli\n");
  printf("2 - Binomial\n");
  printf("3 - Poisson\n");
  printf("4 - Geométrica\n");
  printf("5 - Pascal\n");
  printf("6 - Hipergeométrica\n");
  printf("0 - Sair\n");
  int escolha;
  scanf("%d", &escolha);

  switch (escolha) {
  case 0:
    break;
  case 1:
    bernoulli();
    main();
  case 2:
    binomial();
    main();
  case 3:
    poisson();
    main();
  case 4:
    geometrica();
    main();
  case 5:
    pascal();
    main();
  case 6:
    hipergeometrica();
    main();
  default:
    printf("Opção inválida\n");
    main();
  }
  return 0;
}