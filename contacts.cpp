#include <iostream>
#include "contact.hpp"
#include <vector>
#include <map>

std::map<std::string, std::string> contacts {};

void printContacts() {
    if (contacts.size() == 0) {
        std::cout << "Список контактов пуст. \n" << std::endl;
    }
    
    for (auto const& contact : contacts) {
        std::cout << contact.first << " | "  << contact.second << std::endl;
        std::cout << std::endl;
    }
}

void Contact::addContact() {
    std::string name;
    std::string phone;
    std::cout << "Введите имя и номер телефона нового контакта." << std::endl;
    std::cin >> name;
    std::cin >> phone;

    try {
        contacts[name] = phone;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
    std::cout << "Добавлено. \n" << std::endl;
    printContacts();
}

void Contact::findContact() {
    if (contacts.size() == 0) {
        std::cout << "Список контактов пуст. \n" << std::endl;
        return;
    }

    std::cout << "Поиск контакта по имени." << std::endl;
    std::string findName;
    std::cin >> findName;
    std::cout << std::endl;

    bool find = false;
    for (auto const& contact : contacts) {
        if (findName == contact.first) {
            find = true;
            std::cout << contact.first << " | "  << contact.second << std::endl;
            std::cout << std::endl;
        }
    }

    if (!find) {
        std::cout << "Ничего не найдено." << std::endl;
    }
}   

void Contact::deleteContact() {
    std::cout << "Удаление контакта по имени." << std::endl;
    std::string deleteName;
    std::cin >> deleteName;

    auto it = contacts.find(deleteName);
    if (it != contacts.end()) {
        contacts.erase(it);
        std::cout << "Контакт '" << deleteName << "' удален.\n" << std::endl;
        printContacts();
    } else {
        std::cout << "Контакт с именем '" << deleteName << "' не найден.\n" << std::endl;
    }
}

void Contact::changeContact() {
    std::cout << "Изменение имени контакта." << std::endl;
    
    std::string oldName;
    std::cout << "Введите старое имя контакта: ";
    std::cin >> oldName;

    auto it = contacts.find(oldName);
    if (it != contacts.end()) {
        std::string newName;
        std::cout << "Введите новое имя контакта: ";
        std::cin >> newName;

        contacts[newName] = it->second;
        contacts.erase(it);

        std::cout << "Имя контакта успешно изменено.\n" << std::endl;
        printContacts();
    } else {
        std::cout << "Контакт с именем '" << oldName << "' не найден.\n" << std::endl;
    }
}
