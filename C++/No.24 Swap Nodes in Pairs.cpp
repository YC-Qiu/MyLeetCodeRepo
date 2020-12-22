#include<string>
#include<vector>
#include<iostream>
using namespace std;




struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* n1 = head, * n2 = head->next, * pre = nullptr;
        while (n1 != nullptr && n2 != nullptr) {
            if (pre == nullptr) {
                pre = n1;
                n1->next = n2->next;
                n2->next = n1;
                head = n2;  
            }
            else {
                pre->next = n2;
                n1->next = n2->next;
                n2->next = n1;
                pre = n1;
            }
            n1 = n1->next;
            if (n1 == nullptr) break;
            n2 = n1->next;

        }
        return head;
        
    }
};

//int main() {
//    ListNode n1(1, &ListNode(2, &ListNode(3, &ListNode(4))));
//    Solution sol;
//    ListNode n = *sol.swapPairs(&n1);
//    return 0;
//}