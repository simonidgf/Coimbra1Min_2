#include "struct.h" 


// * Funcao para Adicionar *
bool AdicionarParagem(Paragem **paragens, int num_paragens) {
    Paragem *novaParagem = malloc(sizeof(Paragem));
    if (novaParagem == NULL) {
        return false;
    }

    // * Nome
    printf("Nome da Paragem: ");
    scanf("%s", novaParagem->nome);

    // * Codigo
    srand(time(NULL)); 
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 

    novaParagem->codigo[0] = '#';
    for (int i = 1; i < 5; i++) {
        novaParagem->codigo[i] = charset[rand() % (sizeof(charset) - 1)]; 
    }
    novaParagem->codigo[5] = '\0'; 

    novaParagem->numLinhas = 0;
    novaParagem->linhas = NULL;

    num_paragens++;
    novaParagem->numParagens = num_paragens;

    Paragem **temp = realloc(*paragens, sizeof(Paragem *) * num_paragens);
    if (temp == NULL) {
        free(novaParagem);
        return false;
    }
    *paragens = (Paragem *)temp;
    (*paragens)[num_paragens - 1] = *(novaParagem);

    return true;
}


bool VisualizarParagens(Paragem *paragens, int num_paragens) {
    int i;

    if (num_paragens == 0)
    {
        printf("Nao existem paragens...\n\n");
        return false;
    }
    
    for (i = 0; i < num_paragens; i++) {
        printf("Paragem %d\n", i + 1);
        printf("Nome: %s\n", paragens[i].nome);
        printf("Codigo: %s\n", paragens[i].codigo);
        printf("Numero de Linhas: %d\n", paragens[i].numLinhas);

        // Display the associated train lines
        for (int j = 0; j < paragens[i].numLinhas; j++) {
            printf("Linha %d: %s\n", j + 1, paragens[i].linhas[j].numero);
        }

        putchar('\n');
    }

    if (i == 0) return false;
    else return true;
}




