#include <iostream>
#include <string>
#include <format>
#include "calculator.hpp"

int main() {
	Calculator c;
	std::cout << "Enter expression: ";
	std::string exp{};
	std::getline(std::cin, exp);
	std::cout << std::format("{} = {}", exp, c.calculate(exp));
}
