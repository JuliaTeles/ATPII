#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

/*
  Grupo:
  Gustavo Henrique Baliero Lima
  Júlia Téles Cruz
  Leonardo Milanez da Cunha Prado
*/

// Resolvendo iteradamente
void iterado(int num) {
  bool flag_iter = false;

  /* Vendo se ele é divisível por outros números, como incia-se em 3, logo ao
    testar com 4 exclui os números pares */
  for (int i = 3; i <= sqrt(num); i++) {
    if (num % i == 0 && num != i) {
      printf("Não é primo! - Iterado \n");
      flag_iter = true;
    }
  }

  /* Se flag_iter for false indica que não foi alterada nenhuma das vezes que
   passou pelo for, portanto é primo */
  if (!flag_iter) {
    printf("O número %d é primo - Iterado \n", num);
  }
}

// Resolvendo recursivamente
void recursivo(int num, int aux, bool flag_rec) {

  /* Conferindo se o número é igual a auxiliar, se eles são diferentes e se
    ainda não foi dado como primo pelo método recursivo*/
  if (num % aux == 0 && num != aux && flag_rec) {
    printf("Não é primo! - Recursivo \n");
    flag_rec = false;
  }

  /* Aumentando a auxiliar de dois em dois para evitar comparações
     desnecessárias com números pares */
  aux = aux + 2;

  /* Verificando se a auxiliar é menor que a raíz de n, caso seja chama a função
     novamente */
  if (aux <= sqrt(num)) {
    recursivo(num, aux, flag_rec);
  }
  /* Para ser primo, tem que ter feito todo o loop e a flag continuar true */
  else if (aux > sqrt(num) && flag_rec) {
    printf("O número %d é primo - Recursivo \n", num);
  }
}

int main() {

  int n, d = 3;
  bool flag_rec = true;

  // Colocando o código em português
  setlocale(LC_ALL, "Portuguese");

  printf("--- Programa para conferir se um número é primo ---\n");

  // Pegando o número a ser analisado
  printf("Digite o número que quer conferir: ");
  scanf("%d", &n);

  /* Conferindo se o número não é igual a 2, pois é o primeiro caso e se for
   verdadeiro, não há porque seguir no código */
  if (n == 2) {
    printf("O número %d é primo - igual a 2 \n", n);
    exit(0);
  } else if (n < 2) {
    printf("Valor inválido! Tente um número igual ou maior que 2 \n");
    exit(0);
  }

  // Verificando se é divisivel por 2, caso positivo, não é primo
  if (n % 2 == 0) {
    printf("O número %d não é primo - Divisivel por 2 \n", n);
    exit(0);
  }
  iterado(n);
  recursivo(n, d, flag_rec);
}
