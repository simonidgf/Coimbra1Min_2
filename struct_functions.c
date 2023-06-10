#include "struct.h"

void adicionarLinhas(Linha** linhas, int* numero_linhas)
{
   Linha *nova = (Linha*)malloc(sizeof(Linha));

   if (nova == NULL) {
      printf("Erro 101\n");
      return;
   }

   printf("Nome: ");
   scanf("%s", nova->Nome);
   nova->Nome[strcspn(nova->Nome, "\n")] = '\0';

   nova->numero_paragens = 0;

   nova->paragens = (Paragem*)malloc(nova->numero_paragens * sizeof(Paragem));

   if (nova->paragens == NULL) {
      printf("Erro 202\n");
      free(nova);
      return;
   }

   (*linhas) = (Linha*)realloc((*linhas), (*numero_linhas + 1) * sizeof(Linha));
   (*linhas)[*numero_linhas] = *nova;

   (*numero_linhas)++;

   free(nova);
}

void visualizarLinhas(Linha* linhas, int numero_linhas)
{
   if (numero_linhas == 0) {
      printf("Sem linhas para exibir.\n");
      return;
   }

   printf("Lista de Linhas:\n");

   for (int i = 0; i < numero_linhas; i++) 
   {
      printf("Linha %d.:\n", i + 1);
      printf(" . Nome: %s\n", linhas[i].Nome);
      printf(" . Numero de Paragens: %d\n", linhas[i].numero_paragens);
      if (linhas[i].numero_paragens != 0)
      {
         printf("Paragens:\n");
         for (int j = 0; j < linhas[i].numero_paragens; j++) {
            printf("Paragem %d: %s\n", j + 1, linhas[i].paragens[j].Nome);
         }
      }

      printf("\n");
   }
}

bool eliminarLinha(Linha** linhas, int* numero_linhas)
{
   char NomeLinha[TAMANHO_MAX];
   printf("Digite o nome da linha a ser eliminada: ");
   scanf("%s", NomeLinha);
   
   for (int i = 0; i < *numero_linhas; i++)
   {
      if (strcmp(linhas[i]->Nome, NomeLinha) == 0)
      {
         free(linhas[i]);
         
         for (int j = i; j < *numero_linhas - 1; j++)
         {
            linhas[j] = linhas[j + 1];
         }
         (*numero_linhas)--;
         
         printf("A linha com o nome %s foi eliminada com sucesso!\n", NomeLinha);
         return true;
      }
   }
   
   printf("Nenhuma linha com o nome %s foi encontrada.\n", NomeLinha);
   return false;
}


Linha procuraLinhaEspecifica(Linha** linhas, int* numero_linhas)
{
   char NomeLinha[TAMANHO_MAX];
   printf("Digite o nome da linha a ser procurada: ");
   scanf("%s", NomeLinha);
   
   for (int i = 0; i < *numero_linhas; i++)
   {
      if (strcmp(linhas[i]->Nome, NomeLinha) == 0)
      {
         return *linhas[i];
      }
   }
   
   printf("Nao houve nenhuma linha com o nome %s encontrada!\n", NomeLinha);
   Linha linhaVazia = {"", 0, 0, NULL};
   return linhaVazia;
}