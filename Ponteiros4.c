#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct{

    int rg;
    char *nome;

}pessoa;


int main(){
    setlocale(LC_ALL, "Portuguese");

    pessoa prof;
    prof.rg = 123456;
    prof.nome = "Emílio";
    
    printf("Nome do professor: %s \n",prof.nome);
    printf("Esse não é o rg do prof: %d \n",prof.rg);

    return 0;
}
