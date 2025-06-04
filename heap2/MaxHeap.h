//
// Created by lemon on 6/4/25.
//

#ifndef MAXHEAP_H
#define MAXHEAP_H

// #include <stdio.h>
// #include <iostream>
// #include <algorithm>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    void heapifyUp(int k);
    void heapifyDown(int k);
    void build(vector<int>& arr);

public:
    MaxHeap(vector<int>& arr);
    void insert(int k);
    int max();
    int maxK(int k);
    void print();
};

#endif //MAXHEAP_H
