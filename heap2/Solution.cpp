//finding the kth largest element in an array using max heap

#include <vector>
#include "MaxHeapFactory.h"
#include "MaxHeap.h"

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        MaxHeap *h = MaxHeapFactory::createMaxHeap(arr);
        int mx = h->maxK(k);
        MaxHeapFactory::deleteMaxHeap(h);
        return mx;
    }
};
