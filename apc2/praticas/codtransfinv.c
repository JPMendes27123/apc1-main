#include <stdio.h>

// det 2x2
double calcDet2(double m[2][2]) {
    return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
}

// det 3x3
double calcDet3(double m[3][3]) {
    return ((m[0][0] * m[1][1] * m[2][2]) + (m[0][1] * m[1][2] * m[2][0]) + (m[0][2] * m[1][0] * m[2][1])) - 
           ((m[2][0] * m[1][1] * m[0][2]) + (m[2][1] * m[1][2] * m[0][0]) + (m[2][2] * m[1][0] * m[0][1]));
}

// Inverte 2x2
void invert2(double m[2][2], double inv[2][2]) {
    double det = calcDet2(m);
    
    inv[0][0] = m[1][1] / det;
    inv[0][1] = -m[0][1] / det;
    inv[1][0] = -m[1][0] / det;
    inv[1][1] = m[0][0] / det;
}

// Inverte 3x3 - escalonamento
int invert3(double m[3][3], double inv[3][3]) {
    int i, j, k;
    double temp;
    
    // inversa inicia = identidade
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            inv[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    
    // Escalonamento
    for (k = 0; k < 3; k++) {
        temp = m[k][k];
        if (temp == 0.0) {
            for (i = k + 1; i < 3; i++) {
                if (m[i][k] != 0.0) {
                    for (j = 0; j < 3; j++) {
                        temp = m[k][j];
                        m[k][j] = m[i][j];
                        m[i][j] = temp;
                        
                        temp = inv[k][j];
                        inv[k][j] = inv[i][j];
                        inv[i][j] = temp;
                    }
                    break;
                }
            }
            if (i == 3) return 0;
        }
        
        temp = m[k][k];
        for (j = 0; j < 3; j++) {
            m[k][j] /= temp;
            inv[k][j] /= temp;
        }
        
        for (i = 0; i < 3; i++) {
            if (i != k && m[i][k] != 0.0) {
                temp = m[i][k];
                for (j = 0; j < 3; j++) {
                    m[i][j] -= m[k][j] * temp;
                    inv[i][j] -= inv[k][j] * temp;
                }
            }
        }
    }
    
    return 1;
}

// print matriz 2x2
void printMatrix2(double m[2][2]) {
    printf("A matriz inversa da transformacao T⁻¹ sera:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%.2f\t", m[i][j]);
        }
        printf("\n");
    }
}

// print matriz 3x3
void printMatrix3(double m[3][3]) {
    printf("A matriz inversa da transformacao T⁻¹ sera:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", m[i][j]);
        }
        printf("\n");
    }
}



int main(void) {
    printf("Digite qual o valor de n, para informar qual espaco vetorial sera trabalhado:\n");
    
    int n = 0;
    scanf("%d", &n);

    // R²
    if (n == 2) { 
        printf("Digite os elementos da matriz transformacao 2x2 (elementos linha por linha):\n");

        double m[2][2];
        double inv[2][2];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                scanf("%lf", &m[i][j]);
            }
        }

        double det = calcDet2(m);

        if (det == 0) { 
            printf("O determinante da matriz é igual a 0. Portanto, ela não é inversivel.\n");
            return 0;
        } else {
            printf("O determinante da matriz eh: %.2f. Portanto, eh inversivel\n", det);
            invert2(m, inv);
            printMatrix2(inv);
        }

    } 
    // R³
    else if (n == 3) {
        printf("Digite os elementos da matriz transformacao 3x3 (linha por linha):\n");

        double m[3][3];
        double inv[3][3];
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%lf", &m[i][j]);
            }
        }  
        
        double det = calcDet3(m);

        if (det == 0) {
            printf("O determinante da matriz é igual a 0. Portanto, ela não é inversivel.\n");
            return 0;
        } else {
            printf("O determinante da matriz eh: %.2f. Portanto, eh inversivel\n", det);
            if (invert3(m, inv)) {
                printMatrix3(inv);
            } else {
                printf("Erro na inversão da matriz.\n");
            }
        }

    }
    else {
        printf("O codigo nao tem a capacidade de trabalhar nesse espaco.\n");
    }
    
    return 0;
}