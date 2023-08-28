#include <stdlib.h>
#include <stdio.h>

int main(){
    char b = 'x';
    char *a = &b;
    char **p = NULL;
    
    *a = 't';
    printf("%c \n",b);
    
    p = &a;
    **p = 'g'; 
    printf("%c \n",b);

    return 0;
}
