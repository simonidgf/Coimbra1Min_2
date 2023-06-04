#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define CODE_LENGTH 5
#define MAX_LENGTH 100

// Definição da estrutura Linha
typedef struct linha {
    int numero;
    int numParagens;
    struct linha *proxima;
    struct linha *anterior;
} Linha;

typedef struct paragem{
    char nome[50];
    char codigo[6];
    int numLinhas;
    int numParagens;
    Linha *linhas;
} Paragem;


bool AdicionarParagem(Paragem **paragens, int num_paragens);
bool VisualizarParagens(Paragem *paragens, int num_paragens);

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
