#ifndef UNTITLED_COMMON_H
#define UNTITLED_COMMON_H

#include <cstddef>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <thread>

using namespace std;

inline int type_id_seq = 0;
template< typename > inline const int type_id = type_id_seq++;

#endif