//
// Created by sando on 13/04/2022.
//

#include "random"
#include "D:\c++ facultati\lab 78\Domain\Vector.h"
#include "D:\c++ facultati\lab 78\Domain\ApartamentExpens.h"
#ifndef LAB_78_REPOSITORY_H
#define LAB_78_REPOSITORY_H

template <class T> class EntityRepository {
private:
    EntityVector<T> entities;
    /**
     * Find index of entity in the vector
     * @param entity: An entity to find
     * @return the index if found, -1 otherwise
     */
    int findIndex(T entity) {
        for (int i = 0; i < entities.getSize(); i++) {
            if (entities[i] == entity) {
                return i;
            }
        }
        return -1;
    }
public:
    /**
     * Destructor
     */
    ~EntityRepository() = default;

    /**
     * Default Constructor, initializes the vector as empty.
     */
    EntityRepository() {
        this->entities = EntityVector<T>();
    }

    /**
     * Constructor, initializes the repository with a vector of entities from other repository.
     * @param other a repository
     */
    EntityRepository(const EntityRepository &other) {
        this->entities = other.entities;
    }

    /**
     * Constructor, initializes the repository with a vector of entities from a given vector.
     * @param other a vector
     */
    explicit EntityRepository(const EntityVector<T> &other) {
        this->entities = other;
    }

    /**
     * Constructor, initializes the repository with an empty vector, but with a given capacity.
     * @param capacity
     */
    explicit EntityRepository(int capacity) {
        this->entities = EntityVector<T>(capacity);
    }

    /**
     * Add an entity to the repository.
     * @param entity: An entity to add
     */
    void addElem(T entity) {
        this->entities.push_back(entity);
    }

    /**
     * Remove an entity from the repository.
     * @param entity: An entity to remove
     */
    void remove(T entity) {
        int index = this->findIndex(entity);
        if (index != -1) {
            this->entities.erase(index);
        }
    }

    /**
     * Edits an entity. (update)
     * @param entity: An entity to edit
     * @param newEntity: An entity with the new values
     */
    void edit (T entity, T newEntity) {
        int index = this->findIndex(entity);
        entities.erase(index);
        entities.insert(index, newEntity);
    }

    /**
     * Gets all entities from the repository.
     * @return all entities from the repository
     */
    EntityVector<T> getAll() {
        return this->entities;
    }

    /**
     * Gets size of the vector from repository. (number of entities)
     * @return the number of entities in the repository
     */
    int getSize() {
        return this->entities.getSize();
    }

    /**
     * Gets capacity of the vector from repository.
     * @return the capacity of Entity Vector.
     */
    int getCapacity() {
        return this->entities.getCapacity();
    }

    /**
     * Deletes all entities.
     */
    void deleteAll() {
        this->entities.clear();
    }

    /**
     * Assigns a given vector to the repository.
     * @param newVector a vector
     */
    void setAll(EntityVector<T> newVector) {
        this->entities = newVector;
    }
};

#endif //LAB_78_REPOSITORY_H
