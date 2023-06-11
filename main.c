#include "struct_functions.c"
#include "dados.c"


const char* nomearquivo = "info";
Paragem* array_paragens = NULL;
Linha* array_linhas = NULL;
int numero_paragens = 0, numero_linhas = 0;

void menuParagens(Paragem** array_paragens, Linha** array_linhas, int* numero_linhas, int* numero_paragens);
void menuLinhas(Paragem** array_paragens, Linha** array_linhas, int* numero_linhas, int* numero_paragens);

int main() {
   int opcao;
   carregarDados(&array_linhas, &numero_linhas, &array_paragens, &numero_paragens, nomearquivo);

   do {
      printf("\n=====================\n");
      printf("=        Menu       =\n");
      printf("=====================\n");
      printf("= 1. Linhas         =\n");
      printf("= 2. Paragens       =\n");
      printf("= 3. Percurso       =\n");
      printf("=====================\n");
      printf("= 0. Sair           =\n");
      printf("= 99. Reset         =\n");
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

         case 3:
            calcularPercurso(array_paragens, array_linhas);
            break;

         case 0:
            guardarDados(array_linhas,numero_linhas, array_paragens, numero_paragens, nomearquivo);
            printf("Ate Ja :D ... \n");
            exit(0);

         case 99:
            array_paragens = NULL;
            array_linhas = NULL;
            numero_paragens = 0, numero_linhas = 0;
            break;
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
            guardarDados((*array_linhas),(*numero_linhas), (*array_paragens), (*numero_paragens), nomearquivo);
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
            atualizar(*array_paragens, *array_linhas, *numero_linhas, *numero_paragens);
            break;
         case 9:
            return;
         case 0:
            guardarDados((*array_linhas),(*numero_linhas), (*array_paragens), (*numero_paragens), nomearquivo);
            printf("Ate Ja :D ... \n");
            exit(0);
         default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
      }
   } while (opcao != 0);
}

