//
// Created by lemon on 6/4/25.
//

#ifndef MAXHEAP1_H
#define MAXHEAP1_H

// #include <stdio.h>
// #include <iostream>
// #include <algorithm>
#include <vector>
#include "MaxHeap.h"
using namespace std;

class MaxHeap1 :  public MaxHeap {
private:
    vector<int> heap;
    void heapifyUp(unsigned long k);
    void heapifyDown(int k);
    void build(vector<int>& arr);

public:
    explicit MaxHeap1(vector<int>& arr);
    MaxHeap1& insert(int k) override;
    int max() override;
    int maxK(int k) override;
    MaxHeap1& print() override;
};

#endif //MAXHEAP1_H
