#include <iostream>
#include <limits>
#include "genetico.h"

void imprime_resultado(bool passou) {
	if (passou) {
		std::cout << "\033[1;32mOK\033[0m\n"; // imprime OK verde na tela
	} else {
		std::cout << "\033[1;31mX\033[0m\n"; // imprime X vermelho na tela
	}
}

int main() {
	// OBSERVACAO: eu ja tenho certa experiencia em programacao entao
	// eu tentei deixar meu codigo um pouco mais avancado, porque
	// tenho costume de escrever assim. Espero que nao seja um problema.
	//
	// OBSERVACAO 2: meu teclado e americano, entao eu nao tenho acentos.
	const int tamanho_entradas = 6;

	std::uint16_t entradas[tamanho_entradas];

	std::cout << "Bem vindo a mochila. Para comecar, digite 6 valores para serem usados como mochila\n";
	std::cout << "Os valores precisam ser entre 0 e 65535. CUIDADO: Caso digitado numeros negativos, eles serao convertidos para positivos.\n\n";

	for (int i = 0; i < tamanho_entradas; i++) {
		std::cout << "Digite o valor " << i << ": ";
		std::cin >> entradas[i];
		// Caso o cin nao consiga atribuir o valor digitado pelo
		// usuario dentro da variavel (normalmente por overflow
		// ou por que o usurio digitou letras), cin.fail() vai
		// retornar true.
		while (std::cin.fail()) {
			// Limpa o estado do cin para que ele nao tenha 
			// comportamento inesperado.
			std::cin.clear();
			// Ignora valores acima do tamanho maximo do uint16_t
			// apos \n, ou seja, apos o usuario apertar enter.
			std::cin.ignore(std::numeric_limits<std::uint16_t>::max(), '\n');

			std::cout << "O valor inserido deve ser um numero natural maior ou igual a 0 e menor ou igual a 65535\nDigite um valor valido: ";
			std::cin >> entradas[i];
		}
	}

	std::cout << "\nResultado da Avaliacao\n";
	std::cout << "-----------------------\n";

	for (int i = 0; i < tamanho_entradas; i++) {
		bool passou = avaliar_mochila(entradas[i]);
		imprime_resultado(passou);
	}

	std::cout << "-----------------------\n";

	// Resultado das modificacoess sugeridas
	
	std::uint16_t cruzamento_ponto_unico = cruzar_ponto_unico(entradas[0], entradas[1]);
	bool resultado_cruzamento_ponto_unico = avaliar_mochila(cruzamento_ponto_unico);
	imprime_resultado(resultado_cruzamento_ponto_unico);

	std::uint16_t cruzamento_aritmetico = cruzar_aritmeticamente(entradas[2], entradas[3]);
	bool resultado_cruzamento_aritmetico = avaliar_mochila(cruzamento_aritmetico);
	imprime_resultado(resultado_cruzamento_aritmetico);

	std::uint16_t mutacao = mutar(entradas[4]);
	bool resultado_mutacao = avaliar_mochila(mutacao);
	imprime_resultado(resultado_mutacao);

	std::uint16_t mutacao_dupla = mutar_duplamente(entradas[5]);
	bool resultado_mutacao_dupla(avaliar_mochila(mutacao_dupla));
	imprime_resultado(resultado_mutacao_dupla);
}
