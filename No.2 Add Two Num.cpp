#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode(-1);
        ListNode* i, * j, * k;
        i = l1, j = l2, k = sum;
        int increment = 0;
        while (i != nullptr || j != nullptr) {
            int temp;
            if (i == nullptr) temp = j->val + increment, j = j->next;
            else if (j == nullptr) temp = i->val + increment, i = i->next;
            else temp = i->val + j->val + increment, j = j->next, i = i->next;
            if (increment == 1) increment = 0;
            if (temp >= 10) increment = 1, temp -= 10;
            if (sum->val == -1) sum->val = temp;
            else{
                ListNode* current = new ListNode();
                current->val = temp;
                k->next = current, k = current;
            }
        }
        if (increment == 1) {
            ListNode* current = new ListNode(1);
            k->next = current;
        }
        return sum;
    }
};

//int main() {
//    Solution sol;
//    ListNode l1 = ListNode(8,&ListNode(2));
//    ListNode l2 = ListNode(3);
//    ListNode* l3 = sol.addTwoNumbers(&l1, &l2);
//    delete l3;
//    return 0;
//}