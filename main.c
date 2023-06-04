#include "struct.h"
#include "struct_functions.c"

int menu(Paragem *array_paragens, int num_paragens)
{
    char op = '\0'; 
    bool noOp = true;

    do {
        printf("\n\nCoimbra1Min (Metro Mondego)\n\nAdicionar Paragem (A/a)\nProcurar Paragem (P/p)\nEliminar Paragem (E/e)\nVisualizar Paragens (V/v)\nSair (0)\n>");
        scanf(" %c", &op);
        op = toupper(op);

        switch (op)
        {
        case '0':
            printf("\n\nAté já :)\n");
            return 0;
            break;

        case 'A':
            adicionarParagem(&array_paragens, &num_paragens);
            menu(array_paragens, num_paragens);
            break;

        case 'P':
            Paragem paragem_procurada = procurarParagem(&array_paragens, &num_paragens);
            menu(array_paragens, num_paragens);
            break;

        case 'E':
            eliminarParagem(&array_paragens, &num_paragens);
            menu(array_paragens, num_paragens);
            break;

        case 'V':
            visualizarParagens(array_paragens, num_paragens);
            menu(array_paragens, num_paragens);
            break;

        default:
            break;
        }

        noOp = (op != '0') && (op != 'P');
    } while (noOp);

    return 0;
}

int main()
{
    Paragem *p = NULL;
    int numero_paragens = 0;

    menu(p, numero_paragens);

    free(p);

    return 0;
}

