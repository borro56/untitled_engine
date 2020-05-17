#ifndef UNTITLED_COMMON_H
#define UNTITLED_COMMON_H

#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

template<class T> size_t typeHash() { return typeid(T).hash_code(); } //TODO: Use compile time hash

#endif