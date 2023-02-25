#include "genetico.h"
#include "binario.h"
#include <cstdint>
#include <iomanip>
#include <iostream>

// estou usando define pois nao sabia se eu poderia usuar
// constantes globais.
#define tamanho_mochila 16

typedef struct {
	std::uint16_t pesos[tamanho_mochila];
	std::uint16_t precos[tamanho_mochila];
	int peso_limite;
} mochila;

// Este e o limite que uma mascara de tamanho 1 pode dar bitshift para a esquerda
int limite_bitshift_esquerda() {
	return 15;
}

// Avalia a mochila baseado na entrada do usuario.
// A entrada do usuario sera interpretada como binario e feita
// operacoes com os bits. O indice dos bits da entrada corresponde
// ao indice dos pesos e dos valores.
// Retorna true se o peso esta dentro do limite e falso do contrario
bool avaliar_mochila(std::uint16_t entrada) {
	int peso_total = 0;
	int preco_total = 0;

	const mochila mochila = {
		{ 12, 3, 5, 4, 9, 1, 2, 3, 4, 1, 2, 4, 5, 2, 4, 1 },
		{ 4, 4, 8, 10, 15, 3, 1, 1, 2, 10, 20, 15, 10, 3, 4, 12 },
		20,
	};

	for (int i = 0; i < tamanho_mochila; i++) {
		int mascara = 1 << (limite_bitshift_esquerda() - i);
		if ((entrada & mascara) == mascara) {
			peso_total += mochila.pesos[i];
			preco_total += mochila.precos[i];
		}
	}

	std::cout << std::right << std::setw(5) << entrada << " - ";
	std::cout << "$" << std::left << std::setw(2) << preco_total << " - ";
	std::cout << std::right << std::setw(2) << peso_total << "Kg" << " - ";
	
	return peso_total <= mochila.peso_limite;
}

// Faz mutacao de um bit especifico do valor passado
std::uint16_t mutar(std::uint16_t valor) {
	int indice_bit = 9; // para modificar especificamente o item G da mochila
	return alternar_bit(valor, indice_bit);
};

// Faz mutacao de dois bits especificos do valor passado
std::uint16_t mutar_duplamente(std::uint16_t valor) {
	int indice_bit1 = 3;
	int indice_bit2 = 12;

	std::uint16_t valor_mutado = alternar_bit(valor, indice_bit1); 
	valor_mutado = alternar_bit(valor_mutado, indice_bit2);
	
	return valor_mutado;
}

// Concatena os bits altos do valor 1 com os bits baixos do valor 2 e forma um novo numero
std::uint16_t cruzar_ponto_unico(std::uint16_t valor1, std::uint16_t valor2) {
	// Quando feita operacao AND nos valores com as mascaras, os novos
	// valores serao iguais a suas respectivas metades, dependendo da mascara.
	// A mascara maior mantem os bits de cima e a mascara menor os de baixo.
	int metade_superior = bits_altos(valor1);
	int metade_inferior = bits_baixos(valor2);

	return or_binario(metade_superior, metade_inferior);
}

// Faz um and binario com o valor 1 e o valor 2
std::uint16_t cruzar_aritmeticamente(std::uint16_t valor1, std::uint16_t valor2) {
	return and_binario(valor1, valor2);
}
