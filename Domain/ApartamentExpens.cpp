//
// Created by sando on 13/04/2022.
//

#include "ApartamentExpens.h"

ApartmentExpense::ApartmentExpense() {
    this->apartmentNumber = -1;
    this->sum = 0;
    this->type = new char[0];
    strcpy(this->type, (char*)"");
}

ApartmentExpense::ApartmentExpense(unsigned int apartmentNumber, unsigned int sum, char *type) {
    this->apartmentNumber = apartmentNumber;
    this->sum = sum;
    this->type = new char[strlen(type) + 1];
    strcpy(this->type, type);
}

ApartmentExpense::ApartmentExpense(const ApartmentExpense &other) {
    this->apartmentNumber = other.apartmentNumber;
    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);
    this->sum = other.sum;
}

unsigned int ApartmentExpense::getApartmentNumber() const {
    return this->apartmentNumber;
}

void ApartmentExpense::setApartmentNumber(unsigned int id) {
    this->apartmentNumber = id;
}

std::ostream &operator<<(std::ostream &os, const ApartmentExpense &entity) {
    os << "Apartment expense for apartment number " << entity.apartmentNumber << ": " << entity.sum << " lei - for "
       << entity.type;
    return os;
}

ApartmentExpense::~ApartmentExpense() {
    delete[] this->type;
    this->type = nullptr;
}

std::istream& operator>>(std::istream& is, ApartmentExpense& entity) {
    unsigned int apartmentNumber, sum;
    char* type = new char[strlen(entity.getType()) + 1];
    std::cout << "ApartmentExpense number: ";
    is >> apartmentNumber;
    std::cout << "ApartmentExpense sum: ";
    is >> sum;
    std::cout << R"(ApartmentExpense type from ["water", "electricity", "gas", "warmth", "other"]: )";
    is >> type;
    if (std::find(entity.types.cbegin(), entity.types.cend(), type) != entity.types.cend()) {
        entity.setApartmentNumber(apartmentNumber);
        entity.setSum(sum);
        entity.setType(type);
    } else {
        throw std::invalid_argument("Invalid type. Use types from: water, electricity, gas, warmth, other");
    }
    delete[] type;
    return is;
}

void ApartmentExpense::setSum(unsigned int _sum) {
    this->sum = _sum;
}

void ApartmentExpense::setType(char *_type) {
    if (std::find(this->types.cbegin(), this->types.cend(), _type) != this->types.cend()) {
        delete[] this->type;
        this->type = new char[strlen(_type) + 1];
        strcpy(this->type, _type);
    } else {
        throw std::invalid_argument("Invalid type. Use types from: water, electricity, gas, warmth, other");
    }
}

unsigned int ApartmentExpense::getSum() const {
    return this->sum;
}

char *ApartmentExpense::getType() const {
    return this->type;
}

ApartmentExpense &ApartmentExpense::operator=(const ApartmentExpense &other) {
    this->apartmentNumber = other.apartmentNumber;
    this->sum = other.sum;
    delete[] this->type;
    this->type = new char[strlen(other.type) + 1];
    strcpy(this->type, other.type);
    return *this;
}

bool operator==(const ApartmentExpense &lhs, const ApartmentExpense &rhs) {
    return lhs.getApartmentNumber() == rhs.getApartmentNumber() && lhs.getSum() == rhs.getSum() &&
           strcmp(lhs.getType(), rhs.getType()) == 0;
}

bool operator<(const ApartmentExpense &lhs, const ApartmentExpense &rhs) {
    return lhs.getSum() < rhs.getSum();
}