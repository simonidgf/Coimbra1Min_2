#include "struct.h"

void calcularPercursos(Paragem *paragens, int numParagens, Linha *linhas, int numLinhas) {
    char partida[50];
    char chegada[50];
    
    // Solicitar os nomes das paragens de partida e chegada ao utilizador
    printf("Introduza o nome da paragem de partida: ");
    fgets(partida, sizeof(partida), stdin);
    partida[strcspn(partida, "\n")] = '\0'; // Remover o caractere '\n' do final
    
    printf("Introduza o nome da paragem de chegada: ");
    fgets(chegada, sizeof(chegada), stdin);
    chegada[strcspn(chegada, "\n")] = '\0'; // Remover o caractere '\n' do final
    
    // Implemente a lógica para calcular e mostrar os percursos
    // com uma única linha ou com mudança de linha
    
    // Exemplo:
    printf("Percurso:\n");
    printf("Linha 1: Paragem A -> Paragem B\n");
    printf("Linha 2: Paragem B -> Paragem C\n");
}

void guardarInformacao(Paragem *paragens, int numParagens, Linha *linhas, int numLinhas) {
    FILE *arquivo;
    
    // Abrir o arquivo em modo de escrita binária
    arquivo = fopen("informacao.bin", "wb");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    
    // Escrever o número de paragens no arquivo
    fwrite(&numParagens, sizeof(int), 1, arquivo);
    
    // Escrever as paragens no arquivo
    fwrite(paragens, sizeof(Paragem), numParagens, arquivo);
    
    // Escrever o número de linhas no arquivo
    fwrite(&numLinhas, sizeof(int), 1, arquivo);
    
    // Escrever as linhas no arquivo
    fwrite(linhas, sizeof(Linha), numLinhas, arquivo);
    
    // Fechar o arquivo
    fclose(arquivo);
    
    printf("Informação guardada com sucesso.\n");
}

void carregarInformacao(Paragem **paragens, int *numParagens, Linha **linhas, int *numLinhas) {
    FILE *arquivo;
    
    // Abrir o arquivo em modo de leitura binária
    arquivo = fopen("informacao.bin", "rb");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    
    // Ler o número de paragens do arquivo
    fread(numParagens, sizeof(int), 1, arquivo);
    
    // Alocar memória para as paragens
    *paragens = (Paragem *)malloc(sizeof(Paragem) * (*numParagens));
    
    // Ler as paragens do arquivo
    fread(*paragens, sizeof(Paragem), *numParagens, arquivo);
    
    // Ler o número de linhas do arquivo
    fread(numLinhas, sizeof(int), 1, arquivo);
    
    // Alocar memória para as linhas
    *linhas = (Linha *)malloc(sizeof(Linha) * (*numLinhas));
    
    // Ler as linhas do arquivo
    fread(*linhas, sizeof(Linha), *numLinhas, arquivo);
    
    // Fechar o arquivo
    fclose(arquivo);
    
    printf("Informação carregada com sucesso.\n");
}
