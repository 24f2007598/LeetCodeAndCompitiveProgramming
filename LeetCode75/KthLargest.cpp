//finding the kth largest element in an array using max heap
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
	vector<int> nums;
public:
	int findKthLargest(vector<int>& arr, int k);

	void HeapifyUp(int k);
	void HeapifyDown(int k);
	void print();
	void Insert(int k);

	int Max();
};

void Solution::HeapifyUp(int k) {
	int parent = (k - 1) / 2;
	if (nums[parent] <= nums[k]) {
		swap(nums[k], nums[parent]);
	}
	if (parent == 0) {
		return;
	}
	HeapifyUp(parent);
}

void Solution::HeapifyDown(int k) {
	int largest = k, left = 2 * k + 1, right = left + 1;

	if (left < nums.size() && nums[left] >= nums[largest]) {
		largest = left;
	}
	if (right < nums.size() && nums[right] >= nums[largest]) {
		largest = right;
	}
	if (largest != k) {
		swap(nums[k], nums[largest]);
		HeapifyDown(largest);
	}
}

void Solution::print() {
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

void Solution::Insert(int dat) {
	if (nums.size() == 0) {
		nums.push_back(dat);
		return;
	}
	nums.push_back(dat);
	HeapifyUp(nums.size() - 1);
}

int Solution::Max() {
	int max = nums[0];
	if (nums.size() == 1) {
		nums.erase(nums.end() - 1);
		return max;
	}
	swap(nums[0], nums[nums.size() - 1]);
	nums.erase(nums.end() - 1);
	HeapifyDown(0);
	return max;
}

int Solution::findKthLargest(vector<int>& arr, int k) {
	if (k > arr.size()) {return 0;}
	for (int i = 0; i < arr.size(); i++) {
		Insert(arr[i]);
	}
	int max;
	for (int i = 0; i < k; i++) {
		max = Max();
	}
	return max;
}

/*
int main() {
	vector<int> arr = {3,2,3,1,2,4,5,5,6};
	Solution s;
	printf("%d\n", s.findKthLargest(arr, 4));

}
*/