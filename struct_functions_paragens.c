#include "struct.h" 

void registarParagem(Paragem **paragens, int *numParagens) {
    // Alocar espaço para uma nova paragem
    Paragem *novaParagem = (Paragem *)malloc(sizeof(Paragem));

    // Solicitar o nome da paragem ao utilizador
    printf("Introduza o nome da paragem: ");
    scanf("%s", novaParagem->nome);
    novaParagem->nome[strcspn(novaParagem->nome, "\n")] = '\0'; // Remover o caractere '\n' do final

    // Gerar o código alfanumérico único
    srand(time(NULL));
    char str[6];
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    str[0] = '#';
    for (int i = 1; i < 5; i++) {
        str[i] = charset[rand() % sizeof(charset)];
    }

    str[5] = '\0';
    sprintf(novaParagem->codigo, "%s%d", str, *numParagens + 1);

    // De origem, a paragem é gerada sem linhas
    novaParagem->nLinhas = 0;

    // Realocar o array de paragens para acomodar a nova paragem
    *paragens = (Paragem *)realloc(*paragens, (*numParagens + 1) * sizeof(Paragem));

    // Adicionar a nova paragem ao final do array
    (*paragens)[*numParagens] = *novaParagem;

    // Incrementar o contador de paragens
    (*numParagens)++;

    printf("Paragem registada com sucesso.\n");
    free(novaParagem);
}


void eliminarParagem(Paragem **paragens, int *numParagens) {
    char codigo[5];
    
    // Solicitar o código da paragem a ser removida
    printf("Introduza o código da paragem a eliminar: ");
    scanf("%s", codigo);
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

void visualizarParagens(Paragem *paragens, int numParagens) {
    printf("Lista de Paragens:\n");

    for (int i = 0; i < numParagens; i++) {
        printf("Paragem %d:\n", i + 1);
        printf("Nome: %s\n", paragens[i].nome);
        printf("Código: %s\n", paragens[i].codigo);
        printf("Número de Linhas: %d\n", paragens[i].nLinhas);

        // Imprimir informações adicionais sobre as linhas, se necessário
        // ...

        printf("\n");
    }

    // Aguardar entrada do usuário antes de retornar ao menu
    printf("Pressione Enter para voltar ao menu...");
    getchar(); // Capturar o caractere de nova linha deixado pelo scanf anterior
    getchar(); // Aguardar a entrada do usuário (qualquer tecla)
}



