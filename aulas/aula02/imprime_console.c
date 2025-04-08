#include <stdio.h> //biblioteca entrada e saida

int main() {

  //imprime um texto simples
  printf("um texto sempre entre aspas duplas\n");

  //imprime um numero inteiro
  printf("%i\n", 10);
  printf("%i %i\n", 11, 22);

  //imprime um numero decimal
  printf("%f\n",10.5);
  printf("%10.2f\n", 10.5888);
  printf("%10.2f\n", 10155.5888);

  //imprime um caractere aspas simples
  printf("%c\n", 'A');
  printf("%c\n", 68);

  //imprime um string
  printf("%s\n", "Bom dia!");
  printf("%30s!\n", "Quero cafe");
  printf("%-30s!\n", "Quero cafe");
  
  return 0;
}
