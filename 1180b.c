//utilizando ponteiros
#include <stdio.h>
#include <stdlib.h>

int main(){

    int N;
    int i,j;

    scanf("%d", &N);

//malloc : declaro um ponteiro, depois faço um typecast(pois eu quero tipo int), depois faço malloc, com N *size(int), ou seja
//quero um tamanho = N;
int *p = (int*) malloc(N *sizeof(int));
  if(p == NULL){
   return 1;
    }

//outra forma sem forçar cast de malloc
    int *p = malloc(N *sizeof *p);
        if (p == NULL){
            return 1;
        }

    for(i = 0; i < N; i++){
        scanf("%d", &p[i]);
    }
    
    int menor_valor = *p;
    int posicao = 0;
    
    for(j = 1; j < N; j++){
        if(p[j] < menor_valor){
            menor_valor = p[j];
            posicao = j;

        }
    }
    printf("%d\n", menor_valor);
    printf("%d\n", posicao);

    free(p);

    return 0;
}


//o que aprendemos?
//como utilizar malloc
//p = endereço
//*p = valor do endereço