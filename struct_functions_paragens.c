#include "struct.h" 

void registarParagem(Paragem **paragens, int *numParagens) {
    // Alocar espaço para uma nova paragem
    Paragem *novaParagem = (Paragem *)malloc(sizeof(Paragem));
    
    // Solicitar o nome da paragem ao utilizador
    printf("Introduza o nome da paragem: ");
    fgets(novaParagem->nome, sizeof(novaParagem->nome), stdin);
    novaParagem->nome[strcspn(novaParagem->nome, "\n")] = '\0'; // Remover o caractere '\n' do final
    
    // Gerar o código alfanumérico único (neste exemplo, utiliza-se um contador)
    sprintf(novaParagem->codigo, "%04d", *numParagens + 1);
    
    // Incrementar o contador de paragens
    (*numParagens)++;
    
    // Realocar o array de paragens para acomodar a nova paragem
    *paragens = (Paragem *)realloc(*paragens, (*numParagens) * sizeof(Paragem));
    
    // Adicionar a nova paragem ao final do array
    (*paragens)[*numParagens - 1] = *novaParagem;
    
    printf("Paragem registada com sucesso.\n");
    free(novaParagem);
}

void eliminarParagem(Paragem **paragens, int *numParagens) {
    char codigo[5];
    
    // Solicitar o código da paragem a ser removida
    printf("Introduza o código da paragem a eliminar: ");
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0'; // Remover o caractere '\n' do final
    
    // Verificar se a paragem existe
    int i;
    int encontrada = 0;
    for (i = 0; i < *numParagens; i++) {
        if (strcmp((*paragens)[i].codigo, codigo) == 0) {
            encontrada = 1;
            break;
        }
    }
    
    // Remover a paragem se for encontrada
    if (encontrada) {
        // Verificar se a paragem faz parte de alguma linha
        // (implemente a verificação correspondente)
        
        // Remover a paragem do array
        for (; i < (*numParagens) - 1; i++) {
            (*paragens)[i] = (*paragens)[i + 1];
        }
        
        // Redimensionar o array de paragens
        *paragens = (Paragem *)realloc(*paragens, (*numParagens - 1) * sizeof(Paragem));
        
        (*numParagens)--;
        printf("Paragem removida com sucesso.\n");
    } else {
        printf("Paragem não encontrada.\n");
    }
}

void visualizarParagens(Paragem **paragens, int numParagens) {
    printf("Lista de Paragens:\n");
    for (int i = 0; i < numParagens; i++) {
        printf("Código: %s\tNome: %s\n", (*paragens)[i].codigo, (*paragens)[i].nome);
    }
}
