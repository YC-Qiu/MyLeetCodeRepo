using namespace std;
#include<string>
#include<vector>



class Solution {
public:
    string countAndSay(int n) {
        vector<char> str = { '1' };
        int turns = 1;
        while (turns < n) {
            char current = str[0];
            int count = 1;
            vector<char> result;
            for (int i = 1; i < str.size(); i++) {
                if (str[i] == current) count++;
                else {
                    result.push_back(count+'0');
                    result.push_back(current);
                    count = 1, current = str[i];
                }
            }
            result.push_back(count + '0');
            result.push_back(current);
            turns++;
            str = result;
        }
        string ret;
        ret.insert(ret.begin(), str.begin(), str.end());
        return ret;
    }
};

//int main() {
//    Solution sol;
//    sol.countAndSay(4);
//    
//    return 0;
//}