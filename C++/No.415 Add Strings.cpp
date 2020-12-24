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


class Solution {
public:
    string addStrings(string num1, string num2) {
        stack<char, vector<char>> st;
        int i1 = num1.size() - 1, i2 = num2.size() - 1;
        int incre = 0;
        while(i1 >= 0 || i2 >= 0) {
            int tempsum;
            if (i1 < 0) tempsum = num2[i2--] - '0' + incre;
            else if (i2 < 0) tempsum = num1[i1--] - '0' + incre;
            else tempsum = num1[i1--] - '0' + num2[i2--] - '0' + incre;
            if (tempsum >= 10) tempsum -= 10, incre = true;
            else incre = false;
            st.push(tempsum + '0');
        }
        if (incre) st.push('1');
        string result = "";
        while (!st.empty()) result += st.top(),st.pop();
        return result;
    }
};