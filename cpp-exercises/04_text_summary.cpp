#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

int count_words(const std::string& text) {
    std::istringstream input(text);
    std::string word;
    int count = 0;

    while (input >> word) {
        ++count;
    }

    return count;
}

int count_vowels(const std::string& text) {
    int vowels = 0;

    for (char character : text) {
        char lower = static_cast<char>(std::tolower(static_cast<unsigned char>(character)));

        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
            ++vowels;
        }
    }

    return vowels;
}

int main() {
    std::string text;

    std::cout << "Enter a sentence or short paragraph: ";
    std::getline(std::cin, text);

    if (text.empty()) {
        std::cout << "No text entered.\n";
        return 1;
    }

    std::cout << "Characters: " << text.size() << '\n';
    std::cout << "Words: " << count_words(text) << '\n';
    std::cout << "Vowels: " << count_vowels(text) << '\n';

    return 0;
}
