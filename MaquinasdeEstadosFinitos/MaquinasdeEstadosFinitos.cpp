// MaquinasdeEstadosFinitos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include<string>
#include <conio.h>

enum Estados {
    S_O,
    S_I,
    S_II,
    S_III
};

enum Estados estado = S_O;

int lengthOfArray(const char* arr)
{
    int size = 0;

    while (*arr) {
        size += 1;
        arr += 1;
    }

    return size;
}

int main()
{
    FILE* arq1;
    FILE* arq2;
    FILE* arq3;
    char Linha[100];
    char* result;
    int i;

    arq1 = fopen("teste.txt", "rt");
    FILE arr[] = { arq1 };

    if (arq1 == NULL) {
        std::cout << "Problemas na abertura do arquivo" << '\n';
        return 0;
    }

    i = 1;
    if (arq1) {
        while (!feof(arq1))
        {
            result = fgets(Linha, 100, arq1);
            // Se foi possível ler
            if (result) {
                //TODO HERE:
                long lenResult = lengthOfArray(result);
                for (int j = 0; j < (lenResult - 1); j++){
                    switch (estado)
                    {
                    case S_O:
                        if (result[j] == 'a')
                        {
                            estado = S_I;
                        }
                        break;

                    case S_I:
                        if (result[j] == 'b')
                        {
                            estado = S_II;
                        }
                        else
                        {
                            estado = S_III;
                        }
                        break;

                    case S_II:
                        if (result[j] == 'b')
                        {
                            estado = S_O;
                        }
                        else
                        {
                            estado = S_III;
                        }
                        break;

                    default:
                        estado = S_III;
                        break;
                    }
                }

                if (estado == S_O)
                {
                    std::cout << "|PERTENCE| " << "Input: " << Linha;
                }
                else
                {
                    std::cout << "|NAO PERTENCE| " << "Input: " << Linha;
                }

            }
        }
        fclose(arq1);
        return 0;
        
    }
    return 0;
}