#include<string>
using namespace std;
#include<vector>
#include<iostream>



class Solution {
    struct operator_ctrl {
        bool appeared = false;
        bool ispositive = true;
        bool number_exist = false;
};
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;
        operator_ctrl op;
        long long num = 0;
        for (char ch : s) {
            if (ch == ' ') {
                if (!op.number_exist && !op.appeared) continue;
                else return (op.ispositive ? num : -num);
            }
            else if (ch == '+' || ch == '-') {
                if (op.number_exist) return (op.ispositive ? num : -num);
                if (op.appeared) return 0;
                op.ispositive = ch == '+';
                op.appeared = true;
            }
            else if (ch <= '9' && ch >= '0') {
                num = 10 * num + (ch - '0');
                if (!op.ispositive && -num < INT_MIN) return INT_MIN;
                else if (op.ispositive && num > INT_MAX) return INT_MAX;
                op.number_exist = true;
            }
            else {
                return op.number_exist ? (op.ispositive ? num : -num) : 0;
            }
        }
        return (op.ispositive ? num : -num);
    }
};

//int main() {
//    Solution sol;
//    int k = sol.myAtoi(" -5 - ");
//    return 0;
//}