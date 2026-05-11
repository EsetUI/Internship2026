#include <iostream>
#include <string>

void print_menu() {
    std::cout << "\nMini-project menu\n";
    std::cout << "1. Run main feature\n";
    std::cout << "2. Show help\n";
    std::cout << "3. Exit\n";
}

void run_main_feature() {
    std::cout << "Replace this function with the core logic of your project.\n";
}

void show_help() {
    std::cout << "Describe what your project does and how a user should use it.\n";
}

int main() {
    while (true) {
        print_menu();

        std::string choice;
        std::cout << "Choose an option: ";
        std::getline(std::cin, choice);

        if (choice == "1") {
            run_main_feature();
        } else if (choice == "2") {
            show_help();
        } else if (choice == "3") {
            std::cout << "Goodbye.\n";
            break;
        } else {
            std::cout << "Unknown option. Try again.\n";
        }
    }

    return 0;
}
