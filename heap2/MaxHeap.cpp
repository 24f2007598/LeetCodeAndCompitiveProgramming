//
// Created by lemon on 6/4/25.
//
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "MaxHeap.h"

using namespace std;

MaxHeap::MaxHeap(vector<int>& arr) {
    build(arr);
}

void MaxHeap::build(vector<int> &arr) {
    heap.clear();
    heap.resize(arr.size());
    for (int i : arr) insert(i);
}

void MaxHeap::insert(int dat) {
    if (heap.size() == 0) {
        heap.push_back(dat);
        return;
    }
    heap.push_back(dat);
    heapifyUp(heap.size() - 1);
}

int MaxHeap::maxK(int k) {
    int max;
    while (k-- > 0) max = this->max();
    return max;
}

int MaxHeap::max() {
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

void MaxHeap::heapifyUp(int k) {
    int parent = (k - 1) / 2;
    if (heap[parent] <= heap[k]) {
        swap(heap[k], heap[parent]);
    }
    if (parent == 0) {
        return;
    }
    heapifyUp(parent);
}

void MaxHeap::heapifyDown(int k) {
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

void MaxHeap::print() {
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

