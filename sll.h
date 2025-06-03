//Singly Linked List using list ADT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    private:
        vector<int> heap;

    public:
        void heapify(vector<int> &heap, int, int);
        
        void run_heap();
        void print();
        void insert(int);
        int deletion();
        
        bool Search(int);
        bool search(vector<int> &heap, int, int);

        void heapSort();
    
};

void PriorityQueue::heapify(vector<int> &heap, int i, int n) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }
    
    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[largest], heap[i]);
        heapify(heap, largest, n);
    }
}

void PriorityQueue::run_heap() {
    for (int i = heap.size()-1; i >= 0; --i) {
        heapify(heap, i, heap.size());
    }
}

void PriorityQueue::print() {
    for (int i = 0; i < heap.size(); ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;
}


void PriorityQueue::insert(int key) {
    heap.push_back(key);
    run_heap();
}


int PriorityQueue::deletion() {
    int dat = heap[0];
    heap[0] = heap[heap.size()-1];
    heap.erase(heap.begin()+heap.size()-1);
    
    run_heap();
    
    return dat;
}

bool PriorityQueue::Search(int key) {
    return search(heap, 0, key);
}

bool PriorityQueue::search(vector<int> &heap, int i, int key) {
    if (i >= heap.size()) {
        return false;
    }

    if (heap[i] == key) {
        return true;
    }

    bool leftSearch = search(heap, 2*i + 1, key);
    bool rightSearch = search(heap, 2*i + 2, key);

    return leftSearch || rightSearch;
}


void PriorityQueue::heapSort() {
    int n = heap.size();
    int key;
    vector<int> sorted;

    // One by one extract from heap
    for (int i = 0; i < n; ++i) {
        key = heap[0];
        heap.erase(heap.begin());
        run_heap();
        sorted.push_back(key);
    }
    heap = sorted;
}

//class definition for SLL
class List {
    private:
    struct ListNode {
        int data;
        struct ListNode *next;
    }; 
    ListNode* head;      
    
    public:
        void insert_beginning(int);
        void insert_end(int);
        void insert_position(int, int);

        int delete_beginning();
        int delete_end();
        int delete_position(int);

        bool search(int);

        void reverse_display(struct ListNode*);
        ListNode* reverse(ListNode*);

        bool isempty();
        int len();
        void print();
        List() : head(nullptr) {}

};

bool List::isempty() {
    return head == NULL;
}
//method to insert element x at the start of the SLL
void List::insert_beginning(int x) {
    struct ListNode* newnode = (struct ListNode*) malloc (sizeof(struct ListNode));
    newnode -> data = x;
    newnode -> next = head;
    head = newnode;
}

//method to insert element x at the end of the SLL
void List::insert_end(int x) {
    struct ListNode* newnode = (struct ListNode*) malloc (sizeof(struct ListNode));
    newnode -> data = x;
    newnode -> next = NULL;
    
    if (head == NULL) {
        head = newnode;
        return;
    }

    struct ListNode* temp = head;
    for (; temp -> next != NULL; temp = temp -> next) {
    }
    temp -> next = newnode;

}

//method to insert element x at the specified position in the SLL
void List::insert_position(int x, int pos) {
    struct ListNode *newnode = (struct ListNode*) malloc (sizeof(struct ListNode));
    
    if (pos > len() || pos < 1) {
        printf("Invalid Postion.\n");
        return;
    }

    if (pos == 1) {
        insert_beginning(x);
        return;
    }

    newnode -> data = x;
    struct ListNode* temp = head;
    for (int i = 1; (temp -> next != NULL) && i < pos-1; i++) {
        temp = temp -> next;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
}

//method to delete the first element of the SLL
int List::delete_beginning() {
    if (head == NULL) {
        printf("UnderFlow Error: List is Empty.\n");
        return 0;
    }

    int elem;
    elem = head -> data;
    head = head -> next;

    return elem; 
}

//method to delete last element of the SLL
int List::delete_end() {
    if (head == NULL) {
        printf("UnderFlow Error: List is Empty.\n");
        return 0;
    }

    int elem;
    if (head -> next == NULL) {
        elem = head -> data;
        head = NULL;
        return elem;
    }

    struct ListNode* temp = head;
    for (;temp -> next -> next != NULL; temp = temp -> next) {

    }

    elem = temp -> next -> data;
    temp -> next = NULL;

    return elem; 
}

//method to delete the element present in the specified position
int List::delete_position(int pos) {
    if (head == NULL) {
        printf("\nUnderFlow Error: List is Empty.\n");
        return 0;
    }

    if (pos > len() || pos < 0) {
        printf("\nInvalid Position.\n");
        return 0;
    }
    int elem;

    struct ListNode* temp = head;
    if (pos == 1) {
        elem = head -> data;
        head = head -> next;
        return elem;
    }
    for (int i = 1; temp -> next != NULL && i < pos-1; i++) {
        temp = temp -> next;
    }

    elem = temp -> next -> data;
    temp -> next = temp -> next -> next;

    return elem; 
}

//method to check if element x is presentin the SLL or not
bool List::search(int x) {
    struct ListNode* temp = head;
    for (int i = 0; temp -> next != NULL; temp = temp -> next){
        if (temp -> data == x) {
            return 1;
        }
        i++;
    }
    if (temp -> data == x) {
        return 1;
    }

    return 0;
}

//method to display the reverse of the SLL
void List::reverse_display(struct ListNode* temp) {
    if (temp -> next == NULL) {
        printf("%d ", temp -> data);
        return;
    }

    reverse_display(temp->next);
    printf("<- %d ", temp->data);
}

//method to reverse the SLL
List::ListNode* List::reverse(ListNode *head) {
    ListNode *curr = head, *P = NULL, *N;

    while (curr != NULL) {
        N = curr->next;
        curr->next = P;

        P = curr;
        curr = N;
    }

    return P;
}

//method to find the number of elements in the SLL
int List::len() {
    int len = 0;
    struct ListNode* temp = head;
    for (; temp -> next != NULL; temp = temp -> next) {
        len++;
    }

    return len+1;
}

//method to display the singly liked list
void List::print() {
    struct ListNode *temp = head;
    if (temp == NULL) {
        printf("head -> NULL\n");
        return;
    }

    //printf("head -> ");
    for (; temp -> next != NULL; temp = temp -> next) {
        printf("%d -> ", temp -> data);
    }
    printf("%d -> NULL\n", temp -> data);
}

