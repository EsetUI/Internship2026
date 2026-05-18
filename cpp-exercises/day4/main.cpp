#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <format>
#include <algorithm>
#include <iomanip>
#include <fstream>

std::string handle_file_input(const std::string& );
std::vector<double> handle_console_input();
std::vector<double> parse_numbers(const std::string& );

void print_v(const std::vector<double>&);
void print_stats(const std::vector<double>&);

double get_sum(const std::vector<double>&);
double get_avr(const std::vector<double>& nums);


int main(int argc, char* argv[]) {
	std::vector<double> nums;
	if (argc > 1) {
		nums = parse_numbers(handle_file_input(argv[1]));
	}
	else {
		nums = handle_console_input();
	}
	
	nums = handle_console_input();
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
	std::cout << '\n';
	if (choice == 'y') {
		std::cout << "numbers: ";
		print_v(nums);
	}

	std::cout << std::format("Count: {}\n", nums.size());
	std::cout << std::format("Sum: {:.2f}\n", get_sum(nums));
	std::cout << std::format("Avrage: {:.2f}\n", get_avr(nums));
	std::cout << std::format("\033[31mMin number: {}\033[0m\n", *std::min_element(nums.begin(), nums.end()));
	std::cout << std::format("\033[32mMax number: {}\033[0m\n", *std::max_element(nums.begin(), nums.end()));

}
double get_avr(const std::vector<double>& nums) {
	return get_sum(nums) / nums.size();
}


double get_sum(const std::vector<double>& nums) {
	double sum{};
	for (auto num : nums) {
		sum += num;
	}
	return sum;
}

std::string handle_file_input(const std::string &file_name) {
	std::ifstream fin(file_name);
	if (!fin.is_open()) {
		std::cerr << std::format("\nFile '{}' failed to open\n\n", file_name);
		exit(-1);
	}

	std::string raw_input;
	fin.seekg(0, std::ios_base::end);
	raw_input.resize(fin.tellg());
	fin.seekg(0, std::ios_base::beg);
	fin.read(raw_input.data(), raw_input.size());

	return raw_input;
}

std::vector<double> handle_console_input() {
	std::vector<double> output;
	std::string raw_input;
	while (output.empty()) {
		std::cout << "Enter numbers: ";
		std::getline(std::cin, raw_input);
		output = parse_numbers(raw_input);
	}
	return output;
}

std::vector<double> parse_numbers(const std::string &raw_input) {
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
			auto peek = input.peek();
			if (peek == ',' || peek == ';') {
				input.ignore();
			}
			else {
				std::cout << "\nInvalid input\n\n";
				return {};
			}
		}
	}
}