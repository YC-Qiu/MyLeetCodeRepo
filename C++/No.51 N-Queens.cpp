#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    int MAX_ROW;
    void genPerms(vector<int> path, size_t permLength) {
        if (!promising(path, permLength))
            return;
        if (permLength == MAX_ROW) {
            // Do something with the path
            ans.push_back(vector<string>());
            vector<string>& strvec = ans[ans.size() - 1];
            for (int x : path) {
                string temp = form;
                temp[x] = 'Q';
                strvec.push_back(temp);
            }
            return;
        } // if
        for (size_t i = 0; i < MAX_ROW; ++i) {
            path[permLength] = i;
            genPerms(path, permLength + 1);
        } // for
    } // genPerms()
    bool promising(vector<int>& path, size_t permLength) {
        int last = permLength - 1;
        for (int i = 0; i < last;i++) {
            if (path[i] == path[last] || last - i == path[last] - path[i] || last - i == path[i] - path[last]) return false;
        }
        return true;
    }
    string form;
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        MAX_ROW = n;
        form = string(MAX_ROW, '.');
        vector<int> path(MAX_ROW);
        genPerms(path, 0);
        return ans;
    }
};

//int main() {
//    Solution sol;
//    auto vec = sol.solveNQueens(4);
//    for (auto v: vec) {
//        for (auto str : v) {
//            cout << str << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}