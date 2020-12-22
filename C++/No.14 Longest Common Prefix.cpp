#include<string>
using namespace std;
#include<vector>
#include<iostream>




class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int curr = strs[0].size();
        bool diff = false;
        for (int i = 1; i < strs.size(); i++) {
            string& str = strs[i];
            diff = false;
            for (int j = 0; j < str.size() && j < curr; j++) {
                if (str[j] != strs[0][j]) {
                    curr = j;
                    diff = true;
                    break;
                }
            }
            if(!diff) curr = curr < str.size() ? curr : str.size();
        }
        return strs[0].substr(0, curr);
    }
};
//
//int main() {
//    Solution sol;
//    vector<string> str{ "flower","flow","floweu" };
//    string temp = sol.longestCommonPrefix(str);
//    cout << temp << endl;
//    return 0;
//}