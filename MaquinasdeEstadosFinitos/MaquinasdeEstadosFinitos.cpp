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

int lengthOfArray(const char* arr);
void printStringWithoutBreak(const char* arr);

enum Estados {
	S_O,
	S_I,
	S_II,
	S_III,
	NUMBER
};
enum Estados estado = S_O;

int main()
{
	FILE* arq;
	char Linha[100];
	char* result;
	int num_txt;
	int i;
	int counter;
	int numberLines;
	i = 0;

	//Quantidade de arquivos a serem análisados.
	//num_txt = 4;
	num_txt = 3;

	while (i < num_txt)
	{
		numberLines = -1;
		counter = 0;
		estado = NUMBER;
		/*
			Para adicionar um novo arquivo basta adicionar um novo else if
			E atualizar a variável (num_txt) para o número de arquivos textos atuais

			No envio da atividade já vão estar a disposição 3 arquivos de texto.
		*/

		//Verefica qual arquivo vai ser aberto
		if (i == 0)
		{
			arq = fopen("arq1.txt", "rt");
		}
		else if (i == 1)
		{
			arq = fopen("arq2.txt", "rt");
		}
		else if (i == 2)
		{
			arq = fopen("arq3.txt", "rt");
		}
		/* Exemplo de acréscimo de arquivo, para usar basta retirar o comentário e atualizar a variável num_txt para 4
		else if (i == 3)
		{
			arq = fopen("arq4.txt", "rt");
		}
		*/
		else
		{
			std::cout << "Arquivo nao existe" << '\n';
			return 0;
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
				// Obtem o tamnho da linha para poder fazer o for e analisar char por char
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
						// Se não for do alfabeto Σ={𝑎,𝑏,𝑐} , vai mostrar ao usuario que não pertence.
						else if ((Linha[j] != 'a') && (Linha[j] != 'b') && (Linha[j] != 'c')) 
						{
							estado = S_III;
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
						numberLines = std::strtol (result, NULL, 10);
						break;

					default:
						estado = S_III;
						break;
					}
				}

				//Verefica se faz parte da linguagem 𝐿 = {𝑥 | 𝑥 ∈ {𝑎, 𝑏}∗ 𝑒 𝑐𝑎𝑑𝑎 𝑎 𝑒𝑚 𝑥 é 𝑠𝑒𝑔𝑢𝑖𝑑𝑜 𝑝𝑜𝑟 𝑝𝑒𝑙𝑜 𝑚𝑒𝑛𝑜𝑠 𝑑𝑜𝑖𝑠 𝑏 }
				if (estado == S_O)
				{
					printStringWithoutBreak(Linha);
					std::cout << ": pertence" << '\n';
					
				}
				else if ((estado == S_I) || (estado == S_II) || (estado == S_III))
				{
					printStringWithoutBreak(Linha);
					std::cout << ": nao pertence" << '\n';

				}
				estado = S_O;
				if (counter >= numberLines)
				{
					break;
				}
			}
			counter++;
		}
		fclose(arq);
		i++;
	}
	return 0;
}

int lengthOfArray(const char* arr)
{
	int size = 0;

	while (*arr) {
		size += 1;
		arr += 1;
	}

	return size;
}

void printStringWithoutBreak(const char* arr)
{
	for (size_t i = 0; i < lengthOfArray(arr); i++)
	{
		if (arr[i] != '\n')
		{
			std::cout << arr[i];
		}
	}
}