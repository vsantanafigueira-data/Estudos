#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int ehprimo(long long int x){

    if(x < 2) return 0;
    if(x == 2 || x == 3) return 1;
    if(x % 2 == 0 || x % 3 == 0) return 0;


    long long int limite = sqrt(x);
    for(long long int i = 5; i <= limite; i+=6) { //todos os números primos são escritos como 6k + 1 ou 6k - 1;
        if( x % i == 0 || x % (i + 2)== 0)
        return 0;
    }
    return 1;
}

int main(){


int N;
scanf("%d", &N);

while(N--){
    long long int x;
    scanf("%lld", &x);

    if(ehprimo(x))
        printf("Prime\n");
    else
        printf("Not Prime\n");
}

    return 0;
}   