#include <iostream>
#include "Database.h"

int displayMenu() {
    int selection;
    std::cout << "1) Add new client\n";
    std::cout << "2) Display all clients\n";
    std::cout << "3) Display clients looking for partner\n";
    std::cout << "4) Display clients not looking for partner\n";
    std::cout << "5) Remove a client\n";
    std::cout << "6) Update client age\n";
    std::cout << "0) Exit\n";
    std::cout << "---> ";
    std::cin >> selection;
    return selection;
}

Client createClient() {
    std::string code, name, gender, birthDate, maritalStatus, badHabits, hobbies, description, signCode, relationCode, nationalityCode, address, phone, passport, partnerInfo;
    int age, height, weight, children;

    std::cout << "Enter client code: ";
    std::cin >> code;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter gender: ";
    std::cin >> gender;
    std::cout << "Enter birth date (yyyy-mm-dd): ";
    std::cin >> birthDate;
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cout << "Enter height (cm): ";
    std::cin >> height;
    std::cout << "Enter weight (kg): ";
    std::cin >> weight;
    std::cout << "Enter number of children: ";
    std::cin >> children;
    std::cout << "Enter marital status: ";
    std::cin >> maritalStatus;
    std::cout << "Enter bad habits: ";
    std::cin >> badHabits;
    std::cout << "Enter hobbies: ";
    std::cin >> hobbies;
    std::cout << "Enter description: ";
    std::cin.ignore();
    std::getline(std::cin, description);
    std::cout << "Enter sign code: ";
    std::cin >> signCode;
    std::cout << "Enter relation code: ";
    std::cin >> relationCode;
    std::cout << "Enter nationality code: ";
    std::cin >> nationalityCode;
    std::cout << "Enter address: ";
    std::cin.ignore();
    std::getline(std::cin, address);
    std::cout << "Enter phone: ";
    std::cin >> phone;
    std::cout << "Enter passport: ";
    std::cin >> passport;
    std::cout << "Enter partner info: ";
    std::cin.ignore();
    std::getline(std::cin, partnerInfo);

    return Client(code, name, gender, birthDate, age, height, weight, children, maritalStatus, badHabits, hobbies, description, signCode, relationCode, nationalityCode, address, phone, passport, partnerInfo);
}

void removeClient(Database& db) {
    std::string clientCode;
    std::cout << "Enter the client code to remove: ";
    std::cin >> clientCode;

    if (db.removeClient(clientCode)) {
        std::cout << "Client with code " << clientCode << " has been removed.\n";
    } else {
        std::cout << "Client with code " << clientCode << " not found.\n";
    }
}

void updateClientAge(Database& db) {
    std::string clientCode;
    int newAge;
    std::cout << "Enter the client code: ";
    std::cin >> clientCode;
    std::cout << "Enter the new age: ";
    std::cin >> newAge;

    if (db.updateClientAge(clientCode, newAge)) {
        std::cout << "Client's age updated successfully.\n";
    } else {
        std::cout << "Client with code " << clientCode << " not found.\n";
    }
}

int main() {
    Database db;
    bool done = false;

    while (!done) {
        int selection = displayMenu();
        switch (selection) {
            case 1: {
                Client client = createClient();
                db.addClient(client);
                break;
            }
            case 2:
                db.displayAllClients();
                break;
            case 3:
                db.displayLookingForPartner();
                break;
            case 4:
                db.displayNotLookingForPartner();
                break;
            case 5:  
                removeClient(db);
                break;
            case 6:
                updateClientAge(db);
            case 0:
                done = true;
                break;
            default:
                std::cout << "Invalid option! Try again.\n";
        }
    }
    return 0;
}
