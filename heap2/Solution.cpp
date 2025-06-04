//finding the kth largest element in an array using max heap

#include <vector>
#include "MaxHeap.h"

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        return MaxHeap(arr).maxK(k);
    }
};
