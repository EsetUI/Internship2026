#include <iostream>
#include <string>

std::string build_welcome_message(const std::string& name) {
    if (name.empty()) {
        return "Hello, Student! Welcome to the internship.";
    }
 
    return "Hello, " + name + "! Welcome to the internship.";
}

int main() {
    std::string name;
    std::string topic;
    int age;
    std::cout << "Internship welcome program\n";
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "How old are you: ";
    std::cin >> age;

    std::cout << "What do you want to practice most? ";
    std::getline(std::cin, topic);

    if (topic.empty()) {
        topic = "C++ and Python";
    }

    std::cout << '\n';
    std::cout << build_welcome_message(name) << '\n';
    std::cout << "Your focus for the internship is: " << topic << ".\n";
    std::cout << "Write small changes, test often, and ask clear questions.\n";

    return 0;
}
