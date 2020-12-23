#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * Definition for singly-linked list.**/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)return l2;
        if (l2 == nullptr)return l1;
        ListNode* n1 = l1, * n2 = l2, * n3 = nullptr, * l3 = nullptr;
        if (n1->val < n2->val)l3 = n1, n1 = n1->next;
        else l3 = n2, n2 = n2->next;
        n3 = l3;
        while (n1 != nullptr || n2 != nullptr) {
            if (n1 == nullptr) n3->next = n2, n2 = n2->next;
            else if (n2 == nullptr) n3->next = n1, n1 = n1->next;
            else if(n1->val < n2->val)n3->next = n1, n1 = n1->next;
            else n3->next = n2, n2 = n2->next;
            n3 = n3->next;
        }
        return l3;
    }
};