#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<stack>
#include<queue>
#include<cstdlib>
#include<deque>
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
    bool isPalindrome(ListNode* head) {
        ListNode* rev = nullptr, * fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            ListNode* tmp = rev;
            rev = head;
            head = head->next;
            rev->next = tmp;
        }
        auto tail = fast != nullptr ? head->next : head;
        bool isPali = true;
        while (rev != nullptr) {
            isPali = isPali && rev->val == tail->val;
            ListNode* tmp = head;
            head = rev;
            rev = rev->next;
            head->next = tmp;
            tail = tail->next;
        }
        return isPali;
    }
};