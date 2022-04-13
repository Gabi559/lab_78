//
// Created by sando on 13/04/2022.
//

#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

#ifndef LAB_78_APARTAMENTEXPENS_H
#define LAB_78_APARTAMENTEXPENS_H
class ApartmentExpense {
private:
    unsigned int apartmentNumber;
    unsigned int sum;
    char* type;
    const std::vector<std::string> types = {"water", "electricity", "gas", "warmth", "other"};
public:
    /**
     * Constructor
     */
    ApartmentExpense();

    /**
     * Constructor
     * @param apartmentNumber - apartment number
     * @param sum - sum of taxes
     * @param type - type of tax
     */
    explicit ApartmentExpense(unsigned int apartmentNumber, unsigned int sum, char *type);

    /**
     * Copy constructor
     * @param other the object to copy
     */
    ApartmentExpense(const ApartmentExpense& other);

    /**
     * Destructor
     */
    ~ApartmentExpense();

    /**
     * Setter for id
     * @param id the id to set
     */
    void setApartmentNumber(unsigned int id);

    /**
     * Setter for sum
     * @param sum a given sum
     */
    void setSum(unsigned int sum);

    /**
     * Setter for type
     * @param type a given type
     */
    void setType(char* type);

    /**
     * Getter for id
     * @return the id
     */
    unsigned int getApartmentNumber() const;

    /**
     * Getter for sum
     * @return the sum
     */
    unsigned int getSum() const;

    /**
     * Getter for type
     * @return the type
     */
    char* getType() const;

    /**
     * Overload of the operator <<
     * @param os the output stream
     * @param entity the entity to print
     * @return the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const ApartmentExpense& entity);

    /**
     * Overload of the operator >>
     * @param is the input stream
     * @param entity the other entity
     * @return the input stream
     */
    friend std::istream& operator>>(std::istream& is, ApartmentExpense& entity);

    /**
     * Overload of the operator =
     * @param other the other entity
     * @return the entity
     */
    ApartmentExpense &operator=(const ApartmentExpense &other);

    /**
     * Overload of the operator ==
     * @param other the other entity
     * @return true if the entities are equal
     */
    friend bool operator==(const ApartmentExpense &lhs, const ApartmentExpense &rhs);

    /**
     * Overload of the operator <
     * @param other the other entity
     * @return true if the first entity is less than the second
     */
    friend bool operator<(const ApartmentExpense &lhs, const ApartmentExpense &rhs);
};

#endif //LAB_78_APARTAMENTEXPENS_H
