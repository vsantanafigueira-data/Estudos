#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
#define MAXN 100000

int primos[MAXN], eh_primo[MAXN+1], qtd_primos = 0;

long long potencia_mod(long long base, long long exp){
    long long resultado = 1;
    while(exp){
        if(exp & 1) resultado = (resultado * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return resultado;
}

long long inverso_mod(long long x){
    return potencia_mod(x, MOD - 2);
}

int main(){
    for(int i = 2; i <= MAXN; i++) eh_primo[i] = 1;
    for(int i = 2; i <= MAXN; i++){
        if(eh_primo[i]){
            primos[qtd_primos++] = i;
            for(long long j = 1LL * i * i; j <= MAXN; j += i)
                eh_primo[j] = 0;
        }
    }

    int N;
    long long fatorial = 1;

    while(scanf("%d", &N) != EOF){
        fatorial = 1;
        for(int i = 2; i <= N; i++)
            fatorial = (fatorial * i) % MOD;

        long long soma_divisores = 1;

        for(int i = 0; i < qtd_primos && primos[i] <= N; i++){
            int p = primos[i];
            long long expoente = 0;
            long long k = p;

            while(k <= N){
                expoente += N / k;
                k *= p;
            }

            long long numerador = (potencia_mod(p, expoente + 1) - 1 + MOD) % MOD;
            long long denominador = inverso_mod(p - 1);
            soma_divisores = (soma_divisores * ((numerador * denominador) % MOD)) % MOD;
        }

        long long soma_exceto_fat = (soma_divisores - fatorial + MOD) % MOD;

        printf("%lld %lld\n", soma_exceto_fat, fatorial);
    }

    return 0;
}
