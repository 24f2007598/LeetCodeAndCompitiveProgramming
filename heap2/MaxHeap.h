//
// Created by lemon on 6/5/25.
//

#ifndef MAXHEAP_H
#define MAXHEAP_H

class MaxHeap {
protected:
    MaxHeap() {}
    virtual ~MaxHeap() {}
public:
    virtual MaxHeap& insert(int k) {return *this;}
    virtual int max() {return -1;}
    virtual int maxK(int k) {return -1;}
    virtual MaxHeap& print() {return *this;}

    friend class MaxHeapFactory;
};

#endif //MAXHEAP_H
