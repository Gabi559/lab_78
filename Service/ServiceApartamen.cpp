//
// Created by sando on 13/04/2022.
//

#include "ServiceApartamen.h"
#include <set>
ApartmentService::ApartmentService(EntityRepository<ApartmentExpense> repository) {
    this->previousState = EntityVector<ApartmentExpense>();
    this->repository = repository;
}

void ApartmentService::add(ApartmentExpense entity) {
    this->previousState = this->repository.getAll();
    this->repository.addElem(entity);
}

void ApartmentService::remove(unsigned int apartmentNumber) {

    EntityVector<ApartmentExpense> expenses = this->get(apartmentNumber);
    for (int i = 0; i < expenses.getSize(); i++) {
        if (i >= 0 && i < expenses.getSize()) {
            this->previousState = this->repository.getAll();
        }
        this->repository.remove(expenses[i]);
    }
}

EntityVector<ApartmentExpense> ApartmentService::getAll() {
    EntityVector<ApartmentExpense> apartments = this->repository.getAll();
    return apartments;
}

ApartmentService::ApartmentService() {
    this->previousState = EntityVector<ApartmentExpense>();
    this->repository = EntityRepository<ApartmentExpense>();
}

void ApartmentService::generate(int numberOfGenerations) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 100.0);
    std::vector<std::string> allowedTypes = {"water", "electricity", "gas", "warmth", "other"};
    this->previousState = this->repository.getAll();
    for (int i = 0; i < numberOfGenerations; i++) {
        this->repository.addElem(ApartmentExpense(
                floor(dist(mt)),
                floor(dist(mt)),
                (char*)allowedTypes.at(floor(rand() % allowedTypes.size() - 1)).c_str())
        );
    }
}

EntityVector<ApartmentExpense> ApartmentService::get(unsigned int apartmentNumber) {
    EntityVector<ApartmentExpense> apartments = this->repository.getAll();
    EntityVector<ApartmentExpense> correspondingApartments;
    for (int i = 0; i < apartments.getSize(); i++) {
        if (apartments[i].getApartmentNumber() == apartmentNumber) {
            correspondingApartments.push_back(apartments[i]);
        }
    }
    return correspondingApartments;
}

void ApartmentService::remove(unsigned int apartmentNumber, char *type) {
    if (strcmp(type, "water") != 0 && strcmp(type, "electricity") != 0 && strcmp(type, "gas") != 0 && strcmp(type, "warmth") != 0 && strcmp(type, "other") != 0) {
        throw std::invalid_argument("Invalid type! Please use one of the following: water, electricity, gas, warmth, other");
    }
    EntityVector<ApartmentExpense> expenses = this->get(apartmentNumber);
    for (int i = 0; i < expenses.getSize(); i++) {
        if (strcmp(expenses[i].getType(), type) == 0) {
            this->previousState = this->repository.getAll();
            this->repository.remove(expenses[i]);
        }
    }
}

void ApartmentService::remove(char *type) {
    if (strcmp(type, "water") != 0 && strcmp(type, "electricity") != 0 && strcmp(type, "gas") != 0 && strcmp(type, "warmth") != 0 && strcmp(type, "other") != 0) {
        throw std::invalid_argument("Invalid type! Please use one of the following: water, electricity, gas, warmth, other");
    }
    EntityVector<ApartmentExpense> expenses = this->repository.getAll();
    for (int i = 0; i < expenses.getSize(); i++) {
        if (strcmp(expenses[i].getType(), type) == 0) {
            this->previousState = this->repository.getAll();
            this->repository.remove(expenses[i]);
        }
    }
}

void ApartmentService::remove(unsigned int apartmentNumberBegin, unsigned int apartmentNumberEnd) {
    EntityVector<ApartmentExpense> expenses = this->get(apartmentNumberBegin, apartmentNumberEnd);
    for (int i = 0; i < expenses.getSize(); i++) {
        if (expenses[i].getApartmentNumber() >= apartmentNumberBegin && expenses[i].getApartmentNumber() <= apartmentNumberEnd) {
            this->previousState = this->repository.getAll();
            this->repository.remove(expenses[i]);
        }
    }
}

