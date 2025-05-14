#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *pchar = malloc(sizeof (char)  * 101);
    
    float *pfloat = malloc(sizeof (float) * 15);
    
    struct pessoa{
        char nome[101];
        unsigned int idade;
        float salario;
    };
    
    struct pessoa *pessoa = malloc(sizeof (struct pessoa) * 20);
    
    printf("size of pessoa: %ld\n", sizeof (*pessoa));
    
    int **mat = malloc(5 * sizeof(int *) * 5);
    for(int i = 0; i < 5; i++){
    mat[i] = malloc(sizeof(int) * 5);
    }
     
    //int *mat = malloc(5 * 5 * sizeof(int));
    //mat[i * 5 + j] = valor;
     
        for (int i = 0; i < 5; i++) {
        free(mat[i]);
        }
        free(mat);
    
    return 0;
}