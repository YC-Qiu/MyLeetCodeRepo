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
    int compress(vector<char>& chars) {
        char prev = chars[0];
        string result = "";
        int count = 0;
        chars.push_back('\0');
        for (char ch : chars) {
            if (ch != prev) {
                result += prev;
                if (count != 1) {
                    chars[indexAns++] = (char)((count % 10) + '0');
                    count /= 10;

                }
            }
            else count++;
        }
        chars = vector<char>(result.begin(),result.end());
        return chars.size();
    }
};