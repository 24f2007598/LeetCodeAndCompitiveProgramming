//
// Created by lemon on 6/5/25.
//

#ifndef MAXHEAPFACTORY_H
#define MAXHEAPFACTORY_H
#include "MaxHeap.h"
#include <vector>

using namespace std;

class MaxHeapFactory {
private:
    MaxHeapFactory() = default;
public:
    static MaxHeap* createMaxHeap(vector<int>& arr);
    static void deleteMaxHeap(MaxHeap* obj);
};

#endif //MAXHEAPFACTORY_H
