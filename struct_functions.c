#include "struct.h" 

void adicionarParagem(Paragem **paragens, int *numero_paragens)
{
    Paragem *nova = malloc(sizeof(Paragem));

    printf("Nome: ");
    scanf("%s", nova->Nome);

    srand(time(NULL)); 
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 

    nova->Codigo[0] = '#';
    for (int i = 1; i < 5; i++) {
        nova->Codigo[i] = charset[rand() % (sizeof(charset) - 1)]; 
    }
    nova->Codigo[5] = '\0';

    nova->n_Linhas = 0;
    (*numero_paragens)++;
    nova->n_total_paragens = (*numero_paragens);
    nova->linha = NULL;

    *paragens = realloc(*paragens, (*numero_paragens) * sizeof(Paragem));

    // Add the new Paragem object to the end of the array
    (*paragens)[(*numero_paragens) - 1] = *nova;
}

bool visualizarParagens(Paragem *paragens, int num_paragens) {
    int i;

    if (num_paragens == 0)
    {
        printf("Nao existem paragens...\n\n");
        return false;
    }

    for (i = 0; i < num_paragens; i++) {
        printf("\nParagem %d\n", i + 1);
        printf("Nome: %s\n", paragens[i].Nome);
        printf("Codigo: %s\n", paragens[i].Codigo);
        printf("Numero de Linhas: %d\n", paragens[i].n_Linhas);
        putchar('\n');
    }

    if (i == 0) return false;
    else return true;
}

bool eliminarParagem(Paragem **paragens, int *num_paragens)
{
    char paragem_eliminada[50];
    printf("\nParagem que pretende eliminar: ");
    scanf("%s", paragem_eliminada);

    for (int i = 0; i < *num_paragens; i++)
    {
        if (strcmp((*paragens)[i].Nome, paragem_eliminada) == 0) {
            // Shift elements to overwrite the deleted paragem
            for (int j = i; j < *num_paragens - 1; j++) {
                memcpy(&(*paragens)[j], &(*paragens)[j + 1], sizeof(Paragem));
            }
            (*num_paragens)--;
            *paragens = realloc(*paragens, (*num_paragens) * sizeof(Paragem));
            return true;
        }
    }
    return false;
} 

Paragem procurarParagem(Paragem **paragens, int *num_paragens)
{
    char paragem_pretendida[50];
    printf("\nQue paragem procura: ");
    scanf("%s", paragem_pretendida);

    for (int i = 0; i < *num_paragens; i++)
    {
        if (strcmp((*paragens)[i].Nome, paragem_pretendida) == 0) {
            printf("Paragem Encontrada com sucesso...");
            return (*paragens)[i];
        }
    }

    printf("Nao foi possivel encontrar a sua paragem...");
    Paragem empty_paragem;
    strcpy(empty_paragem.Nome, "");
    strcpy(empty_paragem.Codigo, "");
    empty_paragem.n_Linhas = 0;
    empty_paragem.n_total_paragens = 0;
    empty_paragem.linha = NULL;
    return empty_paragem;
}




