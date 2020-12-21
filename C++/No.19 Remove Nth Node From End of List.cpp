#include<string>
#include<vector>
#include<iostream>
using namespace std;



 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ready = n;
        ListNode* curr = head, * delpre = nullptr;
        while (curr != nullptr) {
            if (delpre != nullptr)
                delpre = delpre->next;
            else if (ready == 0)
                delpre = head;
            else ready--;
            curr = curr->next;
        }
        if (delpre == nullptr)
            head = head->next;
        else delpre->next = delpre->next->next;
        return head;
    }
};