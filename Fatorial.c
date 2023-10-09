#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int mult = 1;
int fatorial(int n) {
  if (n == 0) {
    printf("Fatorial = %d\n", mult);
  } else {
    mult = mult * n;
    n--;
    fatorial(n);
  }
  return mult;
}

int main(void) {

  printf("--- Calculadora de fatorial ---\n");
  printf("Aperte 1 para continuar ou digite 0 para sair.\n");
  int escolha;
  scanf("%d", &escolha);

  switch (escolha) {
  case 0:
    return 0;
  case 1:
    setlocale(LC_ALL, "Portuguese");
    int n;
    printf("Digite o seu número: \n");
    scanf("%d", &n);
    if (n <= -1) {
      printf("Não existe fatorial de nº negativo\n");
    } else if (n < 1) {
      printf("fatorial = %d\n", 1);
    } else {
      fatorial(n);
    }
    main();
  default:
    printf("Opção inválida\n");
    main();
  }
}
