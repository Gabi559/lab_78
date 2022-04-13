//
// Created by sando on 13/04/2022.
//

#ifndef LAB_78_SERVICEAPARTAMEN_H
#define LAB_78_SERVICEAPARTAMEN_H

#include "D:\c++ facultati\lab 78\Repository\Repository.h"
#include "D:\c++ facultati\lab 78\Domain\ApartamentExpens.h"
class ApartmentService {
private:
    EntityRepository<ApartmentExpense> repository;
    EntityVector<ApartmentExpense> previousState;
public:
    /**
     * Default constructor
     */
    ApartmentService();

    /**
     * Constructor, initializes the repository with a given repository.
     * @param repository
     */
    explicit ApartmentService(EntityRepository<ApartmentExpense> repository);

    /**
     * Constructor, initializes class with a given same-type class.
     * @param apartmentService an apartmentService object
     */
    explicit ApartmentService(const ApartmentService& apartmentService);

    /**
     * Adds an entity to repository.
     * @param entity an entity.
     */
    void add(ApartmentExpense entity);

    /**
     * Removes entities from repository with corresponding apartment number.
     * @param apartmentNumber entity's apartment number
     */
    void remove(unsigned int apartmentNumber);

    /**
     * Removes entities from repository wih corresponding apartment number and expense type.
     * @param apartmentNumber entity's apartment number
     * @param type entity's expense type
     */
    void remove(unsigned int apartmentNumber, char* type);

    /**
     * Removes all entities from repository with corresponding expense type.
     * @param type entity's expense type.
     */
    void remove(char* type);

    /**
     * Removes all entities with apartment number between given ones.
     * @param apartmentNumberBegin apartment number to begin with.
     * @param apartmentNumberEnd apartment number to end with.
     */
    void remove(unsigned int apartmentNumberBegin, unsigned int apartmentNumberEnd);

    /**
     * Gets all apartment numbers.
     * @return all available apartment numbers.
     */
    EntityVector<unsigned int> getApartmentNumbers();

    /**
     * Gets all entities with corresponding apartment number.
     * @param apartmentNumber entity's apartment number
     * @return
     */
    EntityVector<ApartmentExpense> get(unsigned int apartmentNumber);

    /**
     * Gets all entities with corresponding apartment number between given ones.
     * @param apartmentNumberBegin apartment number to begin with.
     * @param apartmentNumberEnd apartment number to end with
     * @return
     */
    EntityVector<ApartmentExpense> get(unsigned int apartmentNumberBegin, unsigned int apartmentNumberEnd);

    /**
     * Gets all entities with a given filter type (>, >=, <, <=, =, !=).
     * @param filterType a given filter type (>, >=, <, <=, =, !=).
     * @param filterValue a given filter value.
     * @return returns a vector of filtered apartment expenses.
     */
    EntityVector<ApartmentExpense> get(char* filterType, int filterValue);

    /**
     * Gets all entities corresponding to given type.
     * @param type an apartment expense type.
     * @return
     */
    EntityVector<ApartmentExpense> get(char* type);

    /**
     * Gets all entities with corresponding apartment number and expense type.
     * @param apartmentNumber apartment number.
     * @param type expense type.
     * @return returns a vector with corresponding apartment expenses.
     */
    EntityVector<ApartmentExpense> get(unsigned int apartmentNumber, char* type);

    /**
     * Gets previous vector state.
     * @return previous vector state.
     */
    EntityVector<ApartmentExpense> getPreviousState();

    /**
     * Edits the sum for all expenses with corresponding apartment number and a given expense type.
     * @param apartmentNumber an apartment number.
     * @param typeToEdit an expense type.
     * @param newValue new sum for corresponding expense type.
     */
    void edit(unsigned int apartmentNumber, char* typeToEdit, int newValue);

    /**
     * Returns the sum of all expenses with corresponding apartment number and a given expense type.
     * @param apartmentNumber an apartment number.
     * @param type an expense type.
     * @return return the sum of all expenses with corresponding apartment number and a given expense type.
     */
    unsigned int sum(unsigned int apartmentNumber, char* type);

    /**
     * Return the sum of all expenses with corresponding apartment number.
     * @param apartmentNumber an apartment number.
     * @return the sum of all expenses with corresponding apartment number.
     */
    unsigned int sum(unsigned int apartmentNumber);

    /**
     * Returns the sum of all expenses with corresponding given expense type.
     * @param type an expense type.
     * @return returns the sum of all expenses for a given expense type.
     */
    unsigned int sum(char* type);

    /**
     * Gets max value for a given expense type.
     * @param type an expense type.
     * @return max value for a given expense type.
     */
    ApartmentExpense getMax(char* type);

    /**
     * Gets max value for a given apartment number and expense type.
     * @param apartmentNumber an apartment number.
     * @param type an expense type.
     * @return max value for a given expense type.
     */
    ApartmentExpense getMax(unsigned int apartmentNumber, char* type);

    /**
     * Gets max value for a given apartment number.
     * @param apartmentNumber an apartment number.
     * @return max value for a given apartment number.
     */
    ApartmentExpense getMax(unsigned int apartmentNumber);

    /**
     * Gets all apartment expenses.
     * @return a vector of all apartment expenses.
     */
    EntityVector<ApartmentExpense> getAll();

    /**
     * Generates apartment expenses.
     * @param numberOfGenerations the number of apartment expenses to generate.
     */
    void generate(int numberOfGenerations);

    /**
     * Sorts apartment expenses descending for a given expense type. (doesn't modify the vector)
     * @param type an expense type.
     * @return sorted vector of apartment expenses.
     */
    EntityVector<ApartmentExpense> sort(char* type);

    /**
     * Filters all apartment expenses and removes all expenses that doesn't correspond to given expense type.
     * @param type an expense type.
     */
    void filter(char* type);

    /**
     * Filters all apartment expenses and removes all expenses that are greater or equal to given value.
     * @param sum a given value.
     */
    void filter(int sum);

    /**
     * Deletes all apartment expenses.
     */
    void deleteAll();

    /**
     * Undoes vector to previous state.
     */
    void undo();
};

#endif //LAB_78_SERVICEAPARTAMEN_H
