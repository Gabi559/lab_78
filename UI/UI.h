//
// Created by sando on 13/04/2022.
//

#ifndef LAB_78_UI_H
#define LAB_78_UI_H

#include <iostream>
#include <string>
#include <sstream>
#include "D:\c++ facultati\lab 78\Domain\ApartamentExpens.h"
#include "D:\c++ facultati\lab 78\Tests\Tests.h"
#include "D:\c++ facultati\lab 78\Service\ServiceApartamen.h"
class UserInterface {
private:
    ApartmentService apartmentService;
public:
    /**
     * Constructor
     */
    UserInterface();

    /**
     * Runs the user interface.
     */
    void run();

    /**
     * Prints the menu.
     */
    static void printMenu();

    /**
     * Runs commands.
     * @param i input
     */
    void runCommand(std::string i);

    /**
     * splits string s into a vector of strings based on delimiter.
     * @param s a string
     * @param delimiter a delimiter.
     * @return returns a vector of strings.
     */
    std::vector<std::string> split(const std::string& s, char delimiter);

    /**
     * Handles add command.
     * @param args arguments
     */
    void handleAddExpense(std::vector<std::string> args);

    /**
     * Handles delete command.
     * @param args arguments
     */
    void handleDeleteExpense(std::vector<std::string> args);

    /**
     * Handles update command.
     * @param args arguments
     */
    void handleEditExpense(std::vector<std::string> args);

    /**
     * Handles list (output) command.
     * @param args arguments
     */
    void handlePrintExpenses(std::vector<std::string> args);

    /**
     * Handles sum command.
     * @param args arguments
     */
    void handleSumExpenses(std::vector<std::string> args);

    /**
     * Handles max command.
     * @param args arguments
     */
    void handleMaxExpense(std::vector<std::string> args);

    /**
     * Handles sort command.
     * @param args arguments
     */
    void handleSortExpenses(std::vector<std::string> args);

    /**
     * Handles filter command.
     * @param args arguments
     */
    void handleFilterExpenses(std::vector<std::string> args);

    /**
     * Handles undo command.
     */
    void handleUndo();

    /**
     * Checks to see if a string is a number.
     * @param s a string
     * @return true if s is a number, false otherwise.
     */
    bool isNumber(std::string s);

    /**
     * Handles generate command.
     * @param args arguments.
     */
    void handleGenerateEntries(std::vector<std::string> args);
};

#endif //LAB_78_UI_H
