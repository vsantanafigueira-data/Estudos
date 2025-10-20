//funcionamento de ponteiros em C
#include <stdio.h>

int main(){


    int var = 10;
    int *ptr = &var;

    printf("valor de var: %d\n", var);
    printf("endereco de var: %p\n", &var);
    printf("endereco de ptr: %p\n", ptr);
    printf("valor apontado por ptr: %d\n", *ptr);

    //printf do endereço na memória de var: %p -> &var
    //print do endereço apontado por ptr: %p -> ptr
    //print do valor apontado por ptr: %d -> *ptr


    return 0;
}