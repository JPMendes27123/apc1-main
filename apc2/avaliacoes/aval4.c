#include <stdio.h>

int f(int n) {
    // critério de parada
    if (n == 1) return 1;
    // passo recursivo (n > 1)
    return n + f(n - 1);
}

int f1(int n) {
    // critério de parada
    if (n == 1) return 2;
    // passo recursivo (n > 1)
    return f(n - 1) + 3;
}

int f2(int n) {
    // critério de parada
    if (n == 1) return 3;
    // passo recursivo (n > 1)
    return 2 * f(n - 1);
}

int f3(int n) {
    // critério de parada
    if (n == 1) return 0;
    // passo recursivo (n > 1)
    return f(n - 1) + (n - 1);
}

int main () {

return 0;
}