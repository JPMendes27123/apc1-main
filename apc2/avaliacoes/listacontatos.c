#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
  char nome[200];
  char cpf[12];
  unsigned int idade;
} Pessoa;

// Variáveis globais
Pessoa *pessoas = NULL;
int tam_vetor = 0;

// Protótipos de funções
void inserir(Pessoa p);
void deletar(char *cpf);
void listar();
void buscar(char *cpf);
void carregar_vetor_txt(char *caminho_arquivo);
void salvar_vetor_txt(char *caminho_arquivo);
void carregar_vetor_bin(char *caminho_arquivo);
void salvar_vetor_bin(char *caminho_arquivo);

// Funções auxiliares
void ler_cpf(char *cpf, const char *operacao) {
  printf("Forneça o CPF a ser %s: ", operacao);
  scanf("%11s", cpf);
  while(getchar() != '\n'); // Limpa o buffer
}

void ler_pessoa(Pessoa *p) {
  printf("Nova pessoa:\n");
  printf("-------------------------\n");
  
  printf("Nome: ");
  if(fgets(p->nome, 200, stdin) == NULL) {
    p->nome[0] = '\0';
  } else {
    // Remove a quebra de linha se existir
    p->nome[strcspn(p->nome, "\n")] = '\0';
  }
  
  printf("CPF: ");
  scanf("%11s", p->cpf);
  while(getchar() != '\n'); // Limpa o buffer
  
  printf("Idade: ");
  scanf("%u", &p->idade);
  while(getchar() != '\n'); // Limpa o buffer
}

void ler_caminho(char *caminho) {
  printf("Forneça o caminho do arquivo: ");
  scanf("%99s", caminho);
  while(getchar() != '\n'); // Limpa o buffer
}

// Implementação das funções principais (mantidas como no seu código original)
void inserir(Pessoa p) {
  tam_vetor++;
  pessoas = realloc(pessoas, sizeof(Pessoa) * tam_vetor);
  if (pessoas == NULL) {
    fprintf(stderr, "Erro ao alocar memória!\n");
    exit(1);
  }
  pessoas[tam_vetor - 1] = p;
  printf("Pessoa inserida com sucesso!\n");
}

void deletar(char *cpf) {
  int i, j;
  int encontrado = 0;

  for (i = 0; i < tam_vetor; i++) {
    if (strcmp(pessoas[i].cpf, cpf) == 0) {
      encontrado = 1;
      break;
    }
  }

  if (!encontrado) {
    printf("Pessoa com CPF %s não encontrada.\n", cpf);
    return;
  }

  for (j = i; j < tam_vetor - 1; j++) {
    pessoas[j] = pessoas[j + 1];
  }

  tam_vetor--;
  pessoas = realloc(pessoas, sizeof(Pessoa) * tam_vetor);
  if (tam_vetor > 0 && pessoas == NULL) {
    fprintf(stderr, "Erro ao realocar memória!\n");
    exit(1);
  }

  printf("Pessoa deletada com sucesso!\n");
}

void listar() {
  if (tam_vetor == 0) {
    printf("Lista vazia!\n");
    return;
  }

  for (int i = 0; i < tam_vetor; i++) {
    printf("{nome: %s, CPF: %s, idade: %d}\n",
      pessoas[i].nome, pessoas[i].cpf, pessoas[i].idade);
  }
}

void buscar(char *cpf) {
  if (tam_vetor == 0) {
    printf("Lista vazia!\n");
    return;
  }

  int encontrado = 0;
  for (int i = 0; i < tam_vetor; i++) {
    if (strcmp(pessoas[i].cpf, cpf) == 0) {
      printf("{nome: %s, CPF: %s, idade: %d}\n",
        pessoas[i].nome, pessoas[i].cpf, pessoas[i].idade);
      encontrado = 1;
      break;
    }
  }

  if (!encontrado) {
    printf("Pessoa com CPF %s não encontrada.\n", cpf);
  }
}

