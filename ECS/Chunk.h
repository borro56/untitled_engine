#ifndef UNTITLED_CHUNK_H
#define UNTITLED_CHUNK_H

const int CHUNK_SIZE = 16384;

class Chunk
{
    int sizeOfEntity;
    int amount;
    unsigned char data[CHUNK_SIZE];

public:
    template<class... Types>
    void AddData(Types const&... data);

    int BytesCount() { return sizeOfEntity * amount; }
    int RemainingBytes() { return CHUNK_SIZE - BytesCount(); }

    Chunk(int sizeOfEntity) { this->sizeOfEntity = sizeOfEntity; }
};

#include "Chunk.tpp"

#endif