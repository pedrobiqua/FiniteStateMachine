// MaquinasdeEstadosFinitos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <conio.h>

int main()
{
    FILE* arq;
    char Linha[100];
    char* result;
    int i;

    arq = fopen("teste.txt", "rt");

    if (arq == NULL) {
        std::cout << "Problemas na abertura do arquivo" << '\n';
        return 0;
    }

    i = 1;
    if (arq) {
        while (!feof(arq))
        {
            // Lê uma linha (inclusive com o '\n')
            result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
            std::cout << result << '\n';
            // Se foi possível ler
            if (result) {
                //printf("Linha %d : %s", i, Linha);
                std::cout << "Linha" << i << ":" << Linha << '\n';
            }

            i++;
        }
        fclose(arq);
        return 1;
        
    }
    return 1;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
