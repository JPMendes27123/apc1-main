#include <stdio.h>

int main() {
long int matricula = 24238857 ;
int idade = 25 ;
float altura = 1.72f ;
float peso = 74.6f ;
char sexo = 'M' ;
printf("Matricula: %08ld\n", matricula) ;
printf("Idade: %02i anos\n", idade) ;
printf("Altura: %01.2f m\n", altura) ;
printf("Peso: %03.1f kg\n", peso) ;
printf("Sexo: %c\n", sexo) ;

  return 0 ;
}