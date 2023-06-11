#include "struct_functions.c"


void menuParagens(Paragem** array_paragens, Linha** array_linhas, int* numero_linhas, int* numero_paragens);
void menuLinhas(Paragem** array_paragens, Linha** array_linhas, int* numero_linhas, int* numero_paragens);

int main() {
   Paragem* array_paragens = NULL;
   Linha* array_linhas = NULL;
   int numero_paragens = 0, numero_linhas = 0;
   int opcao;

   do {
      printf("\n=====================\n");
      printf("=        Menu       =\n");
      printf("=====================\n");
      printf("= 1. Linhas         =\n");
      printf("= 2. Paragens       =\n");
      printf("= 0. Sair           =\n");
      printf("=====================\n");

      printf("Escolha uma opcao: ");
      scanf("%d", &opcao);
      printf("\n");

      switch (opcao) {
         case 1:
            menuLinhas(&array_paragens, &array_linhas, &numero_linhas, &numero_paragens);
            break;
         case 2:
            menuParagens(&array_paragens, &array_linhas, &numero_linhas, &numero_paragens);
            break;
         case 0:
            printf("Ate Ja :D ... \n");
            exit(0);
         default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
      }
   } while (opcao != 0);

   return 0;
}

void menuParagens(Paragem** array_paragens, Linha** array_linhas, int* numero_linhas, int* numero_paragens) {
   int opcao;

   do {
      printf("=================\n");
      printf("=    Paragens   =\n");
      printf("=================\n");
      printf("= 1. Adicionar  =\n");
      printf("= 2. Eliminar   =\n");
      printf("= 3. Visualizar =\n");
      printf("=================\n");
      printf("= 9. Voltar     =\n");
      printf("= 0. Sair       =\n");
      printf("=================\n");
      printf("Escolha uma opcao: ");
      scanf("%d", &opcao);
      printf("\n");

      switch (opcao) {
         case 1:
            registarParagem(array_paragens, numero_paragens);
            break;
         case 2:
            eliminarParagem(array_paragens, numero_paragens);
            break;
         case 3:
            visualizarParagens(*array_paragens, *numero_paragens);
            break;
         case 9:
            return;
         case 0:
            printf("Ate Ja :D ... \n");
            exit(0);
         default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
      }
   } while (opcao != 0);
}

void menuLinhas(Paragem** array_paragens, Linha** array_linhas, int* numero_linhas, int* numero_paragens) {
   int opcao;

   do {
      printf("=================\n");
      printf("=     Linhas    =\n");
      printf("=================\n");
      printf("= 1. Adicionar  =\n");
      printf("= 2. Eliminar   =\n");
      printf("= 3. Visualizar =\n");
      printf("= 4. Atualizar  =\n");
      printf("=================\n");
      printf("= 9. Voltar     =\n");
      printf("= 0. Sair       =\n");
      printf("=================\n");
      printf("Escolha uma opcao: ");
      scanf("%d", &opcao);
      printf("\n");

      switch (opcao) {
         case 1:
            adicionarLinhas(array_linhas, numero_linhas);
            break;
         case 2:
            eliminarLinha(array_linhas, numero_linhas);
            break;
         case 3:
            visualizarLinhas(*array_linhas, *numero_linhas);
            break;
         case 4:
         {
            char NomeLinha[TAMANHO_MAX];
            Linha l;
            Paragem p;
            int opcao_atualizar;

            do {
               printf("Que linha pretende atualizar (Nome): ");
               scanf("%s", NomeLinha);
               l = procuraLinhaEspecifica(*array_linhas, *numero_linhas, NomeLinha);
               if (strcmp(l.Nome, "") == 0) {
                  puts("Linha nao existe...\n");
               } else {
                  break;
               }
            } while (1);

            printf("\n:.           Atualizar (%s)       .:\n", l.Nome);
            printf(" : 1. Adicionar Paragem a uma Linha :\n");
            printf(" : 2. Remover Paragem de uma Linha  :\n");
            printf(" : 0. Voltar                        :\n");

            do {
               printf(".:> ");
               scanf("%d", &opcao_atualizar);
            } while (opcao_atualizar != 1 && opcao_atualizar != 2 && opcao_atualizar != 0);

            switch (opcao_atualizar) {
               case 0:
                  return;
               case 1:
               {
                  char NomeParagem[TAMANHO_MAX];
                  do {
                     printf("Paragem para adicionar: ");
                     scanf("%s", NomeParagem);
                     p = procurarParagemEspecifica(*array_paragens, *numero_paragens, NomeParagem);
                     if (strcmp(p.Nome, "") == 0) {
                        puts("Paragem nao existe...\n");
                     } else {
                        break;
                     }
                  } while (1);
                  adicionarParagemLinha(&l, &p);
                  break;
               }
               case 2:
               {
                  char NomeParagem[TAMANHO_MAX];
                  do {
                     printf("Paragem para Remover: ");
                     scanf("%s", NomeParagem);
                     p = procurarParagemEspecifica(*array_paragens, *numero_paragens, NomeParagem);
                     if (strcmp(p.Nome, "") == 0) {
                        puts("Paragem nao existe...\n");
                     } else {
                        break;
                     }
                  } while (1);
                  removerParagemLinha(&l, p.Nome);
                  break;
               }
               default:
                  break;
            }
            break;
         }
         case 9:
            return;
         case 0:
            printf("Ate Ja :D ... \n");
            exit(0);
         default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
      }
   } while (opcao != 0);
}

