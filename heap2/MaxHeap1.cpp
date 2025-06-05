//
// Created by lemon on 6/4/25.
//
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "MaxHeap1.h"

using namespace std;

MaxHeap1::MaxHeap1(vector<int>& arr) {
    build(arr);
}

void MaxHeap1::build(vector<int> &arr) {
    heap.clear();
    heap.resize(arr.size());
    for (int i : arr) insert(i);
}

MaxHeap1& MaxHeap1::insert(int dat) {
    heap.push_back(dat);
    if (heap.size() > 1) {
        heapifyUp(heap.size() - 1);
    }
    return *this;
}

int MaxHeap1::maxK(int k) {
    int max;
    while (k-- > 0) max = this->max();
    return max;
}

int MaxHeap1::max() {
    int max = heap[0];
    if (heap.size() == 1) {
        heap.erase(heap.end() - 1);
        return max;
    }
    swap(heap[0], heap[heap.size() - 1]);
    heap.erase(heap.end() - 1);
    heapifyDown(0);
    return max;
}

void MaxHeap1::heapifyUp(unsigned long k) {
    unsigned long parent = (k - 1) / 2;
    if (heap[parent] <= heap[k]) {
        swap(heap[k], heap[parent]);
    }
    if (parent > 0) {
        heapifyUp(parent);
    }
}

void MaxHeap1::heapifyDown(int k) {
    int largest = k, left = 2 * k + 1, right = left + 1;

    if (left < heap.size() && heap[left] >= heap[largest]) {
        largest = left;
    }
    if (right < heap.size() && heap[right] >= heap[largest]) {
        largest = right;
    }
    if (largest != k) {
        swap(heap[k], heap[largest]);
        heapifyDown(largest);
    }
}

MaxHeap1& MaxHeap1::print() {
    for (int i : heap) {
        cout << i << " ";
    }
    cout << endl;
    return *this;
}

