#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    const int target = std::rand() % 100 + 1;

    int guess = 0;
    int attempts = 0;

    std::cout << "Guess the number between 1 and 100.\n";

    while (true) {
        std::cout << "Your guess: ";
        std::cin >> guess;

        if (!std::cin) {
            std::cout << "Please enter a whole number.\n";
            return 1;
        }

        ++attempts;

        if (guess < target) {
            std::cout << "Too low.\n";
        } else if (guess > target) {
            std::cout << "Too high.\n";
        } else {
            std::cout << "Correct. You needed " << attempts << " attempts.\n";
            break;
        }
    }

    return 0;
}
