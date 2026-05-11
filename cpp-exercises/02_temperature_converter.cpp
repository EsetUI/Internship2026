#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>

double parse_number(const std::string& text) {
    std::size_t processed = 0;
    const double value = std::stod(text, &processed);

    if (processed != text.size()) {
        throw std::invalid_argument("Temperature must be a number.");
    }

    return value;
}

char parse_unit(const std::string& text) {
    if (text.size() != 1) {
        throw std::invalid_argument("Unit must be C or F.");
    }

    const char unit = static_cast<char>(std::toupper(static_cast<unsigned char>(text[0])));

    if (unit != 'C' && unit != 'F') {
        throw std::invalid_argument("Unit must be C or F.");
    }

    return unit;
}

double celsius_to_fahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    std::string value_text;
    std::string unit_text;

    std::cout << "Temperature converter\n";
    std::cout << "Enter the temperature value: ";
    std::getline(std::cin, value_text);

    std::cout << "Is the value in C or F? ";
    std::getline(std::cin, unit_text);

    try {
        const double value = parse_number(value_text);
        const char unit = parse_unit(unit_text);

        std::cout << std::fixed;
        std::cout.precision(2);

        if (unit == 'C') {
            std::cout << value << " C is " << celsius_to_fahrenheit(value) << " F\n";
        } else {
            std::cout << value << " F is " << fahrenheit_to_celsius(value) << " C\n";
        }
    } catch (const std::exception& error) {
        std::cout << "Invalid input: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
