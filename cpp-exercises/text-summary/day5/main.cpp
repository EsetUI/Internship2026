#include <iostream>
#include <string>
#include <format>
#include <sstream>
#include <cctype>
#include <map>
#include <fstream>

std::string get_console_input(std::string_view);
std::string get_file_input(const std::string& file_name);
void print_text_info(const std::string&);
size_t get_vowel_count(const std::string&);
size_t get_word_count(const std::string&);
std::string remove_punctuation_copy(std::string);
size_t get_unique_word_count( std::string);
void turn_lowercase(std::string&);
size_t get_scentence_count(const std::string& input);



int main(int argc, char* argv[]) {
	std::string input;
	if (argc > 1) {
		input = get_file_input(argv[1]);
	}
	else {
		input = get_console_input("Enter text: ");
	}

	print_text_info(input);
}

std::string get_file_input(const std::string &file_name) {
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

void print_text_info(const std::string &input) {
	std::cout << std::format("Text size:         {}\n", input.length());
	std::cout << std::format("Vowel count:       {}\n", get_vowel_count(input));
	std::cout << std::format("Word count:        {}\n", get_word_count(input));
	std::cout << std::format("Unique word count: {}\n", get_unique_word_count(input));
	std::cout << std::format("Scentences:        {}\n", get_scentence_count(input));
}

size_t get_word_count(const std::string &raw_input) {
	std::istringstream input(remove_punctuation_copy(raw_input));
	std::string word;
	size_t word_count{};
	while (input >> word) {
		word_count++;
	}
	return word_count;
}

std::string remove_punctuation_copy(std::string input) {//replaces all panctuation with ' ' and returns a copy
	for (char& c : input) {
		if (std::ispunct(static_cast<unsigned char>(c))) {
			c = ' ';
		}
	}
	return input;
}

void turn_lowercase(std::string &input) {
	for (char& c : input) {
		c = std::tolower(static_cast<unsigned char>(c));
	}
}

size_t get_unique_word_count(std::string raw_input) {
	turn_lowercase(raw_input);
	std::map<std::string, size_t> u_words;
	std::istringstream input(remove_punctuation_copy(raw_input));
	std::string word;
	while (input >> word) {
		u_words[word]++;
	}
	return u_words.size();
}

size_t get_scentence_count(const std::string& input) {//only counts scentences that have at least one letter and end with '.' or '?' or '!'
	bool has_letter = false;
	size_t count{};
	for (auto c : input) {
		if (std::isalpha(static_cast<unsigned char>(c))) {
			has_letter = true;
		}
		else if (c == '.' || c == '?' || c == '!') {
			if (has_letter) {
				count++;
				has_letter = false;
			}
		}
	}
	return count;
}


size_t get_vowel_count(const std::string &input) {
	constexpr std::string_view vowels = "aeiouAEIOU";
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
	if (input.empty()) {
		return get_console_input(input_msg);
	}
	return input;
}