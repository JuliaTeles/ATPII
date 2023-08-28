#include <stdlib.h>
#include <stdio.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int x = 5;
    int y = 2;
    
    printf("x = %d, y = %d \n",x,y);
    troca(&x,&y);
    printf("x = %d, y = %d \n",x,y);

    return 0;
}
