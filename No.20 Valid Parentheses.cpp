#include<string>
#include<vector>
#include<map>
using namespace std;




class Solution {
public:
    bool isValid(string s) {
        vector<char> q;
        map<char, int> map{ {'(',1},{'[',2},{'{',3},{')',4},{']',5},{'}',6} };
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i]] < 4) {
                q.push_back(map[s[i]]);
            }
            else if (q.empty() || q.back() != map[s[i]] - 3)
                return false;
            else q.pop_back();
        }
        return q.empty();
    }
};

//int main() {
//    Solution sol;
//    string str = "([)]";
//    bool right = sol.isValid(str);
//    
//    return 0;
//}