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
	int findKthLargest(vector<int>& arr, int);

	void heapifyUp();
	void HeapifyUp(vector<int>& nums, int);

	void heapifyDown();
	void HeapifyDown(vector<int>& nums, int);

	void print();

	void insert(int);
	void Insert(vector<int>& nums, int);

	int deletion();
	int Deletion();
};

void Solution::heapifyUp() {
	int len = nums.size();
	HeapifyUp(nums, len - 1);
}
void Solution::HeapifyUp(vector<int>& nums, int k) {
	int parent = (k - 1) / 2;
	if (nums[parent] <= nums[k]) {
		swap(nums[k], nums[parent]);
	}
	if (parent == 0) {
		return;
	}
	HeapifyUp(nums, parent);
}

void Solution::heapifyDown() {
	HeapifyDown(nums, 0);
}
void Solution::HeapifyDown(vector<int>& nums, int k) {
	int largest = k, left = 2 * k + 1, right = left + 1;
	if (left > nums.size()-1) {
		return;
	}
	if (nums[left] >= nums[largest]) {
		largest = left;
	}
	if (nums[right] >= nums[largest]) {
		largest = right;
	}
	swap(nums[k], nums[largest]);
	HeapifyDown(nums, largest);
}

void Solution::print() {
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

void Solution::insert(int dat) {
	Insert(nums, dat);
}
void Solution::Insert(vector<int>& nums, int dat) {
	nums.push_back(dat);
	heapifyUp();
}

int Solution::Deletion() {
	int max = nums[0];
	swap(nums[0], nums[nums.size() - 1]);
	nums.pop_back();
	heapifyDown();
	return max;
}

int Solution::findKthLargest(vector<int>& arr, int k) {
	for (int i = 0; i < nums.size(); i++) {
		insert(nums[i]);
	}
	int max;
	for (int i = 0; i < k; i++) {
		max = Deletion();
	}
	return max;
}

int main() {
	vector<int> arr = {3,2,3,1,2,4,5,5,6};
	int a;
	cin >> a;
	Solution s;
	s.print();
	printf("%d\n", s.findKthLargest(arr, a));
	s.print();

/*
	s.heapifyDown();
	s.print();
*/
}