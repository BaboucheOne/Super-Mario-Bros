#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <iostream>
#include <vector>

#include "GameObject.h"

using namespace std;

struct Chunk {
    int ID;
    int x;
    int y;
    vector <GameObject> gameobject;
};

#endif // GLOBAL_H_
