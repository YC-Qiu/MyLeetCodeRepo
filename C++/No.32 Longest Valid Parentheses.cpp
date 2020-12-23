#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int sum = 0, start, end, currbest = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += s[i] == '(' ? 1 : -1;
            if (sum == 0) end = i, currbest = max(end - start + 1, currbest);
            else if (sum < 0 && s[i] == '(') {
                sum = 1, start = i;
            }
            else if (sum > 0 && s[i] == ')') {
                end = i,start= currbest = max(end - start + 1, currbest);
            }
        }
        return currbest;
    }
};