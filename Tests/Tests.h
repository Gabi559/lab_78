//
// Created by sando on 13/04/2022.
//

#ifndef LAB_78_TESTS_H
#define LAB_78_TESTS_H
#include <cassert>
#include <chrono>
#include <thread>
#include "D:\c++ facultati\lab 78\Domain\ApartamentExpens.h"
#include "D:\c++ facultati\lab 78\Repository\Repository.h"
#include "D:\c++ facultati\lab 78\Service\ServiceApartamen.h"
class Test {
public:
    /**
     * Tests the EntityRepository class
     */
    static void testRepository() {
        EntityRepository<ApartmentExpense> repo;
        assert(repo.getSize() == 0);
        assert(repo.getAll().getSize() == 0);
        repo.addElem(ApartmentExpense(1, 200, (char*)"water"));
        assert(repo.getSize() == 1);
        assert(repo.getAll().getSize() == 1);
        assert(repo.getCapacity() == 10);
        repo.addElem(ApartmentExpense(2, 3000, (char*)"electricity"));
        assert(repo.getSize() == 2);
        assert(repo.getAll().getSize() == 2);
        assert(repo.getCapacity() == 10);
        EntityRepository<ApartmentExpense> repo2(repo);
        assert(repo2.getSize() == 2);
        assert(repo2.getAll().getSize() == 2);
        assert(repo2.getCapacity() == 10);
        repo2.addElem(ApartmentExpense(3, 400, (char*)"water"));
        assert(repo2.getSize() == 3);
        assert(repo2.getAll().getSize() == 3);
        assert(repo2.getCapacity() == 10);
    }

    /**
     * Tests the ApartmentService class
     */
    static void testService() {
        ApartmentService service;
        assert(service.getAll().getSize() == 0);
        service.add(ApartmentExpense(1, 200, (char*)"water"));
        assert(service.getAll().getSize() == 1);
        service.add(ApartmentExpense(2, 3000, (char*)"electricity"));
        assert(service.getAll().getSize() == 2);
        service.add(ApartmentExpense(3, 400, (char*)"water"));
        assert(service.getAll().getSize() == 3);
        service.remove(1);
        assert(service.getAll().getSize() == 2);
        service.remove((char*)"water");
        assert(service.getAll().getSize() == 1);
        service.remove((char*)"electricity");
        assert(service.getAll().getSize() == 0);
        service.add(ApartmentExpense(1, 200, (char*)"water"));
        service.add(ApartmentExpense(2, 3000, (char*)"electricity"));
        service.add(ApartmentExpense(3, 400, (char*)"water"));
        service.add(ApartmentExpense(3, 400, (char*)"gas"));
        assert(service.getAll().getSize() == 4);
        service.remove(3, (char*)"water");
        assert(service.getAll().getSize() == 3);
        service.remove(1, 2);
        assert(service.getAll().getSize() == 1);
        service.deleteAll();
        service.add(ApartmentExpense(1, 200, (char*)"water"));
        service.add(ApartmentExpense(2, 3000, (char*)"electricity"));
        service.add(ApartmentExpense(3, 400, (char*)"water"));
        service.add(ApartmentExpense(3, 300, (char*)"gas"));
        assert(service.getAll().getSize() == 4);
        assert(strcmp(service.get(1)[0].getType(), "water") == 0);
        service.edit(1, (char*)"water", 300);
        assert(service.get(1)[0].getSum() == 300);
        assert(service.get(2)[0].getSum() == 3000);
        service.edit(2, (char*)"electricity", 300);
        assert(service.get(2)[0].getSum() == 300);
        assert(service.get(1).getSize() == 1);
        assert(service.get(3).getSize() == 2);
        assert(service.getMax((char*)"electricity") == ApartmentExpense(2, 300, (char*)"electricity"));
        assert(service.getMax(3) == ApartmentExpense(3, 400, (char*)"water"));
        assert(service.getMax(3, (char*)"gas") == ApartmentExpense(3, 300, (char*)"gas"));
        assert(service.sum((char*)"water") == 700);
        assert(service.sum(3) == 700);
        assert(service.sum(3, (char*)"gas") == 300);
        assert(service.sort((char*)"water")[0].getSum() == 400);
        assert(service.sort((char*)"water")[1].getSum() == 300);
        service.filter(301);
        assert(service.getAll().getSize() == 3);
        service.filter((char*)"water");
        assert(service.getAll().getSize() == 1);
        service.deleteAll();
        service.generate(156);
        assert(service.getAll().getSize() == 156);
        service.deleteAll();
        assert(service.getAll().getSize() == 0);
        service.undo();
        assert(service.getAll().getSize() == 156);
        service.deleteAll();
    }

    /**
     * Tests the ApartmentExpense class.
     */
    static void testEntity() {
        ApartmentExpense entity;
        assert(entity.getApartmentNumber() == -1);
        assert(strcmp(entity.getType(), "") == 0);
        assert(entity.getSum() == 0);
        entity.setApartmentNumber(2);
        entity.setSum(300);
        entity.setType((char*)"water");
        assert(entity.getApartmentNumber() == 2);
        assert(entity.getSum() == 300);
        assert(strcmp(entity.getType(), "water") == 0);
        entity.setSum(400);
        entity.setApartmentNumber(3);
        entity.setType((char*)"electricity");
        assert(entity.getApartmentNumber() == 3);
        assert(entity.getSum() == 400);
        assert(strcmp(entity.getType(), "electricity") == 0);
    }

    /**
     * Tests EntityVector class.
     */
    static void testEntityVector() {
        EntityVector<int> vector;
        assert(vector.getSize() == 0);
        vector.push_back(1);
        assert(vector.getSize() == 1);
        vector.push_back(2);
        assert(vector.getSize() == 2);
        vector.push_back(3);
        assert(vector.getSize() == 3);
        int a = vector.pop_back();
        assert(vector.getSize() == 2);
        assert(a == 3);
        vector.insert(1, 4);
        assert(vector.getSize() == 3);
        vector.erase(1);
        assert(vector.getSize() == 2);
        vector.erase(0);
        assert(vector.getSize() == 1);
        vector.erase(0);
        assert(vector.getSize() == 0);
        vector.push_back(1);
        vector.push_back(2);
        vector.push_back(3);
        vector.push_back(4);
        vector.push_back(5);
        EntityVector<int> vector2 = vector;
        assert(vector2.getSize() == 5);
        vector.clear();
        assert(vector.getSize() == 0);
        assert(vector2.getSize() == 5);
        vector2.clear();
        assert(vector2.getSize() == 0);
    }

    /**
     * Calls all the tests.
     */
    static void testAll() {
        std::cout << "Running tests..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        Test::testEntity();
        Test::testEntityVector();
        Test::testRepository();
        Test::testService();

        std::cout << "Tests passed!" << std::endl;
    }
};
#endif //LAB_78_TESTS_H
