#include <iostream>
#include <format>
#include <span>
double c_to_f(double);
void print_output(std::string*, double );

int main() {
	double degrees{};
	char lang{};
	std::string slovak[] = { {"Zadajte teplotu na konverciu (celzia na farenheit): "},{"vasa teplota vo farenheitoch je "} };
	std::string english[] = { {"Enter a temperature to convert (celsius to fahrenheit): "}, {"Your temperature in fahrenheit is "} };
	


	std::cout << "s = slovak\ne = english\nEnter language: ";
	std::cin >> lang;
	switch (lang) {
	case 's':
		print_output(slovak, degrees);
		break;
	default:
		print_output(english, degrees);
	}

}

void print_output(std::span<std::string> arr, double degrees) {
	std::cout << std::format("{}", arr[0]);
	std::cin >> degrees;
	std::cout << std::format("{}{}F", arr[1], c_to_f(degrees));
}

double c_to_f(double c) {
	return c * 9.0 / 5.0 + 32.0;
}
