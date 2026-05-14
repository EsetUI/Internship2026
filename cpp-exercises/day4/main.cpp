#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <format>

std::vector<double> handle_input();
void print_v(const std::vector<double>&);
void print_stats(const std::vector<double>&);
double get_sum(const std::vector<double>&);


int main() {
	std::vector<double> nums = handle_input();

	print_stats(nums);
}

void print_v(const std::vector<double> &vec) {
	for (auto num : vec) {
		std::cout << std::format("{}; ", num);
	}
	std::cout << '\n';
}

void print_stats(const std::vector<double> &nums) {
	char choice{};
	std::cout << "Show numbers before statistics?(y,n): ";
	std::cin >> choice;
	if (choice == 'y') {
		std::cout << "numbers: ";
		print_v(nums);
	}
	
	

	std::cout << std::format("Sum: {}\n", get_sum(nums));
}

double get_sum(const std::vector<double>& nums) {
	double sum{};
	for (auto num : nums) {
		sum += num;
	}
	return sum;
}




std::vector<double> handle_input() {
	std::string raw_input;
	std::cout << "Numbers: ";
	std::getline(std::cin, raw_input);
	std::stringstream input(raw_input);
	std::vector<double> output;
	double temp{};
	while (true) {
		if (input >> temp) {
			output.push_back(temp);
		}
		else {
			if (input.eof()) {
				return output;
			}

			input.clear();
			char peek = input.peek();
			if (peek == ',' || peek == ';') {
				input.ignore();
			}
			else {
				std::cout << "\nInvalid input\n\n";
				return handle_input();
			}
		}
	}
}