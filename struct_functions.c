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
      if (strcmp(l.Nome, "") != 0) {
         puts("Nome ja existe, escolha outro...\n");
      }
      else {
         break;
      }

   } while (1);
   
   nova->Nome[strcspn(nova->Nome, "\n")] = '\0';

   nova->numero_paragens = 0;
   nova->paragens = NULL;
   nova->prox = NULL;

   if (*linhas == NULL) {
      *linhas = nova;  // A lista estava vazia, então o novo nó é o primeiro da lista
   } else {
      Linha* atual = *linhas;
      while (atual->prox != NULL) {
         atual = atual->prox;  // Avança até o último nó da lista
      }
      atual->prox = nova;  // Adiciona o novo nó como o próximo do último nó
   }

   (*numero_linhas)++;

   *linhas = (Linha*)realloc(*linhas, (*numero_linhas) * sizeof(Linha));
   if (*linhas == NULL) {
      printf("Erro 102\n");
      free(nova);
      return;
   }

   (*linhas)[*numero_linhas - 1] = *nova;
}

void visualizarLinhas(Linha* linhas, int numero_linhas)
{
   printf("Linhas Disponiveis:\n");
   for (int i = 0; i < numero_linhas; i++) {
      printf("- %s\n", linhas[i].Nome);
      Paragem* paragem = linhas[i].paragens;
      if (paragem == NULL) {
         printf("  Nao ha paragens adicionadas.\n");
      } else {
         printf("  Paragens adicionadas:\n");
         while (paragem != NULL) {
            printf("  - %s # %s\n", paragem->Nome, paragem->Codigo);
            paragem = paragem->proxima;
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
   if (paragem == NULL) {
      printf("Erro 103\n");
      return;
   }

   paragem->proxima = NULL;
   paragem->anterior = NULL;

   if (linha->paragens == NULL) {
      linha->paragens = (Paragem*)malloc(sizeof(Paragem));
      *linha->paragens = *paragem;
   } else {
      Paragem* nova_paragem = (Paragem*)realloc(linha->paragens, (linha->numero_paragens + 1) * sizeof(Paragem));
      if (nova_paragem == NULL) {
         printf("Erro na realocação de memória\n");
         return;
      }
      linha->paragens = nova_paragem;
      linha->paragens[linha->numero_paragens] = *paragem;

      // Configurar ligações entre as paragens
      linha->paragens[linha->numero_paragens - 1].proxima = &linha->paragens[linha->numero_paragens];
      linha->paragens[linha->numero_paragens].anterior = &linha->paragens[linha->numero_paragens - 1];
   }

   linha->numero_paragens++;
}


bool removerParagemLinha(Linha* linha, char* nomeParagem)
{
   Paragem* paragens = linha->paragens;

   for (int i = 0; i < linha->numero_paragens; i++)
   {
      if (strcmp(paragens[i].Nome, nomeParagem) == 0)
      {
         // Remover a paragem encontrada
         for (int j = i; j < linha->numero_paragens - 1; j++)
         {
            paragens[j] = paragens[j + 1];
         }

         linha->numero_paragens--;

         // Realocar a memória, se necessário
         Paragem* nova_paragem = (Paragem*)realloc(linha->paragens, linha->numero_paragens * sizeof(Paragem));
         if (nova_paragem == NULL && linha->numero_paragens > 0)
         {
            printf("Erro na realocação de memória\n");
            return false;
         }
         linha->paragens = nova_paragem;

         printf("Paragem \"%s\" removida com sucesso.\n", nomeParagem);
         return true;
      }
   }

   printf("Nao houve nenhuma paragem com o nome %s encontrada!\n", nomeParagem);
   return false;
}



void atualizar(Paragem* paragens, Linha* linhas, int numero_linhas, int numero_paragens)
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

            Paragem paragem = procurarParagemEspecifica(paragens, numero_paragens, nome_paragem);
            if (strcmp(paragem.Nome, "") == 0)
            {
               printf("A paragem com o nome %s nao existe\n", nome_paragem);
               break;
            }

            adicionarParagemLinha(linha, &paragem);
            break;

         case 2:
            printf("Paragem para remover: ");
            char nome_paragem_remover[TAMANHO_MAX];
            scanf("%s", nome_paragem_remover);

            Paragem p = procurarParagemEspecifica(paragens, numero_paragens, nome_paragem_remover);
            if (strcmp(p.Nome, "") == 0)
            {
               printf("A paragem com o nome %s não foi encontrada. Não é possível removê-la.\n", nome_paragem_remover);
               break;
            }

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







// * Percursos **************************************************

void calcularPercurso(Paragem* stops, Linha* lines) {
      char origem[32], destino[32];

      // Falta verificar existencia das stops
      printf("Origem: ");
      scanf(" %s", origem);
      printf("Destino: ");
      scanf(" %s", destino);

      int percusoEncontrado = 0, indiceOrigem = -1, indiceDestino = -1, indiceparagem1 = -1, indiceparagem2 = -1;
      Linha* line1 = NULL;
      Linha* line2 = NULL;
      Linha* atual = lines;

      while(atual != NULL) {
         int origemEncontrado = 0;

         // Loop passa em todas as stops da line atual e verifica se alguma coincide com a origem pretendida
         for(int i = 0; i < atual->numero_paragens; i++) {
               if (strcmp(atual->paragens[i].Nome, origem) == 0)
               {
                  origemEncontrado = 1;
                  indiceOrigem = i;
                  break;
               }
         }

         if (origemEncontrado) {
               // Loop passa outra vez em todas as stops da line atual e verifica se o destino fica na mesma line
               for (int i = 0; i < atual->numero_paragens; i++) {
                  if (strcmp(atual->paragens[i].Nome, destino) == 0)
                  {
                     percusoEncontrado = 1;
                     indiceDestino = i;
                     line1 = atual;
                     break;
                  }
               }

               if (!percusoEncontrado) {
                  Linha* conexao = lines;

                  while(conexao != NULL) {
                     int destinoEncontrado = 0;

                     for (int i = 0; i < conexao->numero_paragens; i++) {
                           if (strcmp(conexao->paragens[i].Nome, destino) == 0) 
                           {
                              destinoEncontrado = 1;
                              indiceDestino = i;
                              break;
                           }
                     }

                     if (destinoEncontrado) 
                     {
                           for (int i = 0; i < atual->numero_paragens; i++) {
                              for (int j = 0; j < conexao->numero_paragens; j++) {
                                 
                                 if (strcmp(atual->paragens[i].Nome, conexao->paragens[j].Nome) == 0) 
                                 {
                                       percusoEncontrado = 1;
                                       line1 = atual;
                                       line2 = conexao;

                                       indiceparagem1 = i;
                                       indiceparagem2 = j;
                                       break;
                                 }
                              }

                              if (percusoEncontrado) 
                              {
                                 break;
                              }
                           }
                     }

                     if (percusoEncontrado) 
                     {
                           break;
                     }

                     conexao = conexao->prox;
                  }
               } 

               if (percusoEncontrado)
               {
                  break;
               }
         }

         atual = atual->prox;
      }

      // Print no resultado
      if (percusoEncontrado)
      {
         printf("Percurso encontrado\n");

         if (line2 == NULL) 
         {
               printf("Linha: %s\n", line1->Nome);
               printf("Paragens:\n\n");

               if (indiceOrigem < indiceDestino) 
               {
                  for (int i = indiceOrigem; i <= indiceDestino; i++) 
                  {
                     printf("%s - %s\n", line1->paragens[i].Nome, line1->paragens[i].Codigo);
                  }
               }
               else
               {
                  
                  for (int i = indiceOrigem; i >= indiceDestino; i--)
                  {
                     printf("%s - %s\n", line1->paragens[i].Nome, line1->paragens[i].Codigo);
                  }
               }
         }
         else 
         {
               printf("Linha de origem: %s\n", line1->Nome);
               printf("Paragens:\n\n");


               if (indiceOrigem < indiceparagem1)
               {
                  for (int i = indiceOrigem; i <= indiceparagem1; i++) 
                  {
                     printf("%s - %s\n", line1->paragens[i].Nome, line1->paragens[i].Codigo);
                  }
               }
               else
               {
                  for(int i = indiceOrigem; i >= indiceparagem1; i--)
                  {
                     printf("%s - %s\n", line1->paragens[i].Nome, line1->paragens[i].Codigo);
                  }
               }

               printf("Transicao para a linha de destino: %s\n", line2->Nome);
               printf("Paragens:\n\n");

               if (indiceparagem2 < indiceDestino)
               {
                  for (int i = indiceparagem2; i <= indiceDestino; i++) 
                  {
                     printf("%s - %s\n", line2->paragens[i].Nome, line2->paragens[i].Codigo);
                  }
               }
               else
               {
                  for(int i = indiceparagem2; i >= indiceDestino; i--)
                  {
                     printf("%s - %s\n", line2->paragens[i].Nome, line2->paragens[i].Codigo);
                  } 
               }
         }


      }
      else 
      {
         printf("Não foi encontrado um percuso");
         return;
      }
}

