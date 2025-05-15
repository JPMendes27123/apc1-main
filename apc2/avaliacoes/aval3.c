#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    //funcao 1
int *build_int_array(unsigned int size){
    int *v = malloc(sizeof (int) * size);
    return v;
}
    //funcao 2
float *medias_das_notas(int m, int n, float matriz[m][n]){
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
    //funcao 3
char *repete_string(char str[], int n){
    int size_str = strlen(str);
    char *r = malloc(size_str * n + 1);
    
    char *p = r;
    for (int i = 0; i < n; i++) {
        strcpy(p, str);
        p += size_str;
    }
    *p = '\0';
    return r;
}



int main() {
    //teste 1
    int *v = build_int_array(10);
    free(v);
    //teste 2
    float notas[3][2] = {{5,7}, {8,7}, {6,10}};
    float *medias = medias_das_notas(3, 2, notas);

    if (medias != NULL) {
        printf("Saida da funcao:\n");
        printf("(float *) {");
        for (int i = 0; i < 3; i++) {
            printf("%.1f%s", medias[i], (i < 2) ? ", " : "");
        }
        printf("}\n");
        free(medias);
    }
    //teste 3
    char *r = repete_string("Ana", 3);

    if (r != NULL) {
        printf("\nSaida da funcao:\n");
        printf("(char *) \"%s\"\n", r);
        free(r);
    }

return 0;
}