void ApartmentService::edit(unsigned int apartmentNumber, char *typeToEdit, int newValue) {
    EntityVector<ApartmentExpense> expenses = this->get(apartmentNumber, typeToEdit);
    if(expenses.getSize() > 0) {
        this->previousState = this->repository.getAll();
    }
    for (int i = 0; i < expenses.getSize(); i++) {
        ApartmentExpense newExpense = expenses[i];
        newExpense.setSum(newValue);
        this->repository.edit(expenses[i], newExpense);
    }
}

EntityVector<ApartmentExpense> ApartmentService::get(char *filterType, int filterValue) {
    EntityVector<ApartmentExpense> expenses = this->repository.getAll();
    EntityVector<ApartmentExpense> filteredApartments;
    for (int i = 0; i < expenses.getSize(); i++) {
        if (strcmp(filterType, (char*) ">") == 0) {
            if (expenses[i].getSum() > filterValue) {
                filteredApartments.push_back(expenses[i]);
            }
        } else if (strcmp(filterType, (char*) "<") == 0) {
            if (expenses[i].getSum() < filterValue) {
                filteredApartments.push_back(expenses[i]);
            }
        } else if (strcmp(filterType, (char*) ">=") == 0) {
            if (expenses[i].getSum() >= filterValue) {
                filteredApartments.push_back(expenses[i]);
            }
        } else  if (strcmp(filterType, (char*) "<=") == 0) {
            if (expenses[i].getSum() <= filterValue) {
                filteredApartments.push_back(expenses[i]);
            }
        } else if (strcmp(filterType, (char*) "=") == 0) {
            if (expenses[i].getSum() == filterValue) {
                filteredApartments.push_back(expenses[i]);
            }
        } else if (strcmp(filterType, (char*) "!=") == 0) {
            if (expenses[i].getSum() != filterValue) {
                filteredApartments.push_back(expenses[i]);
            }
        } else {
            throw std::invalid_argument("Invalid filter type! Please use one of the following: >, <, >=, <=, =");
        }
    }
    return filteredApartments;
}

void ApartmentService::deleteAll() {
    this->previousState = this->repository.getAll();
    this->repository.deleteAll();
}

unsigned int ApartmentService::sum(unsigned int apartmentNumber, char *type) {
    if (strcmp(type, "water") != 0 && strcmp(type, "electricity") != 0 && strcmp(type, "gas") != 0 && strcmp(type, "warmth") != 0 && strcmp(type, "other") != 0) {
        throw std::invalid_argument("Invalid type! Please use one of the following: water, electricity, gas, warmth, other");
    }
    EntityVector<ApartmentExpense> apartments = this->get(apartmentNumber);
    unsigned int sum = 0;
    for (int i = 0; i < apartments.getSize(); i++) {
        if (strcmp(apartments[i].getType(), type) == 0) {
            sum += apartments[i].getSum();
        }
    }
    return sum;
}

unsigned int ApartmentService::sum(unsigned int apartmentNumber) {
    EntityVector<ApartmentExpense> apartments = this->get(apartmentNumber);
    unsigned int sum = 0;
    for (int i = 0; i < apartments.getSize(); i++) {
        sum += apartments[i].getSum();
    }
    return sum;
}

unsigned int ApartmentService::sum(char *type) {
    if (strcmp(type, "water") != 0 && strcmp(type, "electricity") != 0 && strcmp(type, "gas") != 0 && strcmp(type, "warmth") != 0 && strcmp(type, "other") != 0) {
        throw std::invalid_argument("Invalid type! Please use one of the following: water, electricity, gas, warmth, other");
    }
    EntityVector<ApartmentExpense> apartments = this->getAll();
    unsigned int sum = 0;
    for (int i = 0; i < apartments.getSize(); i++) {
        if(strcmp(apartments[i].getType(), type) == 0) {
            sum += apartments[i].getSum();
        }
    }
    return sum;
}

