#include <cstdint>

#pragma once

std::uint16_t ligar_bit(std::uint16_t valor, std::uint16_t indice_bit);
std::uint16_t desligar_bit(std::uint16_t valor, std::uint16_t indice_bit);
std::uint16_t alternar_bit(std::uint16_t valor, std::uint16_t indice_bit);
bool testar_bit(std::uint16_t valor, std::uint16_t indice_bit);
std::uint16_t and_binario(std::uint16_t valor1, std::uint16_t valor2);
std::uint16_t or_binario(std::uint16_t valor1, std::uint16_t valor2);
std::uint16_t bits_baixos(std::uint16_t valor);
std::uint16_t bits_altos(std::uint16_t valor);
