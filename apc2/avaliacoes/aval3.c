#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *build_int_array(unsigned int size){
    int *v = malloc(sizeof (int) * size);
    return v;
}

float *media_das_notas(int m, int n, float matriz[m][n]){
    float *media = (float*)malloc(sizeof (float) * m);

    for (int i = 0; i < m; i++) {
        float soma = 0.0;
            for (int j = 0; j < n; j++) {
                soma += matriz[i][j];
        }
    media[i] = soma/n;
    }
    return media;
}

char *repete_string(char str[], int n){
    int size_str = strlen(str);
    int size1 = (size_str * n) + 1;
    char *r = malloc(size1);
    
    r[0] = '\0';
    for (int i = 0; i < n; i++) {
        strcat(r, str);
    }

    return r;
}

int main() {

int m = 3, n = 2;
    float notas[3][2] = {
        {5, 7},
        {8, 7},
        {6, 10}
    };
float *medias = medias_das_notas(m, n, notas);

    if (medias != NULL) {
        printf("Médias:\n");
        for (int i = 0; i < m; i++) {
            printf("Aluno %d: %.1f\n", i, medias[i]);
        }
        free(medias);
    }

char *r = repete_string("Ana", 3);
    
    if (r != NULL) {
        printf("Resultado: %s\n", r);
        free(r);
    }

return 0;
}