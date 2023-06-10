#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define TAMANHO_MAX 50
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
   int numeros_linhas;
   Paragem *paragens;
} Linha;

void adicionarLinhas(Linha** linhas, int* numero_linhas);
void visualizarLinhas(Linha* linhas, int numero_linhas);
bool eliminarLinha(Linha** linhas, int* numero_linhas);
Linha procuraLinhaExpecifica(Linha** linhas, int* numero_linhas);


#endif 