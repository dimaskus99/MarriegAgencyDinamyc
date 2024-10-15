#include "Database.h"
#include <algorithm>

void Database::addClient(const Client& client) {
    mClients.push_back(client);
}

void Database::displayAllClients() const {
    for (const auto& client : mClients) {
        client.displayInfo();
        std::cout << "---------------------------------\n";
    }
}

void Database::displayLookingForPartner() const {
    for (const auto& client : mClients) {
        if (client.isLookingForPartner()) {
            client.displayInfo();
            std::cout << "---------------------------------\n";
        }
    }
}

void Database::displayNotLookingForPartner() const {
    for (const auto& client : mClients) {
        if (!client.isLookingForPartner()) {
            client.displayInfo();
            std::cout << "---------------------------------\n";
        }
    }
}

bool Database::removeClient(const std::string& clientCode) {
    auto it = std::remove_if(mClients.begin(), mClients.end(),
        [&clientCode](const Client& client) {
            return client.getCode() == clientCode;  
        });

    if (it != mClients.end()) {
        mClients.erase(it, mClients.end());
        return true;  
    } else {
        return false;  
    }
}
bool Database::updateClientAge(const std::string& clientCode, int newAge) {
    for (auto& client : mClients) {
        if (client.getCode() == clientCode) {
            client.setAge(newAge);  
            return true;
        }
    }
    return false;  
}
