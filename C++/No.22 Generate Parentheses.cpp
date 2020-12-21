#include<string>
#include<vector>
#include<iostream>
using namespace std;



class Solution {
public:
    int n;
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        this->n = n;
        genPerms(0, 0, 0);
        return ans;
    }

    void genPerms(int path, int permLength, int valid) {
        // permLength from 1 to 2n
        if (valid < 0 || valid > 2*n - permLength) return;
        if (permLength == 2*n && valid == 0) {
            char vec[2*8+1];
            int pow = 2 * n - 1, i = 0;
            while (pow >= 0) {
                if (path & (1 << pow)) vec[i++] = ')';
                else vec[i++] = '(';
                path >> 1, pow--;
            }
            vec[i] = '\0';
            ans.push_back(string(vec));
            return;
        } // if
        // valid: ( +1, )-1
        // path: '('=0,')'=1
        genPerms(path << 1, permLength + 1, valid + 1);
        genPerms((path << 1) + 1, permLength + 1, valid - 1);

    } // genPerms()
};

//int main() {
//    Solution sol;
//    vector<string> strs = sol.generateParenthesis(1);
//    return 0;
//}

