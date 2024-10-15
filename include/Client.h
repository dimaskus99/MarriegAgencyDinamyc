#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>

class Client {
public:
    Client();
    Client(std::string code, std::string name, std::string gender, std::string birthDate, 
           int age, int height, int weight, int children, std::string maritalStatus, 
           std::string badHabits, std::string hobbies, std::string description, 
           std::string signCode, std::string relationCode, std::string nationalityCode,
           std::string address, std::string phone, std::string passport, std::string partnerInfo);
    
    void displayInfo() const;
    bool isLookingForPartner() const;
    void setAge(int newAge);
    std::string getCode() const;
    int getAge() const;

private:
    std::string mCode;
    std::string mName;
    std::string mGender;
    std::string mBirthDate;
    int mAge;
    int mHeight;
    int mWeight;
    int mChildren;
    std::string mMaritalStatus;
    std::string mBadHabits;
    std::string mHobbies;
    std::string mDescription;
    std::string mSignCode;
    std::string mRelationCode;
    std::string mNationalityCode;
    std::string mAddress;
    std::string mPhone;
    std::string mPassport;
    std::string mPartnerInfo;
};

#endif