ApartmentExpense ApartmentService::getMax(char *type) {
    if (strcmp(type, "water") != 0 && strcmp(type, "electricity") != 0 && strcmp(type, "gas") != 0 && strcmp(type, "warmth") != 0 && strcmp(type, "other") != 0) {
        throw std::invalid_argument("Invalid type! Please use one of the following: water, electricity, gas, warmth, other");
    }
    ApartmentExpense maxExpense;
    EntityVector<ApartmentExpense> apartments = this->getAll();
    for (int i = 0; i < apartments.getSize(); i++) {
        if (strcmp(apartments[i].getType(), type) == 0) {
            if (maxExpense < apartments[i]) {
                maxExpense = apartments[i];
            }
        }
    }
    return maxExpense;
}

ApartmentExpense ApartmentService::getMax(unsigned int apartmentNumber, char *type) {
    if (strcmp(type, "water") != 0 && strcmp(type, "electricity") != 0 && strcmp(type, "gas") != 0 && strcmp(type, "warmth") != 0 && strcmp(type, "other") != 0) {
        throw std::invalid_argument("Invalid type! Please use one of the following: water, electricity, gas, warmth, other");
    }
    ApartmentExpense maxExpense;
    EntityVector<ApartmentExpense> apartments = this->get(apartmentNumber);
    for (int i = 0; i < apartments.getSize(); i++) {
        if (strcmp(apartments[i].getType(), type) == 0) {
            if (maxExpense < apartments[i]) {
                maxExpense = apartments[i];
            }
        }
    }
    return maxExpense;
}

ApartmentExpense ApartmentService::getMax(unsigned int apartmentNumber) {
    ApartmentExpense maxExpense;
    EntityVector<ApartmentExpense> apartments = this->get(apartmentNumber);
    for (int i = 0; i < apartments.getSize(); i++) {
        if (maxExpense < apartments[i]) {
            maxExpense = apartments[i];
        }
    }
    return maxExpense;
}

EntityVector<ApartmentExpense> ApartmentService::sort(char *type) {
    if (strcmp(type, "water") != 0 && strcmp(type, "electricity") != 0 && strcmp(type, "gas") != 0 && strcmp(type, "warmth") != 0 && strcmp(type, "other") != 0) {
        throw std::invalid_argument("Invalid type! Please use one of the following: water, electricity, gas, warmth, other");
    }
    EntityVector<ApartmentExpense> apartments = this->get(type);
    for(int i = 1; i < apartments.getSize(); i++)
    {
        ApartmentExpense currApp = apartments[i];
        int currIndex = i;

        while(currApp < apartments[currIndex-1] && currIndex > 0)
        {
            int leftIndex = currIndex-1;
            ApartmentExpense leftApp = apartments[leftIndex];

            apartments[leftIndex] = currApp;
            apartments[currIndex] = leftApp;

            currIndex = leftIndex;
        }
    }
    EntityVector<ApartmentExpense> descendingApartments = apartments;
    for (int i = 0; i < apartments.getSize(); i++) {
        descendingApartments[i] = apartments[apartments.getSize() - i - 1];
    }
    if (!(this->repository.getAll() == descendingApartments)) {
        this->previousState = this->repository.getAll();
    }
    return descendingApartments;
}

EntityVector<ApartmentExpense> ApartmentService::get(char *type) {
    if (strcmp(type, "water") != 0 && strcmp(type, "electricity") != 0 && strcmp(type, "gas") != 0 && strcmp(type, "warmth") != 0 && strcmp(type, "other") != 0) {
        throw std::invalid_argument("Invalid type! Please use one of the following: water, electricity, gas, warmth, other");
    }
    EntityVector<ApartmentExpense> apartments = this->getAll();
    EntityVector<ApartmentExpense> filteredApartments;
    for (int i = 0; i < apartments.getSize(); i++) {
        if (strcmp(apartments[i].getType(), type) == 0) {
            filteredApartments.push_back(apartments[i]);
        }
    }
    return filteredApartments;
}

