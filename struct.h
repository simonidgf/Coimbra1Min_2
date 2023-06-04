#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct linha {
    int Numero_Linha;
    struct linha *anterior;
    struct linha *seguinte;
    int n_total_paragens;
} Linha;

typedef struct paragem {
    char Nome[50];
    char Codigo[6];
    int n_Linhas;
    int n_total_paragens;
   struct linha *linha;
} Paragem;


void adicionarParagem(Paragem **paragens, int *numero_paragens);
bool visualizarParagens(Paragem *paragens, int num_paragens);
bool eliminarParagem(Paragem **paragens, int *num_paragens);
Paragem procurarParagem(Paragem **paragens, int *num_paragens);

/* Funções para manipulação das paragens
void registarParagem(Paragem **paragens, int *numParagens);
void eliminarParagem(Paragem **paragens, int *numParagens);
void visualizarParagens(Paragem *paragens, int numParagens);

// Funções para manipulação das linhas
void adicionarLinha(Linha **linhas, int *numLinhas, Paragem *paragens, int numParagens);
void atualizarLinha(Linha *linhas, int numLinhas);
void visualizarLinhas(Linha *linhas, int numLinhas);

// Funções para cálculo de percursos
void calcularPercursos(Paragem *paragens, int numParagens, Linha *linhas, int numLinhas);

// Função para armazenamento em arquivo
void guardarInformacao(Paragem *paragens, int numParagens, Linha *linhas, int numLinhas);
void carregarInformacao(Paragem **paragens, int *numParagens, Linha **linhas, int *numLinhas);
*/
#endif
