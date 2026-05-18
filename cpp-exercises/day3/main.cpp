#include <iostream>
#include <format>
#include <span>
#include <string>
#include <cctype>

double c_to_f(double);
double f_to_c(double);
double c_to_k(double);
double k_to_c(double);
void print_output(std::span<std::string_view>, double );

template<typename T>
T request_valid_input(std::string_view,std::string_view error_msg);

template<typename T, typename _T>
T request_valid_input(std::string_view , std::string_view ,const _T&);


int main() {
	double degrees{};
	std::string_view slovak[] = { {"Zadajte teplotu na konverciu ({} na {}): "},{"vasa teplota vo {} je {}{}"}, {"Zadajte z akej jednotky chcete konvertovat: "},
								{"Zadajte do akej jednotky chcete konvertovat: "},{"Moznosti:\nC = celzia\nF = farengeit\nK = kelvin\n"},};
	std::string_view english[] = { {"Enter a temperature to convert ({} to {}): "}, {"Your temperature in {} is {}{}"}, {"Enter from which unit you want to convert: "},
								{"Enter to which unit you want to convert: "},{"Options:\nC = celsius\nF = fahrenheit\nK = kelvin\n"},};
	
	char lang = request_valid_input<char, std::string>("\ns = slovak\ne = english\nEnter language: ", "Invalid language please only enter from the language options\n\n", "se");

	switch (lang) {
	case 's':
		print_output(slovak, degrees);
		break;
	case 'e':
		print_output(english, degrees);
		break;
	}
}

void print_output(std::span<std::string_view> arr, double degrees) {
	std::cout << arr[4];
	char unit_from{};
	char unit_to{};

	while (true) {
		unit_from = request_valid_input<char, std::string>(arr[2], "\nInvalid input you have to enter a valid unit(C,F,K)\n\n", "CFK");
		unit_to = request_valid_input<char, std::string>(arr[3], "\nInvalid input you have to enter a valid unit(C,F,K)\n\n", "CFK");
		if (unit_from != unit_to) break;
		std::cout << "\nConversion to the same unit is not possible\n\n";
	}
	unit_from = std::toupper(static_cast<unsigned char>(unit_from));
	unit_to = std::toupper(static_cast<unsigned char>(unit_to));
	degrees = request_valid_input<double>(std::vformat(arr[0],std::make_format_args(unit_from, unit_to)), "\nInvalid input enter a real number\n\n");

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

template<typename T>
T request_valid_input(std::string_view input_msg, std::string_view error_msg) {
	T value{};
	std::string input;
	while (true) {
		std::cout << input_msg;
		if (!(std::cin >> value)) {
			std::cerr << error_msg;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else {
			break;
		}
	}

	return value;
}

template<typename T, typename _T>
T request_valid_input(std::string_view input_msg, std::string_view error_msg,const _T &input_options) {
	T value{};
	std::string input;
	while (true) {
		std::cout << input_msg;
		if (!(std::cin >> value)) {
			std::cerr << error_msg;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else {
			value = std::tolower(static_cast<unsigned char>(value));
			for (auto option : input_options) {
				option = std::tolower(static_cast<unsigned char>(option));
				if (option == value) {
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					return value;
				}
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << std::format("\nValue '{}' was not included in valid options\n\n", value);
		}
	}
}