#include <stdio.h>

int main () { 
  int nota = 0;

printf("Entre com a nota do motorista: ");
int deu_certo = scanf("%i", &nota);

  if (nota == 1) {
    printf("Ganhou 1 estrela!\n");
  } else if (nota == 2) {
    printf("Ganhou 2 estrelas!\n");
  } else if (nota == 3) {
    printf("Ganhou 3 estrelas!\n");
  } else if (nota == 4) {
   printf("Ganhou 4 estrelas!\n");
  } else if (nota == 5) {
   printf("Ganhou 5 estrelas!\n");
  } else {
   printf("Nota invalida\n");
  }

  switch(nota) {
        case 1: printf("\nGanhou 1 estrela!\n"); break;
        case 2: printf("\nGanhou 2 estrelas!\n"); break;
        case 3: printf("\nGanhou 3 estrelas!\n"); break;
        case 4: printf("\nGanhou 4 estrelas!\n"); break;
        case 5: printf("\nGanhou 5 estrelas!\n"); break;
        default: printf("\nNota invalida\n"); break;
  }

   printf("\n   MENU PRINCIPAL\n");
   printf("-------------------\n");
   printf("1 - Consulta saldo\n");
   printf("2 - Recarrega saldo\n");
   printf("3 - Ver recados\n");
   printf("4 - Ultimas ligacoes\n\n");
   printf("5 - Sair\n");
   int opcao = 0;
   int deu_certo = scanf("%i", &opcao);

   switch(opcao) {
    case 1: printf("\nSaldo de R$ 10.00\n"); break;
    case 2: {
         printf("\nEscolha um valor: \n\n"); 
        int recarga = 0;
        deu_certo = scanf("%i", &recarga);
        switch(recarga) {
        case 10: printf("\nRecarga de R$ 10.00 realizada"); break;
        case 15: printf("\nRecarga de R$ 15.00 realizada"); break;
        case 20: printf("\nRecarga de R$ 20.00 realizada"); break;
        case 25: printf("\nRecarga de R$ 25.00 realizada"); break;
        case 30: printf("\nRecarga de R$ 30.00 realizada"); break;
        default: printf("\nOpcao invalida\n");
        }
     } break;
    
    case 3: printf("\nVoce tem 4 recados\n"); break;
    case 4: printf("\n61 8888-8888\n61 9999-9999\n"); break;
    case 5: printf("\nAte logo!\n"); break;
    default: printf("\nOpcao invalida\n");
   }

  return 0;
}