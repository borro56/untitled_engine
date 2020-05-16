#ifndef UNTITLED_CHUNK_H
#define UNTITLED_CHUNK_H

const int CHUNK_SIZE = 16384;

class Chunk
{
    int sizeOfEntity;
    int amount;

public:
    unsigned char data[CHUNK_SIZE];
    Chunk(int sizeOfEntity) { this->sizeOfEntity = sizeOfEntity; }
    int BytesCount() { return sizeOfEntity * amount; }
    int RemainingBytes() { return CHUNK_SIZE - BytesCount(); }

    template<class... Types>
    void AddData(Types const&... data);
};

#include "Chunk.tpp"

#endif