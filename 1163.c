#include <stdio.h>
#include <math.h>

int main() {
    const double g  = 9.80665;
    const double PI = 3.14159;

    double h;
    int p1, p2;
    int n;

    // lê até EOF
    while (scanf("%lf", &h) == 1) {

        scanf("%d %d", &p1, &p2);
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {

            double alpha, V;
            scanf("%lf %lf", &alpha, &V);

            // converter para radianos
            double rad = alpha * PI / 180.0;

            // componentes da velocidade
            double Vx = V * cos(rad);
            double Vy = V * sin(rad);

            // discriminante sempre positivo
            double disc = Vy * Vy + 2.0 * g * h;

            // tempo até atingir o chão (raiz positiva)
            double t = (Vy + sqrt(disc)) / g;

            // alcance
            double x = Vx * t;

            // verifica se está dentro da Nlogônia
            if (x >= p1 && x <= p2)
                printf("%.5f -> DUCK\n", x);
            else
                printf("%.5f -> NUCK\n", x);
        }
    }

    return 0;
}