EntityVector<ApartmentExpense> ApartmentService::get(unsigned int apartmentNumber, char *type) {
    if (strcmp(type, "water") != 0 && strcmp(type, "electricity") != 0 && strcmp(type, "gas") != 0 && strcmp(type, "warmth") != 0 && strcmp(type, "other") != 0) {
        throw std::invalid_argument("Invalid type! Please use one of the following: water, electricity, gas, warmth, other");
    }
    EntityVector<ApartmentExpense> apartments = this->getAll();
    EntityVector<ApartmentExpense> filteredApartments;
    for (int i = 0; i < apartments.getSize(); i++) {
        if (strcmp(apartments[i].getType(), type) == 0 && apartments[i].getApartmentNumber() == apartmentNumber) {
            filteredApartments.push_back(apartments[i]);
        }
    }
    return filteredApartments;
}

void ApartmentService::filter(char *type) {
    EntityVector<ApartmentExpense> apartments = this->getAll();
    EntityRepository<ApartmentExpense> newApartments = this->repository;
    for (int i = 0; i < apartments.getSize(); i++) {
        if (strcmp(apartments[i].getType(), type) != 0) {
            newApartments.remove(apartments[i]);
        }
    }

    if (!(this->repository.getAll() == newApartments.getAll())) {
        this->previousState = this->repository.getAll();
        this->repository = newApartments;
    }
}

void ApartmentService::filter(int sum) {
    EntityVector<ApartmentExpense> apartments = this->getAll();
    EntityRepository<ApartmentExpense> newApartments = this->repository;
    for (int i = 0; i < apartments.getSize(); i++) {
        if(apartments[i].getSum() >= sum) {
            newApartments.remove(apartments[i]);
        }
    }

    if (!(this->repository.getAll() == newApartments.getAll())) {
        this->previousState = this->repository.getAll();
        this->repository = newApartments;
    }
}

EntityVector<unsigned int> ApartmentService::getApartmentNumbers() {
    EntityVector<ApartmentExpense> apartments = this->getAll();
    std::set<unsigned int> tempApartmentNumbers;
    for (int i = 0; i < apartments.getSize(); i++) {
        tempApartmentNumbers.insert(apartments[i].getApartmentNumber());
    }
    EntityVector<unsigned int> apartmentNumbers;
    while(!tempApartmentNumbers.empty()) {
        unsigned int apartmentNumber = *tempApartmentNumbers.begin();
        tempApartmentNumbers.erase(apartmentNumber);
        apartmentNumbers.push_back(apartmentNumber);
    }
    return apartmentNumbers;
}

EntityVector<ApartmentExpense> ApartmentService::getPreviousState() {
    return this->previousState;
}

EntityVector<ApartmentExpense>
ApartmentService::get(unsigned int apartmentNumberBegin, unsigned int apartmentNumberEnd) {
    EntityVector<ApartmentExpense> apartments = this->getAll();
    EntityVector<ApartmentExpense> filteredApartments;
    for (int i = 0; i < apartments.getSize(); i++) {
        if (apartments[i].getApartmentNumber() >= apartmentNumberBegin && apartments[i].getApartmentNumber() <= apartmentNumberEnd) {
            filteredApartments.push_back(apartments[i]);
        }
    }
    return filteredApartments;
}

void ApartmentService::undo() {
    if (!(this->previousState == EntityVector<ApartmentExpense>())) {
        this->repository.setAll(this->previousState);
        this->previousState = EntityVector<ApartmentExpense>();
    } else {
        throw std::out_of_range("No previous state!");
    }
}

ApartmentService::ApartmentService(const ApartmentService &apartmentService) {
    this->repository = apartmentService.repository;
    this->previousState = apartmentService.previousState;
}
