#include "struct.h" 

bool AdicionarParagem(Paragem **paragens, int *num_paragens) {
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

    novaParagem->nLinhas = 0;

    (*num_paragens)++;
    novaParagem->numParagens = *num_paragens;

    Paragem **temp = realloc(*paragens, sizeof(Paragem *) * (*num_paragens));
    if (temp == NULL) {
        free(novaParagem);
        return false;
    }
    *paragens = (Paragem *)temp;
    (*paragens)[(*num_paragens) - 1] = *(novaParagem);

    return true;
}

