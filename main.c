#include "struct_functions.c"

Paragem* array_paragens = NULL;
Linha* array_linhas = NULL;
int numero_paragens = 0, numero_linhas = 0;

void menuParagens(Paragem** array_paragens, int* numero_paragens);
void menuLinhas(Linha** array_linhas, int* numero_linhas);

int main()
{
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
            menuLinhas(&array_linhas, &numero_linhas);
            break;
         case 2:
            menuParagens(&array_paragens, &numero_paragens);
            break;
         case 0:
            printf("Ate Ja :D ... \n");
            exit(0);
            break;
         default:
            printf(" Opcao invalida. Tente novamente. \n");
            break;
      }
   } while (opcao != 0);

   return 0;
}

void menuParagens(Paragem** array_paragens, int* numero_paragens)
{
   int opcao;

   printf("============\n");
   printf("= Paragens =\n");
   printf("============\n");
}

void menuLinhas(Linha** array_linhas, int* numero_linhas)
{
   int opcao;

   do
   {
      printf("=================\n");
      printf("=     Linhas    =\n");
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
            adicionarLinhas(array_linhas, numero_linhas);
            break;
         case 2:
            eliminarLinha(array_linhas, numero_linhas);
            break;
         case 3:
            visualizarLinhas(*array_linhas, *numero_linhas);
            break;
         case 9:
            main();
            break;
         case 0:
            printf("Ate Ja :D ... \n");
            exit(0);
            break;
         default:
            printf(" Opcao invalida. Tente novamente. \n");
            break;
      }
   } while (opcao != 0);
   
}