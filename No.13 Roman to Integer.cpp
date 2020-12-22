#include<string>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int romanToInt(string str) {
         int num = 0;
         int curr = 0;
         while (str[curr] != '\0') {
             if (str[curr] == 'M') num += 1000, curr++;
             else if (str[curr] == 'D') num += 500, curr++;
             else if (str[curr] == 'L') num += 50, curr++;
             else if (str[curr] == 'V') num += 5, curr++;
             else if (str[curr] == 'C') {
                 if (str[curr + 1] == 'D') num += 400, curr += 2;
                 else if (str[curr + 1] == 'M') num += 900, curr += 2;
                 else num += 100, curr++;
             }
             else if (str[curr] == 'X') {
                 if (str[curr + 1] == 'C') num += 90, curr += 2;
                 else if (str[curr + 1] == 'L') num += 40, curr += 2;
                 else num += 10, curr++;
             }
             else if (str[curr] == 'I') {
                 if (str[curr + 1] == 'X') num += 9, curr += 2;
                 else if (str[curr + 1] == 'V') num += 4, curr += 2;
                 else num += 1, curr++;
             }
        }
        return num;
    }
};
//
//int main() {
//    Solution sol;
//    string str = sol.intToRoman(1994);
//    return 0;
//}