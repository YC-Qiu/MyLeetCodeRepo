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


class MaxStack {
public:
    /** initialize your data structure here. */
    vector<int> s1; // entire stack
    stack<int> s2; // current max

    MaxStack() {

    }

    void push(int x) {
        s1.push_back(x);
        if (s2.empty() || x >= peekMax())  s2.push(x);
    }

    int pop() {
        int x = top();
        if (s1.back() == peekMax())  s2.pop();
        s1.pop_back();
        return x;
    }

    int top() {
        return s1.back();
    }

    int peekMax() {
        return s2.empty() ? s1.back() : s2.top();
    }

    int popMax() {
        int max= s2.top();
        for (int i = s1.size() - 1; i >= 0; i--) {
            if (s1[i] != max) continue;
            s1.erase(s1.begin()+i);
            break;
        }
        s2.pop();
        return max;
    }
};