#include <iostream>
#include "contact.hpp"
#include <vector>
#include <map>

std::map<std::string, std::string> contacts {};

void printContacts() {
    for (auto c : contacts) {
        std::cout << c.first << " | "   << c.second << std::endl;
        std::cout << std::endl;
    }
}

void Contact::addContact() {
    std::string name;
    std::string phone;
    std::cout << "Введите имя и номер телефона нового контакта " << std::endl;
    std::cin >> name;
    std::cin >> phone;

    try {
        contacts[name] = phone;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
    std::cout << "Добавлено." << std::endl;
    printContacts();
}

void Contact::findContact() {
    // Implement the findContact method
}

void Contact::deleteContact() {
    // Implement the deleteContact method
}

void Contact::changeContact() {
    // Implement the changeContact method
}
