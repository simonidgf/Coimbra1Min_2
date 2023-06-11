#include "struct.h"

// *************************************************************************************************************************
// * LINHAS
// *************************************************************************************************************************

void adicionarLinhas(Linha** linhas, int* numero_linhas)
{
   Linha *nova = (Linha*)malloc(sizeof(Linha));

   if (nova == NULL) {
      printf("Erro 101\n");
      return;
   }

   do
   {
      printf("Nome: ");
      scanf("%s", nova->Nome);
      Linha l = procuraLinhaEspecifica(*linhas, *numero_linhas, nova->Nome);
      if(strcmp(l.Nome, "") != 0) {
         puts("Nome ja existe, escolha outro...\n");
      }
      else {
         break;
      }

   } while (1);
   
   nova->Nome[strcspn(nova->Nome, "\n")] = '\0';

   nova->numero_paragens = 0;
   nova->numeros_linhas = (*numero_linhas) + 1;
   nova->paragens = NULL;

   (*linhas) = (Linha*)realloc((*linhas), ((*numero_linhas) + 1) * sizeof(Linha));
   if ((*linhas) == NULL) {
      printf("Erro 102\n");
      free(nova);
      return;
   }

   (*linhas)[*numero_linhas] = *nova;
   (*numero_linhas)++;

   free(nova);
}

void visualizarLinhas(Linha* linhas, int numero_linhas)
{
   printf("Linhas Disponiveis:\n");

   if (numero_linhas == 0) {
      printf("Nao ha linhas disponiveis.\n");
      return;
   }

   for (int i = 0; i < numero_linhas; i++) {
      printf("- %s\n", linhas[i].Nome);

      if (linhas[i].numero_paragens == 0) {
         printf("  Nao ha paragens adicionadas.\n");
      } else {
         printf("  Paragens .:\n");
         for (int j = 0; j < linhas[i].numero_paragens; j++) {
            printf("  - %s\n", linhas[i].paragens[j].Nome);
         }
      }
   }
}

bool eliminarLinha(Linha** linhas, int* numero_linhas)
{
   if (*numero_linhas == 0) {
      printf("Nao ha linhas disponiveis para eliminar.\n");
      return false;
   }

   char nomeLinha[TAMANHO_MAX];
   printf("Nome da linha a eliminar: ");
   scanf("%s", nomeLinha);

   for (int i = 0; i < *numero_linhas; i++) {
      if (strcmp((*linhas)[i].Nome, nomeLinha) == 0) {
         free((*linhas)[i].paragens);
         for (int j = i; j < (*numero_linhas) - 1; j++) {
            (*linhas)[j] = (*linhas)[j + 1];
         }
         *numero_linhas = *numero_linhas - 1;
         *linhas = (Linha*)realloc(*linhas, (*numero_linhas) * sizeof(Linha));
         printf("Linha \"%s\" eliminada com sucesso.\n", nomeLinha);
         return true;
      }
   }

   printf("Nao houve nenhuma linha com o nome %s encontrada!\n", nomeLinha);
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

// *************************************************************************************************************************
// * PARAGENS
// *************************************************************************************************************************

Paragem procurarParagemEspecifica(Paragem* paragens, int numero_paragens, char NomeParagem[TAMANHO_MAX])
{
   for (int i = 0; i < numero_paragens; i++)
   {
      if (strcmp(paragens[i].Nome, NomeParagem) == 0)
      {
         return paragens[i];
      }
   }


   Paragem paragemVazia = { "", "", 0, 0, NULL, NULL };
   return paragemVazia;
}

void registarParagem(Paragem** paragens, int* numero_paragens)
{
   Paragem nova;
   srand(time(NULL));
   char str[6];
   const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

   printf("Nome da paragem: ");
   scanf("%s", nova.Nome);

   str[0] = '#';
   for (int i = 1; i < 5; i++) {
      str[i] = charset[rand() % (sizeof(charset) - 1)];
   }
   str[5] = '\0';
   strcpy(nova.Codigo, str);

   Paragem p = procurarParagemEspecifica(*paragens, *numero_paragens, nova.Nome);
   if (strcmp(p.Nome, "") != 0)
   {
      printf("A paragem com o nome %s ja existe. Nao e possivel registar novamente.\n", nova.Nome);
      return;
   }

   nova.proxima = NULL;
   nova.anterior = NULL;

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
      printf("Paragem %d.:\n", i + 1);
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


// * * Funções do Atualizar

void adicionarParagemLinha(Linha* linha, Paragem* paragem)
{
   Paragem* novaParagem = (Paragem*)malloc(sizeof(Paragem));
   if (novaParagem == NULL) {
      printf("Erro 103\n");
      return;
   }

   *novaParagem = *paragem;
   novaParagem->proxima = linha->paragens;
   novaParagem->anterior = NULL;

   if (linha->paragens != NULL) {
      linha->paragens->anterior = novaParagem;
   }

   linha->paragens = novaParagem;
   linha->numero_paragens++;
}

bool removerParagemLinha(Linha* linha, char* nomeParagem)
{
   Paragem* current = linha->paragens;

   while (current != NULL) {
      if (strcmp(current->Nome, nomeParagem) == 0) {
         if (current->anterior != NULL) {
            current->anterior->proxima = current->proxima;
         } else {
            linha->paragens = current->proxima;
         }

         if (current->proxima != NULL) {
            current->proxima->anterior = current->anterior;
         }

         free(current);
         linha->numero_paragens--;
         printf("Paragem \"%s\" removida com sucesso.\n", nomeParagem);
         return true;
      }

      current = current->proxima;
   }

   printf("Nao houve nenhuma paragem com o nome %s encontrada!\n", nomeParagem);
   return false;
}

void atualizar(Linha* linhas, int numero_linhas)
{
   char nome[TAMANHO_MAX];
   printf("Que linha pretende atualizar (Nome): ");
   scanf("%s", nome);

   Linha* linha = NULL;
   for (int i = 0; i < numero_linhas; i++) {
      if (strcmp(linhas[i].Nome, nome) == 0) {
         linha = &linhas[i];
         break;
      }
   }

   if (linha == NULL) {
      printf("Nao houve nenhuma linha com o nome %s encontrada!\n", nome);
      printf("Linha nao existe...\n");
      return;
   }

   int opcao;
   do {
      printf("\n:.           Atualizar (%s)       .:\n", linha->Nome);
      printf(" : 1. Adicionar Paragem a uma Linha :\n");
      printf(" : 2. Remover Paragem de uma Linha  :\n");
      printf(" : 0. Voltar                        :\n");
      printf(".:> ");
      scanf("%d", &opcao);

      switch (opcao) {
         case 1:
            printf("Paragem para adicionar: ");
            char nome_paragem[TAMANHO_MAX];
            scanf("%s", nome_paragem);

            Paragem paragem;
            strcpy(paragem.Nome, nome_paragem);

            adicionarParagemLinha(linha, &paragem);
            break;
         case 2:
            printf("Paragem para remover: ");
            char nome_paragem_remover[TAMANHO_MAX];
            scanf("%s", nome_paragem_remover);

            removerParagemLinha(linha, nome_paragem_remover);
            break;
         case 0:
            return;
         default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
      }
   } while (opcao != 0);
}
