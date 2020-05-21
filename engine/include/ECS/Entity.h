#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H

class Entity {
    friend class EntityManager;

    int id;
    int version;

public:
    int Id() const { return id; }
    int Version() const { return version; }

    Entity(const int id, const int version = 0) : id(id), version(version) { }
};

#endif