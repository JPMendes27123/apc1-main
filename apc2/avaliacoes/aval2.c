#include <stdio.h>

//avaliacao - passagem parâmetros

// 1. c) i.
int inverter_sinal(int x) {
    return -x;
}

// 1. c) ii.
void inverter_sinal(int *x) {
    *x = -(*x);
}

// Ex 1
void incremento(int x) {
    x = x + 1;
}

// Ex 2
void incremento(int *x) {
    *x = *x + 1;
}

// 2. a)
int abs(int x) {
    return (x < 0) ? -x : x;
}

// 2. b)
int eVogal (char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' );
}

// 2. c)
int eQuadrado(int x, int y) {
    return (x == y *y);
}

// 2. d)
double obterSegundos(double horas) {
    return horas * 3600;
}

// 2. e)
double converterHoras(double horas, char formato) {
    switch (formato) {
    case 'H':
    case 'h':
    return horas;
    case 'M':
    case 'm':
    return horas * 60;
    case 'S':
    case 's':
    return horas * 3600;
    default:
    return -1;
    }
}

// 2. f)
void exibirMedia(int n, int *vet) {
    int soma = 0;
    for(int i = 0; i < n; i++) {
    soma+= vet[i];
    }
    printf("media: %d\n", soma / n);
}

// 2. g)
int buscarValor(int n, int *vet, int busca) {
    for(int i = 0; i < n; i++) {
    if (vet[i] == busca)
    return i;
    }
    return -1;
}

// 2. h)
void potencia(int *x, int y) {
    int resultado = 1;
    for (int i = 0; i < y; i++) {
    resultado *= *x;
    }
    *x = resultado;
}

// 2. i)
int preencherMatriz(int m, int n, int matriz[m][n] ) {
    for (int i = 0; i < m; i++){
    for (int j = 0; i < n; j++) {
    printf("Digite o valor para [%d] [%d]:\n", i, j);
    scanf("%d", &matriz[i][j]);
        }
    }
    return 1;
}

// 2. j)
void troca(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}
