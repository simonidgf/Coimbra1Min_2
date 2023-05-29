#include "libs.h"
#ifndef STRUCT_H
#define STRUCT_H

// Definição da estrutura Paragem (Parada)
typedef struct paragem{
    char codigo[CODE_LENGTH];
    char nome[MAX_LENGTH];
} Paragem;

// Definição da estrutura Linha
typedef struct linha {
    char nome[MAX_LENGTH];
    struct linha *proxima;
    struct linha *anterior;
    Paragem *paragens;
    int numParagens;
} Linha;

// Funções para manipulação das paragens
void registarParagem(Paragem **paragens, int *numParagens);
void eliminarParagem(Paragem **paragens, int *numParagens);
void visualizarParagens(Paragem **paragens, int numParagens);

// Funções para manipulação das linhas
void adicionarLinha(Linha **linhas, int *numLinhas, Paragem *paragens, int numParagens);
void atualizarLinha(Linha *linhas, int numLinhas);
void visualizarLinhas(Linha *linhas, int numLinhas);

// Funções para cálculo de percursos
void calcularPercursos(Paragem *paragens, int numParagens, Linha *linhas, int numLinhas);

// Função para armazenamento em arquivo
void guardarInformacao(Paragem *paragens, int numParagens, Linha *linhas, int numLinhas);
void carregarInformacao(Paragem **paragens, int *numParagens, Linha **linhas, int *numLinhas);

#endif
