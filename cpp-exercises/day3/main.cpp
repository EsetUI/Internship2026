#include <iostream>
#include <format>
#include <span>
#include <string>

double c_to_f(double);
double f_to_c(double);
double c_to_k(double);
double k_to_c(double);
void print_output(std::span<std::string_view>, double );
double request_valid_input(std::string_view);

int main() {
	double degrees{};
	char lang{};
	std::string_view slovak[] = { {"Zadajte teplotu na konverciu ({} na {}): "},{"vasa teplota vo {} je {}{}"}, {"Zadajte z akej jednotky chcete konvertovat: "},
								{"Zadajte do akej jednotky chcete konvertovat"},{"Moznosti:\nC = celzia\nF = farengeit\nK = kelvin\n"},};
	std::string_view english[] = { {"Enter a temperature to convert ({} to {}): "}, {"Your temperature in {} is {}{}"}, {"Enter from which unit you want to convert: "},
								{"Enter to which unit you want to convert: "},{"Options:\nC = celsius\nF = fahrenheit\nK = kelvin\n"},};
	
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
	char unit_from;
	char unit_to;
	std::cout << arr[4];
	std::cout << arr[2];
	std::cin >> unit_from;

	std::cout << arr[3];
	std::cin >> unit_to;
	
	degrees = request_valid_input(std::vformat(arr[0],std::make_format_args(unit_from, unit_to)));

	double temp{};
	switch (unit_from) {
	case 'C':
		switch (unit_to) {
		case 'F': 
			temp = c_to_f(degrees); 
			break;
		case 'K': 
			temp = c_to_k(degrees); 
			break;
		}
		break;
	case 'F':
		switch (unit_to) {
		case 'C': 
			temp = f_to_c(degrees);
			break;
		case 'K':
			temp = f_to_c(degrees); 
			temp = c_to_k(temp);
			break;
		}
		break;
	case 'K':
		switch (unit_to) {
		case 'C':
			temp = k_to_c(degrees);
			break;
		case 'F':
			temp = k_to_c(degrees);
			temp = c_to_f(temp);
			break;
		}
		break;
	}
	std::cout << std::vformat(arr[1], std::make_format_args(unit_to, temp, unit_to));
}

double c_to_f(double c) {
	return c * 9.0 / 5.0 + 32.0;
}
double f_to_c(double f) {
	return (f - 32) * 5 / 9;
}
double c_to_k(double c) {
	return c + 273.15;
}
double k_to_c(double k) {
	return k - 273.15;
}

double request_valid_input(std::string_view input_msg) {
	double degrees{};
	std::string input;
	while (true) {
		std::cout << input_msg;
		if (!(std::cin >> degrees)) {
			std::cerr << "\nWrong input try a real number\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else {
			break;
		}
	}

	return degrees;
}
