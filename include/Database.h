#ifndef DATABASE_H
#define DATABASE_H

#include "Client.h"
#include <vector>

class Database {
public:
    void addClient(const Client& client);
    void displayAllClients() const;
    void displayLookingForPartner() const;
    void displayNotLookingForPartner() const;
    bool removeClient(const std::string& clientCode);
    bool updateClientAge(const std::string& clientCode, int newAge);

private:
    std::vector<Client> mClients;
};

#endif
