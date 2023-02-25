#include <cstdint>

std::uint16_t ligar_bit(std::uint16_t valor, std::uint16_t indice_bit) {
	int mascara = 1 << indice_bit;
	return valor | mascara;
}

std::uint16_t desligar_bit(std::uint16_t valor, std::uint16_t indice_bit) {
	int mascara = 1 << indice_bit;
	return valor & ~mascara;
}

bool testar_bit(std::uint16_t valor, std::uint16_t indice_bit) {
	int mascara = 1 << indice_bit;
	return (valor & mascara) == 0;
}

// Se o bit indicado pelo indice_bit no valor estiver ligado, desliga-o. Caso desligado, liga-o.
std::uint16_t alternar_bit(std::uint16_t valor, std::uint16_t indice_bit) {
	bool ligado = testar_bit(valor, indice_bit);

	if (ligado) {
		return ligar_bit(valor, indice_bit);
	}
	return desligar_bit(valor, indice_bit);
}

std::uint16_t and_binario(std::uint16_t valor1, std::uint16_t valor2) {
	return valor1 & valor2;
}

std::uint16_t or_binario(std::uint16_t valor1, std::uint16_t valor2) {
	return valor1 | valor2;
}

std::uint16_t bits_baixos(std::uint16_t valor) {
	const std::uint16_t mascara_menor = 255; // 0000 0000 1111 1111
	return valor & mascara_menor;
}

std::uint16_t bits_altos(std::uint16_t valor) {
	const std::uint16_t mascara_maior = 65280; // 1111 1111 0000 0000
	return valor & mascara_maior;
}
