#include <iostream>

class Contact {
private: 
    std::string name;
    std::string phone;

public:
    Contact(std::string _name, std::string _phone);
    void findContact();
    void addContact();
    void deleteContact();
    void changeContact();
};