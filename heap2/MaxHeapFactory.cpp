//
// Created by lemon on 6/5/25.
//

#include "MaxHeapFactory.h"
#include "MaxHeap1.h"

MaxHeap* MaxHeapFactory::createMaxHeap(vector<int>& arr) {
    return new MaxHeap1(arr);
}

void MaxHeapFactory::deleteMaxHeap(MaxHeap* obj) {
    delete obj;
}