void carregar_vetor_txt(char *caminho_arquivo) {
  FILE *input = fopen(caminho_arquivo, "r");
  if(!input) {
    fprintf(stderr, "Arquivo inválido!\n");
    return;
  }

  Pessoa p;
  int dados_lidos;
  while(!feof(input)) {
    dados_lidos = fscanf(input, "%199[^\t]\t%11s\t%d\n",
      p.nome, p.cpf, &p.idade);
    if(dados_lidos != 3) break;
    tam_vetor++;
    pessoas = realloc(pessoas, sizeof(Pessoa)*tam_vetor);
    strcpy(pessoas[tam_vetor-1].nome, p.nome);
    strcpy(pessoas[tam_vetor-1].cpf, p.cpf);
    pessoas[tam_vetor-1].idade = p.idade;
  }
  printf("Contatos carregados com sucesso!\n");
  fclose(input);
} 

void salvar_vetor_txt(char *caminho_arquivo) {
  FILE *output = fopen(caminho_arquivo, "w");
  if (!output) {
    fprintf(stderr, "Erro ao abrir o arquivo para escrita!\n");
    return;
  }

  for (int i = 0; i < tam_vetor; i++) {
    fprintf(output, "%s\t%s\t%d\n",
      pessoas[i].nome, pessoas[i].cpf, pessoas[i].idade);
  }

  printf("Contatos salvos em TXT com sucesso!\n");
  fclose(output);
}

void carregar_vetor_bin(char *caminho_arquivo) {
  FILE *input = fopen(caminho_arquivo, "rb");
  if (!input) {
    fprintf(stderr, "Erro ao abrir o arquivo binário!\n");
    return;
  }

  fread(&tam_vetor, sizeof(int), 1, input);

  pessoas = realloc(pessoas, sizeof(Pessoa) * tam_vetor);
  if (pessoas == NULL && tam_vetor > 0) {
    fprintf(stderr, "Erro ao alocar memória!\n");
    fclose(input);
    exit(1);
  }

  fread(pessoas, sizeof(Pessoa), tam_vetor, input);

  printf("Contatos carregados do BIN com sucesso!\n");
  fclose(input);
}

void salvar_vetor_bin(char *caminho_arquivo) {
  FILE *output = fopen(caminho_arquivo, "wb");
  if (!output) {
    fprintf(stderr, "Erro ao abrir o arquivo binário para escrita!\n");
    return;
  }

  fwrite(&tam_vetor, sizeof(int), 1, output);
  fwrite(pessoas, sizeof(Pessoa), tam_vetor, output);

  printf("Contatos salvos no BIN com sucesso!\n");
  fclose(output);
}

int main() {
  char ch = '\0';
  while(ch != 'q' && ch != 'Q') {
    printf("\033[2J\033[H"); // Limpa a tela
    printf("      Lista de Contatos    \n");
    printf("---------------------------\n");
    printf("1 - Listar.\n");
    printf("2 - Buscar.\n");
    printf("3 - Inserir.\n");
    printf("4 - Deletar.\n");
    printf("5 - Carregar pessoas (TXT).\n");
    printf("6 - Salvar pessoas (TXT).\n");
    printf("7 - Carregar pessoas (BIN).\n");
    printf("8 - Salvar pessoas (BIN).\n");
    printf("Q - Sair.\n");
    printf("Opção: ");
    scanf("%c", &ch);
    while(getchar() != '\n'); // Limpa o buffer
    
    switch(ch) {
      case '1': listar(); break;
      case '2': {
        char cpf[12];
        ler_cpf(cpf, "buscado");
        buscar(cpf);
        break;
      }
      case '3': {
        Pessoa p;
        ler_pessoa(&p);
        inserir(p);
        break;
      }
      case '4': {
        char cpf[12];
        ler_cpf(cpf, "deletado");
        deletar(cpf);
        break;
      }
      case '5': {
        char caminho_arquivo[100];
        ler_caminho(caminho_arquivo);
        carregar_vetor_txt(caminho_arquivo);
        break;
      }
      case '6': {
        char caminho_arquivo[100];
        ler_caminho(caminho_arquivo);
        salvar_vetor_txt(caminho_arquivo);
        break;
      }
      case '7': {
        char caminho_arquivo[100];
        ler_caminho(caminho_arquivo);
        carregar_vetor_bin(caminho_arquivo);
        break;
      }
      case '8': {
        char caminho_arquivo[100];
        ler_caminho(caminho_arquivo);
        salvar_vetor_bin(caminho_arquivo);
        break;
      }
    }
    printf("Pressione enter para continuar.");
    getchar();
  }
  
  if(pessoas != NULL) {
    free(pessoas);
    pessoas = NULL;
  }
  
  return 0;
}