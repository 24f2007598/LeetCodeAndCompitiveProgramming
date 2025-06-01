#include "sll.h"
class Solution {
    public:
        void mergeKLists(vector<ListNode>& lists) {
            for (int i = 0; i < lists.size(); i++) {
                printf("%d", i);
            }
        }
};

int main() {
    Solution L;
    ListNode a;
    ListNode b; 

    a.insert_end(1);
    a.insert_end(2);
    a.insert_end(3);

    b.insert_end(10);
    b.insert_end(20);
    b.insert_end(30);
    
    vector<ListNode> wht = {a, b};
    for (int i = 0; i < wht.size(); i++) {
        wht[i].print();
        printf("\n");
    }

    L.mergeKLists(wht);

    return 0;
}