#include <stdio.h>

int main() {
long int ISBN = 13488578329 ;
int número = 736 ;
float preço = 359.90f ;
int ano = 2020 ;
printf("ISBN: %013ld\n", ISBN) ;
printf("Num. Paginas: %03i\n", número) ;
printf("Preco: R$ %04.2f\n", preço) ;
printf("Publicado em %04i\n", ano) ;

  return 0 ;
}