#include <stdio.h>

int main() {

printf("\n%s\n", "=============================");
printf("%s\n", "     N O T A    L E G A L  ");
printf("%s\n", "=============================");
printf("%s\n", "Produto        Qtd Valor Unit");
printf("%-14s %03i %10.2f\n", "Camiseta", 2, 39.99);
printf("%-14s %03i %10.2f\n", "Calca", 1, 89.90);
printf("%-14s %03i %10.2f\n", "Meia Social", 3, 19.99);
printf("%s\n", "=============================");
printf("%-22s %.2f\n\n", "Total:", 229.85);
  return 0;
}