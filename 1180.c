//simples
#include <stdio.h>

int main(){


    int N;
    int vetor[1000];
    int i,j;
    int posicao;
    int menor_valor;

    scanf("%d", &N);

    for(i = 0; i < N; i++){
        scanf("%d", &vetor[i]);           
        }

    posicao = 0;
    menor_valor = vetor[0];

    for(j = 1; j < N; j++){
        if(vetor[j] < menor_valor){
            menor_valor = vetor[j];
            posicao = j;
        }


    }
    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao = %d", posicao);

return 0;
}