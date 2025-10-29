#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

char imagem[MAX][MAX];
int visitado[MAX][MAX];
int N, M;

// Movimentos possíveis: cima, baixo, esquerda, direita
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y) {
    // marca pixel como visitado
    visitado[x][y] = 1;

    // tenta ir para os vizinhos
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        // verifica limites e se é pixel branco ainda não visitado
        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (imagem[nx][ny] == '.' && !visitado[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    getchar(); // consome o ENTER após o scanf

    for (int i = 0; i < N; i++) {
        fgets(imagem[i], MAX, stdin);
    }

    int regioes = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (imagem[i][j] == '.' && !visitado[i][j]) {
                dfs(i, j);
                regioes++;
            }
        }
    }

    printf("%d\n", regioes);
    return 0;
}
