#include <stdlib.h>
#include <stdio.h>

int main(){
    char b = 'x';

    char *a = &b;

    printf("%c \n",b);
    printf("%c \n",*a);
    // %p imprime o endeço na tela
    printf("%p \n",&b);
    printf("%p \n",a);

    return 0;
}
