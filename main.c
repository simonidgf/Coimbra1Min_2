#include "libs.h"

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
    char op = '\0'; 
    bool noOp = true;

    do {
        system("clear");
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
            menuParagens();
            break;

        default:
            break;
        }

        noOp = (op != '0') && (op != 'P');
    } while (noOp);

    return 0;
}

void menuParagens()
{
    char op = '\0'; 
    bool noOp = true;

    do
    {
        system("clear");
        printf("Paragens...\n\nAdicionar Paragem (A/a)\nEliminar Paragem (E/e)\nProcurar Paragem (P/p)\nLINHAS (L/l)\nVoltar (0)\n>");
        scanf(" %c", &op);
        op = toupper(op);

        switch (op)
        {
        case 'L':
            printf("Linhas...");
            break;
        
        case 'A':
            printf("Linhas..A");
            break;

        case 'E':
            printf("Linhas...");
            break;

        case 'P':
            printf("Linhas...");
            break;

        case '0':
            system("clear");
            menu();
            break;

        default:
            break;
        }

        noOp = (op != '1') && (op != 'A') && (op != 'E') && (op != 'P') && (op != 'L') && (op != '0'); 
    } while (noOp);
}

void menuLinhas()
{
    char op = '\0'; 
    bool noOp = true;

    do
    {
        system("clear");
        printf("Linhas...\n\nAdicionar Linha (A/a)\nAtualizar Linha (R/r)\nVizualizar Linhas (V/v)\nVoltar Menu (M/m)\nVoltar (0)\n>");
        scanf(" %c", &op);
        op = toupper(op);

        switch (op)
        {
        case 'L':
            printf("Linhas...");
            break;
        
        case 'A':
            printf("Linhas..A");
            break;

        case 'E':
            printf("Linhas...");
            break;

        case 'P':
            printf("Linhas...");
            break;

        case '1':
            printf("Linhas...");
            break;

        case '0':
            system("clear");
            menu();
            break;

        default:
            break;
        }

        noOp = (op != '1') && (op != 'A') && (op != 'E') && (op != 'P') && (op != 'L') && (op != '0'); 
    } while (noOp);
}