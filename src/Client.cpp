#include "Client.h"

Client::Client() {}

Client::Client(std::string code, std::string name, std::string gender, std::string birthDate, 
               int age, int height, int weight, int children, std::string maritalStatus, 
               std::string badHabits, std::string hobbies, std::string description, 
               std::string signCode, std::string relationCode, std::string nationalityCode,
               std::string address, std::string phone, std::string passport, std::string partnerInfo) 
    : mCode(code), mName(name), mGender(gender), mBirthDate(birthDate), mAge(age), mHeight(height),
      mWeight(weight), mChildren(children), mMaritalStatus(maritalStatus), mBadHabits(badHabits),
      mHobbies(hobbies), mDescription(description), mSignCode(signCode), mRelationCode(relationCode),
      mNationalityCode(nationalityCode), mAddress(address), mPhone(phone), mPassport(passport),
      mPartnerInfo(partnerInfo) {}

void Client::displayInfo() const {
    std::cout << "Client Code: " << mCode << std::endl;
    std::cout << "Name: " << mName << std::endl;
    std::cout << "Gender: " << mGender << std::endl;
    std::cout << "Birth Date: " << mBirthDate << std::endl;
    std::cout << "Age: " << mAge << std::endl;
    std::cout << "Height: " << mHeight << " cm" << std::endl;
    std::cout << "Weight: " << mWeight << " kg" << std::endl;
    std::cout << "Children: " << mChildren << std::endl;
    std::cout << "Marital Status: " << mMaritalStatus << std::endl;
    std::cout << "Bad Habits: " << mBadHabits << std::endl;
    std::cout << "Hobbies: " << mHobbies << std::endl;
    std::cout << "Address: " << mAddress << std::endl;
    std::cout << "Phone: " << mPhone << std::endl;
    std::cout << "Passport: " << mPassport << std::endl;
    std::cout << "Partner Info: " << mPartnerInfo << std::endl;
}

bool Client::isLookingForPartner() const {
    return mMaritalStatus == "Single" || mMaritalStatus == "Divorced";
}

std::string Client::getCode() const {
    return mCode;  
}
void Client::setAge(int newAge) {
    mAge = newAge;
}

int Client::getAge() const {
    return mAge;
}
