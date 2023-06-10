#include "struct.h"


// * LINHAS
void adicionarLinhas(Linha** linhas, int* numero_linhas)
{
   Linha *nova = (Linha*)malloc(sizeof(Linha));
   Linha l;

   if (nova == NULL) {
      printf("Erro 101\n");
      return;
   }

   do
   {
      printf("Nome: ");
      scanf("%s", nova->Nome);
      l = procuraLinhaEspecifica(*linhas, *numero_linhas, nova->Nome);
      if(strcmp(l.Nome, "") != 0) {
         puts("Nome ja existe, escolha outro...\n");
      }
      else {
         break;
      }

   } while (1);
   
   nova->Nome[strcspn(nova->Nome, "\n")] = '\0';

   nova->numero_paragens = 0;
   nova->paragens = NULL;

   (*linhas) = (Linha*)realloc((*linhas), (*numero_linhas + 1) * sizeof(Linha));
   (*linhas)[*numero_linhas] = *nova;

   (*numero_linhas)++;
   puts("Linha adicionada com sucesso!\n");
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
      if (strcmp((*linhas)[i].Nome, NomeLinha) == 0)
      {
         free((*linhas)[i].paragens);
         
         for (int j = i; j < *numero_linhas - 1; j++)
         {
            (*linhas)[j] = (*linhas)[j + 1];
         }
         (*numero_linhas)--;
         
         // Allocate new memory for the last element
         (*linhas) = (Linha*)realloc((*linhas), (*numero_linhas) * sizeof(Linha));
         
         printf("A linha com o nome %s foi eliminada com sucesso!\n", NomeLinha);
         return true;
      }
   }
   
   printf("Nenhuma linha com o nome %s foi encontrada.\n", NomeLinha);
   return false;
}


Linha procuraLinhaEspecifica(Linha* linhas, int numero_linhas, char NomeLinha[TAMANHO_MAX])
{
   for (int i = 0; i < numero_linhas; i++)
   {
      if (strcmp(linhas[i].Nome, NomeLinha) == 0)
      {
         return linhas[i];
      }
   }
   
   printf("Nao houve nenhuma linha com o nome %s encontrada!\n", NomeLinha);
   Linha linhaVazia = {"", 0, 0, NULL};
   return linhaVazia;
}

// * PARAGENS

Paragem procurarParagemEspecifica(Paragem* paragens, int numero_paragens, char NomeParagem[TAMANHO_MAX])
{
   for (int i = 0; i < numero_paragens; i++)
   {
      if (strcmp(paragens[i].Nome, NomeParagem) == 0)
      {
         return paragens[i];
      }
   }

   printf("Nao foi encontrada nenhuma paragem com o nome %s.\n", NomeParagem);
   Paragem paragemVazia = { "", "", 0, 0, NULL, NULL };
   return paragemVazia;
}

void registarParagem(Paragem** paragens, int* numero_paragens)
{
   Paragem nova;
   printf("Nome da paragem: ");
   scanf("%s", nova.Nome);
   printf("Codigo da paragem: ");
   scanf("%s", nova.Codigo);

   Paragem p = procurarParagemEspecifica(*paragens, *numero_paragens, nova.Nome);
   if (strcmp(p.Nome, "") != 0)
   {
      printf("A paragem com o nome %s ja existe. Nao e possivel registar novamente.\n", nova.Nome);
      return;
   }

   (*paragens) = (Paragem*)realloc((*paragens), (*numero_paragens + 1) * sizeof(Paragem));
   (*paragens)[*numero_paragens] = nova;
   (*numero_paragens)++;

   printf("Paragem registada com sucesso!\n");
}

void visualizarParagens(Paragem* paragens, int numero_paragens)
{
   printf("Lista de Paragens:\n");
   for (int i = 0; i < numero_paragens; i++)
   {
      printf("Paragem %d:\n", i + 1);
      printf(" . Nome: %s\n", paragens[i].Nome);
      printf(" . Codigo: %s\n", paragens[i].Codigo);
      printf(" . Numero de Paragens: %d\n", paragens[i].numero_paragens);
      printf(" . Numero de Linhas: %d\n", paragens[i].numeros_linhas);
   }
}

bool eliminarParagem(Paragem** paragens, int* numero_paragens)
{
   char NomeParagem[TAMANHO_MAX];
   printf("Digite o nome da paragem a ser eliminada: ");
   scanf("%s", NomeParagem);

   for (int i = 0; i < *numero_paragens; i++)
   {
      if (strcmp((*paragens)[i].Nome, NomeParagem) == 0)
      {
         free((*paragens)[i].proxima);
         free((*paragens)[i].anterior);

         for (int j = i; j < *numero_paragens - 1; j++)
         {
            (*paragens)[j] = (*paragens)[j + 1];
         }
         (*numero_paragens)--;

         (*paragens) = (Paragem*)realloc((*paragens), (*numero_paragens) * sizeof(Paragem));

         printf("A paragem com o nome %s foi eliminada com sucesso!\n", NomeParagem);
         return true;
      }
   }

   printf("Nenhuma paragem com o nome %s foi encontrada.\n", NomeParagem);
   return false;
}