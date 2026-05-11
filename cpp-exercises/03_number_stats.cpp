#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::string trim(const std::string& text) {
    const std::size_t start = text.find_first_not_of(" \t");

    if (start == std::string::npos) {
        return "";
    }

    const std::size_t end = text.find_last_not_of(" \t");
    return text.substr(start, end - start + 1);
}

std::vector<double> parse_numbers(const std::string& text) {
    std::string normalized = text;
    std::replace(normalized.begin(), normalized.end(), ';', ',');

    std::vector<double> numbers;
    std::stringstream input(normalized);
    std::string part;

    while (std::getline(input, part, ',')) {
        const std::string cleaned_part = trim(part);

        if (cleaned_part.empty()) {
            continue;
        }

        std::size_t processed = 0;
        const double value = std::stod(cleaned_part, &processed);

        if (processed != cleaned_part.size()) {
            throw std::invalid_argument("Invalid number: " + cleaned_part);
        }

        numbers.push_back(value);
    }

    if (numbers.empty()) {
        throw std::invalid_argument("Enter at least one number.");
    }

    return numbers;
}

double calculate_sum(const std::vector<double>& numbers) {
    double total = 0.0;

    for (double number : numbers) {
        total += number;
    }

    return total;
}

int main() {
    std::string raw_input;

    std::cout << "Number statistics\n";
    std::cout << "Enter numbers separated by commas: ";
    std::getline(std::cin, raw_input);

    try {
        const std::vector<double> numbers = parse_numbers(raw_input);
        const double total = calculate_sum(numbers);

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Count: " << numbers.size() << '\n';
        std::cout << "Minimum: " << *std::min_element(numbers.begin(), numbers.end()) << '\n';
        std::cout << "Maximum: " << *std::max_element(numbers.begin(), numbers.end()) << '\n';
        std::cout << "Sum: " << total << '\n';
        std::cout << "Average: " << total / static_cast<double>(numbers.size()) << '\n';
    } catch (const std::exception& error) {
        std::cout << "Invalid input: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
