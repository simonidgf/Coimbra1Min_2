#include "struct.h"

void guardarDados(Linha* linhas, int numero_linhas, Paragem* paragens, int numero_paragens, const char* nome_arquivo)
{
    FILE* arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Escrever o número de linhas e paragens no arquivo
    fwrite(&numero_linhas, sizeof(int), 1, arquivo);
    fwrite(&numero_paragens, sizeof(int), 1, arquivo);

    // Escrever as linhas no arquivo
    for (int i = 0; i < numero_linhas; i++) {
        Linha linha = linhas[i];
        fwrite(&linha.numero_paragens, sizeof(int), 1, arquivo);
        fwrite(linha.Nome, sizeof(char), TAMANHO_MAX, arquivo);

        // Verificar se a linha tem paragens associadas
        if (linha.numero_paragens > 0 && linha.paragens != NULL) {
            // Escrever as paragens da linha no arquivo
            for (int j = 0; j < linha.numero_paragens; j++) {
                Paragem paragem = linha.paragens[j];
                fwrite(&paragem.numero_paragens, sizeof(int), 1, arquivo);
                fwrite(&paragem.numeros_linhas, sizeof(int), 1, arquivo);
                fwrite(paragem.Nome, sizeof(char), TAMANHO_MAX, arquivo);
                fwrite(paragem.Codigo, sizeof(char), TAMANHO_COD, arquivo);
            }
        }
    }

    // Escrever as paragens não associadas a uma linha no arquivo
    for (int i = 0; i < numero_paragens; i++) {
        Paragem paragem = paragens[i];

        // Verificar se a paragem não está associada a nenhuma linha
        if (paragem.numeros_linhas == 0) {
            fwrite(&paragem.numero_paragens, sizeof(int), 1, arquivo);
            fwrite(&paragem.numeros_linhas, sizeof(int), 1, arquivo);
            fwrite(paragem.Nome, sizeof(char), TAMANHO_MAX, arquivo);
            fwrite(paragem.Codigo, sizeof(char), TAMANHO_COD, arquivo);
        }
    }

    fclose(arquivo);
}


void carregarDados(Linha** linhas, int* numero_linhas, Paragem** paragens, int* numero_paragens, const char* nome_arquivo)
{
    FILE* arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    // Ler o número de linhas e paragens do arquivo
    fread(numero_linhas, sizeof(int), 1, arquivo);
    fread(numero_paragens, sizeof(int), 1, arquivo);

    // Alocar memória para as linhas e paragens
    *linhas = (Linha*)malloc((*numero_linhas) * sizeof(Linha));
    *paragens = (Paragem*)malloc((*numero_paragens) * sizeof(Paragem));

    // Ler as linhas do arquivo
    for (int i = 0; i < *numero_linhas; i++) {
        Linha linha;
        fread(&linha.numero_paragens, sizeof(int), 1, arquivo);
        fread(linha.Nome, sizeof(char), TAMANHO_MAX, arquivo);

        // Verificar se a linha tem paragens associadas
        if (linha.numero_paragens > 0) {
            linha.paragens = (Paragem*)malloc(linha.numero_paragens * sizeof(Paragem));

            // Ler as paragens da linha
            for (int j = 0; j < linha.numero_paragens; j++) {
                Paragem paragem;
                fread(&paragem.numero_paragens, sizeof(int), 1, arquivo);
                fread(&paragem.numeros_linhas, sizeof(int), 1, arquivo);
                fread(paragem.Nome, sizeof(char), TAMANHO_MAX, arquivo);
                fread(paragem.Codigo, sizeof(char), TAMANHO_COD, arquivo);

                linha.paragens[j] = paragem;
            }
        } else {
            linha.paragens = NULL;
        }

        (*linhas)[i] = linha;
    }

    // Ler as paragens não associadas a uma linha
    for (int i = 0; i < *numero_paragens; i++) {
        Paragem paragem;
        fread(&paragem.numero_paragens, sizeof(int), 1, arquivo);
        fread(&paragem.numeros_linhas, sizeof(int), 1, arquivo);
        fread(paragem.Nome, sizeof(char), TAMANHO_MAX, arquivo);
        fread(paragem.Codigo, sizeof(char), TAMANHO_COD, arquivo);

        (*paragens)[i] = paragem;
    }

    fclose(arquivo);

}



