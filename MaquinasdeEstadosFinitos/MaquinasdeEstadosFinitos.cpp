//Estudante : Pedro Bianchini de Quadros
/*
	ENUNCIADO:
	Para  obter  os  pontos  relativos  a  este  trabalho,  você  deverá  criar  um  programa,  utilizando  a
linguagem  Python, C, ou C++.  Este  programa,  quando  executado,  irá  determinar  se  uma  string de
entrada  faz  parte  da  linguagem  𝐿    definida  por  𝐿 = {𝑥 | 𝑥 ∈
{𝑎,𝑏}∗ 𝑒 𝑐𝑎𝑑𝑎 𝑎 𝑒𝑚 𝑥 é 𝑠𝑒𝑔𝑢𝑖𝑑𝑜 𝑝𝑜𝑟 𝑝𝑒𝑙𝑜 𝑚𝑒𝑛𝑜𝑠 𝑑𝑜𝑖𝑠 𝑏} segundo o alfabeto  Σ={𝑎,𝑏,𝑐}.
	O  programa  que  você  desenvolverá  irá  receber  como  entrada um arquivo de texto  (.txt)
contendo várias strings. A primeira linha do arquivo indica quantas strings estão no arquivo de texto de
entrada. As linhas subsequentes contém uma string por linha.  A seguir está um exemplo das linhas que
podem existir em um arquivo de testes para o programa que você irá desenvolver:
	3 
	abbaba 
	abababb 
	bbabbaaab

	Neste  exemplo  temos  3  strings  de  entrada.  O  número  de  strings em  cada  arquivo  será
representado  por  um  número  inteiro  positivo.  A  resposta  do  seu  programa  deverá  conter  uma, e
somente uma linha de saída para cada string. Estas linhas conterão a string de entrada e o resultado
da validação conforme o formato indicado a seguir:
	A  saída  poderá  ser  enviada  para  um  arquivo  de  textos,  ou  para  o  terminal  padrão  e  será
composta de uma linha de saída por string de entrada. No caso do exemplo, teremos 3 linhas de saída.
Para que seu programa possa ser testado você deve criar, no mínimo, três arquivos de entrada
contendo um número diferente de strings diferentes. Os arquivos de entrada criados para os seus testes
devem estar disponíveis tanto no ambiente repl.it quanto no ambiente Github. Observe que o professor
irá  testar  seu  programa  com  os  arquivos  de  testes  que  você  criar  e  com,  no  mínimo  um  arquivo  de
testes criado pelo próprio professor.
*/

#include <iostream>

enum Estados {
	S_O,
	S_I,
	S_II,
	S_III,
	NUMBER
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
		estado = NUMBER;
		//Verefica qual arquivo vai ser aberto
		if (i == 0)
		{
			std::cout << "Arquivo arq1.txt" << '\n';
			arq = fopen("arq1.txt", "rt");
		}
		else if (i == 1) {
			std::cout << '\n' << '\n' << "Arquivo arq2.txt" << '\n';
			arq = fopen("arq2.txt", "rt");
		}
		else {
			std::cout << '\n' << '\n' << "Arquivo arq3.txt" << '\n';
			arq = fopen("arq3.txt", "rt");
		}


		if (arq == NULL) {
			std::cout << "Problemas na abertura do arquivo" << '\n';
			return 0;
		}

		//Irá percorrer todas as linhas do arquivo
		while (!feof(arq))
		{
			result = fgets(Linha, 100, arq);
			// Se foi possível ler
			if (result) {
				// Obtem o tamnho da linha para poder fazer o for
				long lenResult = lengthOfArray(Linha);
				for (int j = 0; j < (lenResult - 1); j++) {
					//Aplicação da lógica
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

					case NUMBER:
						std::cout << "|QUANTIDADE DE INPUTS| " << "N: " << Linha << '\n';
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
				else if ((estado == S_I) || (estado == S_II) || (estado == S_III))
				{
					std::cout << "|NAO PERTENCE| " << "Input: " << Linha;
				}

				estado = S_O;

			}
		}
		fclose(arq);

		i++;
	}

	return 0;
}