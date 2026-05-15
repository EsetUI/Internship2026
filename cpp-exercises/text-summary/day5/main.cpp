#include <iostream>
#include <string>
#include <format>
#include <sstream>

std::string get_console_input(std::string_view);
void print_text_info(const std::string&);
size_t get_vowel_count(const std::string&);
size_t get_word_count(const std::string&);
std::string separate_copy(std::string);


int main() {
	std::string input = get_console_input("Enter text: ");
	print_text_info(input);
}


void print_text_info(const std::string &input) {
	
	std::cout << std::format("Text size: {}\n", input.length());
	std::cout << std::format("Vowel count: {}\n", get_vowel_count(input));
	std::cout << std::format("Word count: {}\n", get_word_count(input));
}

size_t get_word_count(const std::string &raw_input) {
	std::istringstream input(separate_copy(raw_input));
	std::string word;
	size_t word_count{};
	while (input >> word) {
		word_count++;
	}
	return word_count;
}

std::string separate_copy(std::string input) {

	for (int i = 0; i < input.length();i++) {
		if (input[i]=='.'|| input[i] == ',' || input[i] == ';' || input[i] == ':') {
			input[i] = ' ';
		}
	}
	return input;
}

size_t get_vowel_count(const std::string &input) {
	std::string vowels = "aeiouAEIOU";
	size_t count{};
	for (auto c : input) {
		if (vowels.find(c) != std::string::npos) {
			count++;
		}
	}
	return count;
}

std::string get_console_input(std::string_view input_msg) {
	std::string input;
	std::cout << input_msg;
	std::getline(std::cin, input);

	return input;
}