#include "struct.h"
#include "struct_functions_linhas.c"
#include "struct_functions_paragens.c"
#include "struct_management_functions.c"



void menuParagens();
void menuLinhas();
int menu();

int main()
{
    menu();
    return 0;
}

int menu()
{
    Paragem *paragens = malloc(sizeof(Paragem));
    Linha *linhas = malloc(sizeof(Linha));
    char op = '\0'; 
    bool noOp = true;

    do {
        printf("\n\nCoimbra1Min (Metro Mondego)\n\nParagens (P/p)\nSair (0)\n>");
        scanf(" %c", &op);
        op = toupper(op);

        switch (op)
        {
        case '0':
            printf("\n\nAté já :)\n");
            return 0;
            break;

        case 'P':
            menuParagens(paragens, linhas);
            break;

        default:
            break;
        }

        noOp = (op != '0') && (op != 'P');
    } while (noOp);

    return 0;
}

void menuParagens(Paragem *paragens, Linha *linhas) {

    int numParagens = 0;
    char op = '\0';
    bool noOp = true;

    do {
        printf("Paragens...\n\nAdicionar Paragem (A/a)\nEliminar Paragem (E/e)\nVisualizar Paragem (V/v)\nProcurar Paragem (P/p)\nLINHAS (L/l)\nVoltar (0)\n>");
        scanf(" %c", &op);
        op = toupper(op);

        switch (op) {
            case 'L':
                menuLinhas(paragens, linhas);
                break;

            case 'A':
                if (AdicionarParagem(&paragens, numParagens)) {
                    printf("Adicionado com sucesso.\n");
                    numParagens++;
                } else {
                    printf("Falha ao adicionar paragem.\n");
                }
                break;

            case 'E':
                printf("Eliminar paragem...\n");
                break;

            case 'P':
                printf("Procurar paragem...\n");
                break;

            case 'V':
                VisualizarParagens(paragens, numParagens);
                break;

            case '0':
                system("cls");
                menu();

            default:
                break;
        }
        menuParagens(paragens, linhas);

        noOp = (op != 'A') && (op != 'E') && (op != 'P') && (op != 'L') && (op != '0') && (op != 'V');
    } while (noOp);
}


void menuLinhas(Paragem *paragens, Linha *linhas)
{
    char op = '\0'; 
    bool noOp = true;

    do
    {
        system("cls");
        printf("Linhas...\n\nAdicionar Linha (A/a)\nAtualizar Linha (R/r)\nVizualizar Linhas (V/v)\nVoltar Menu (M/m)\nVoltar (0)\n>");
        scanf(" %c", &op);
        op = toupper(op);

        switch (op)
        {
        case 'R':
            printf("Linhas...");
            break;
        
        case 'A':
            printf("Linhas..A");
            break;

        case 'V':
            printf("Linhas...");
            break;

        case 'M':
            menu();
            break;

        case '0':
            system("cls");
            menuParagens(paragens, linhas);
            break;

        default:
            break;
        }

        noOp = (op != 'A') && (op != 'R') && (op != 'V') && (op != 'M') && (op != '0'); 
    } while (noOp);
}