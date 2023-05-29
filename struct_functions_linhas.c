#include "struct.h" 

void atualizarLinha(Linha *linhas, int numLinhas) {
    char nomeLinha[50];
    
    // Solicitar o nome da linha a ser atualizada
    printf("Introduza o nome da linha a ser atualizada: ");
    fgets(nomeLinha, sizeof(nomeLinha), stdin);
    nomeLinha[strcspn(nomeLinha, "\n")] = '\0'; // Remover o caractere '\n' do final
    
    // Verificar se a linha existe
    Linha *linhaAtual = linhas;
    int encontrada = 0;
    
    while (linhaAtual != NULL) {
        if (strcmp(linhaAtual->nome, nomeLinha) == 0) {
            encontrada = 1;
            break;
        }
        
        linhaAtual = linhaAtual->proxima;
    }
    
    // Atualizar a linha se for encontrada
    if (encontrada) {
        // Implemente a lógica para adicionar ou remover paragens da linha
        // (você pode solicitar ao utilizador as ações desejadas)
        
        printf("Linha atualizada com sucesso.\n");
    } else {
        printf("Linha não encontrada.\n");
    }
}

void visualizarLinhas(Linha *linhas, int numLinhas) {
    printf("Lista de Linhas:\n");
    
    Linha *linhaAtual = linhas;
    
    while (linhaAtual != NULL) {
        printf("Nome: %s\n", linhaAtual->nome);
        // Implemente a lógica para mostrar as paragens da linha
        
        linhaAtual = linhaAtual->proxima;
    }
}

void adicionarLinha(Linha **linhas, int *numLinhas, Paragem *paragens, int numParagens) {
    // Alocar espaço para uma nova linha
    Linha *novaLinha = (Linha *)malloc(sizeof(Linha));
    
    // Solicitar o nome da linha ao utilizador
    printf("Introduza o nome da linha: ");
    fgets(novaLinha->nome, sizeof(novaLinha->nome), stdin);
    novaLinha->nome[strcspn(novaLinha->nome, "\n")] = '\0'; // Remover o caractere '\n' do final
    
    // Implemente a lógica para adicionar as paragens à nova linha
    // (você pode solicitar ao utilizador as paragens da linha)
    
    // Atribuir o número de paragens à nova linha
    novaLinha->numParagens = numParagens;
    
    // Definir os ponteiros de próxima e anterior como NULL (pois é adicionada no final da lista)
    novaLinha->proxima = NULL;
    novaLinha->anterior = NULL;
    
    // Se a lista de linhas estiver vazia, a nova linha se torna a primeira
    if (*linhas == NULL) {
        *linhas = novaLinha;
    } else {
        // Percorrer a lista até encontrar a última linha
        Linha *ultimaLinha = *linhas;
        
        while (ultimaLinha->proxima != NULL) {
            ultimaLinha = ultimaLinha->proxima;
        }
        
        // Adicionar a nova linha no final da lista
        ultimaLinha->proxima = novaLinha;
        novaLinha->anterior = ultimaLinha;
    }
    
    printf("Linha adicionada com sucesso.\n");
}
