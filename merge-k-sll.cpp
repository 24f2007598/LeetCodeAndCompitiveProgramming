#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
using namespace std;

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
        void insert_end(ListNode*, int);
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
//vector<ListNode*>& lists
        void mergeKLists();
        ListNode* merge2Lists(ListNode*, ListNode*);
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
void List::insert_end(ListNode* head, int x) {
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

List::ListNode* List::merge2Lists(ListNode* L1, ListNode* L2) {
    if (L1 == NULL) {
        return L2;
    }
    if (L2 == NULL) {
        return L1;
    }

    struct ListNode* sorted = (struct ListNode*) malloc (sizeof(struct ListNode));
    sorted -> data = 0;
    sorted -> next = NULL;
    struct ListNode* t1 = L1;
    struct ListNode* t2 = L2;

    while (true) {
        if (t1 -> data < t2 -> data) {
            sorted -> next = t1;
        }

    }


    // for (int i = 0; i < lists.size(); i++) {
    //     while (true) {
    //         if (sorted == NULL) {
    //             sorted = lists[i];
    //             break;
    //         }
    //         if (lists[i] == NULL) {
    //             break;
    //         }
    //         if (sorted->data < lists[i] -> data) {

    //         }
    //     }
    // }
}

int main() {
    
    List a;
    List b; 

    a.mergeKLists();
    
    return 0;
}