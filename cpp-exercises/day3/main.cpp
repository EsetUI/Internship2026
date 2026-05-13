#include <iostream>
#include <format>
#include <span>
#include <string>
double c_to_f(double);
void print_output(std::span<std::string_view>, double );

int main() {
	double degrees{};
	char lang{};
	std::string_view slovak[] = { {"Zadajte teplotu na konverciu (celzia na farenheit): "},{"vasa teplota vo farenheitoch je {}F"} };
	std::string_view english[] = { {"Enter a temperature to convert (celsius to fahrenheit): "}, {"Your temperature in fahrenheit is {}F"} };
	
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

void print_output(std::span<std::string_view> arr, double degrees) {
	std::cout << arr[0];
	std::cin >> degrees;
	
	double temp = c_to_f(degrees);
	std::cout << std::vformat(arr[1], std::make_format_args(temp));
}

double c_to_f(double c) {
	return c * 9.0 / 5.0 + 32.0;
}
