#ifndef UNTITLED_ARCHETYPE_H
#define UNTITLED_ARCHETYPE_H

#include <cstddef>
#include <vector>

using namespace std;

class Archetype {
    vector<size_t> typeHashes;

public:
    Archetype(vector<size_t> typeHashes) { this->typeHashes = typeHashes; }
    vector<size_t> TypesHashes() { return typeHashes; }
};

#endif