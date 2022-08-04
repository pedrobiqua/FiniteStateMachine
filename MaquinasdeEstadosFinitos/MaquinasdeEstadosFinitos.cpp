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
    FILE* arq;
    char Linha[100];
    char* result;
    int i;
    i = 0;

    while (i < 3)
    {
        estado = S_O;
        if (i == 0)
        {
            std::cout << "Arquivo arq1.txt" << '\n';
            arq = fopen("arq1.txt", "rt");
        } else if (i == 1) {
            std::cout << '\n' << "Arquivo arq2.txt" << '\n';
            arq = fopen("arq2.txt", "rt");
        } else {
            std::cout << '\n' << "Arquivo arq3.txt" << '\n';
            arq = fopen("arq3.txt", "rt");
        }
        

        if (arq == NULL) {
            std::cout << "Problemas na abertura do arquivo" << '\n';
            return 0;
        }

        if (arq) {
            while (!feof(arq))
            {
                result = fgets(Linha, 100, arq);
                // Se foi possível ler
                if (result) {
                    //TODO HERE:
                    long lenResult = lengthOfArray(Linha);
                    for (int j = 0; j < (lenResult - 1); j++) {
                        switch (estado)
                        {
                        case S_O:
                            if (Linha[j] == 'a')
                            {
                                estado = S_I;
                            }
                            break;

                        case S_I:
                            if (Linha[j] == 'b')
                            {
                                estado = S_II;
                            }
                            else
                            {
                                estado = S_III;
                            }
                            break;

                        case S_II:
                            if (Linha[j] == 'b')
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
                    estado = S_O;

                }
            }
            fclose(arq);

        }
        i++;
    }
    
    return 0;
}