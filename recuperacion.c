#include <stdio.h>
#include <string.h>

int main() {
    char nombres[5][50];
    float tiempos[5][3];
    int distancias[3] = {50, 100, 200};
    float suma_tiempos[5] = {0};
    int i, j;

    for (i = 0; i < 5; i++) {
        int valido = 0;
        while (!valido) {
            valido = 1;
            printf("Ingrese el nombre del nadador %d: ", i + 1);
            scanf("%s", nombres[i]);

            for (int k = 0; nombres[i][k] != '\0'; k++) {
                if (nombres[i][k] >= '0' && nombres[i][k] <= '9') {
                    printf("El nombre no puede contener numeros.\n");
                    valido = 0;
                    break;
                }
            }
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            int valido = 0;
            while (!valido) {
                printf("Ingrese el tiempo de %s para %d metros: ", nombres[i], distancias[j]);
                if (scanf("%f", &tiempos[i][j]) != 1 || tiempos[i][j] <= 0) {
                    printf("Tiempo invalido.\n");
                    while (getchar() != '\n'); 
                } else {
                    valido = 1;
                }
            }
        }
    }

    printf("\nGanadores por competencia\n");
    for (j = 0; j < 3; j++) {
        int ganador = 0;
        for (i = 1; i < 5; i++) {
            if (tiempos[i][j] < tiempos[ganador][j]) {
                ganador = i;
            }
        }
        printf("Ganador en %d metros: %s con %.2f segundos\n", distancias[j], nombres[ganador], tiempos[ganador][j]);
    }

    int ganador_total = 0;
    for (i = 0; i < 5; i++) {
        suma_tiempos[i] = 0;
        for (j = 0; j < 3; j++) {
            suma_tiempos[i] += tiempos[i][j];
        }
        if (suma_tiempos[i] < suma_tiempos[ganador_total]) {
            ganador_total = i;
        }
    }

    printf("\nGanador total\n");
    printf("Ganador total: %s con %.2f segundos acumulados\n", nombres[ganador_total], suma_tiempos[ganador_total]);

    return 0;
}
