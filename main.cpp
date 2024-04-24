#include <iostream>
#include "contact.hpp"

int main() {
    while (true) {
        std::cout << "Контакты \n Выберите действие: " << std::endl;
        std::cout << "0 - Выйти \n 1 - Добавить контакт \n 2 - Найти контакт \n 3 - Удалить контакт \n 4 - Изменить контакт \n";
        char action;
        std::cin >> action;

        switch (action) {
            case '0': return 0;
            case '1': { 
                Contact contact;
                contact.addContact();
                break;
            }
            case '2': {
                Contact contact;
                contact.findContact();
                break;
            }
            case '3': {
                Contact contact;
                contact.deleteContact();
                break;
            }
            case '4': {
                Contact contact;
                contact.changeContact();
                break;
            }

            default:
                std::cout << "Неизвестная команда" << std::endl;
        }
    }

    return 0;
}