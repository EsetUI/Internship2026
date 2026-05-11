#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

double calculate_average(const std::vector<double>& numbers) {
    double total = 0.0;

    for (double number : numbers) {
        total += number;
    }

    return total / static_cast<double>(numbers.size());
}

int main() {
    int count = 0;
    std::cout << "How many numbers do you want to enter? ";
    std::cin >> count;

    if (!std::cin || count <= 0) {
        std::cout << "Please enter a positive whole number.\n";
        return 1;
    }

    std::vector<double> numbers;
    numbers.reserve(count);

    double minimum = std::numeric_limits<double>::max();
    double maximum = std::numeric_limits<double>::lowest();

    for (int index = 0; index < count; ++index) {
        double value = 0.0;
        std::cout << "Enter number " << (index + 1) << ": ";
        std::cin >> value;

        if (!std::cin) {
            std::cout << "Invalid number input.\n";
            return 1;
        }

        numbers.push_back(value);

        if (value < minimum) {
            minimum = value;
        }

        if (value > maximum) {
            maximum = value;
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Minimum: " << minimum << '\n';
    std::cout << "Maximum: " << maximum << '\n';
    std::cout << "Average: " << calculate_average(numbers) << '\n';

    return 0;
}
