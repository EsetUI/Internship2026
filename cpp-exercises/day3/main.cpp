#include <iostream>
#include <format>
#include <vector>
double c_to_f(double);

int main() {
	const size_t number_of_sentences = 2;
	double degrees;
	char lang;
	std::string slovak[] = { {"Zadajte teplotu na konverciu (celzia na farenheit): "},{"vasa teplota vo farenheitoch je "} };
	std::string english[] = { {"Enter a temperature to convert (celsius to fahrenheit): "}, {"Your temperature in fahrenheit is "} };
	
	std::string language[number_of_sentences];

	std::cout << "s = slovak\ne = english\nEnter language: ";
	std::cin >> lang;
	switch (lang){
	case 's':
		for (int i = 0;i < number_of_sentences;i++) {
			language[i] = slovak[i];
		}
		break;
	default:
		for (int i = 0;i < number_of_sentences;i++) {
			language[i] = english[i];
		}
	}

	std::cout << std::format("{}", language[0]);
	std::cin >> degrees;
	std::cout << std::format("{}{}F", language[1], c_to_f(degrees));
}

double c_to_f(double c) {
	return c * 9.0 / 5.0 + 32.0;
}
