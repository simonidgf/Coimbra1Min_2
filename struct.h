#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_PARAGENS 200
#define TAMANHO_MAX 100
#define TAMANHO_COD 6

typedef struct paragem
{
   char Nome[TAMANHO_MAX];
   char Codigo[TAMANHO_COD];
   int numero_paragens;
   int numeros_linhas;
   struct paragem *proxima;
   struct paragem *anterior;
} Paragem;

typedef struct linha
{
   char Nome[TAMANHO_MAX];
   int numero_paragens;
   Paragem *paragens;
   struct linha* prox;
} Linha;


// * Linhas
Linha procuraLinhaEspecifica(Linha* linhas, int numero_linhas, char NomeLinha[TAMANHO_MAX]);
void adicionarLinhas(Linha** linhas, int* numero_linhas);
void visualizarLinhas(Linha* linhas, int numero_linhas);
bool eliminarLinha(Linha** linhas, int* numero_linhas);
// * Funcao Atualizar Linha (Ver Enunciado)
void adicionarParagemLinha(Linha* linha, Paragem* paragem);
bool removerParagemLinha(Linha* linha, char* nomeParagem);
void atualizar(Paragem* paragens, Linha* linhas, int numero_linhas, int numero_paragens);

// * Paragens
Paragem procurarParagemEspecifica(Paragem* paragens, int numero_paragens, char NomeParagem[TAMANHO_MAX]);
void registarParagem(Paragem** paragens, int* numero_paragens);
void visualizarParagens(Paragem* paragens, int numero_paragens);
bool eliminarParagem(Paragem** paragens, int* numero_paragens);

#endif 