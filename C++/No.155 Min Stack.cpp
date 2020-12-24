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

class MinStack {
private:
    stack<int> s1; // entire stack
    stack<int> s2; // current min
public:
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin())  s2.push(x);
    }
    void pop() {
        if (s1.top() == getMin())  s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int getMin() {
        return s2.top();
    }
};