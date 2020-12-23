#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
private:
  //void genPerms(vector<int>& path, size_t permLength)
    void genPerms(vector<int> path, size_t permLength) {
        if (permLength == path.size()) {
            // Do something with the path
            vec.push_back(path);
            //cout << "path is added: " << path[0] << path[1] << path[2] << path[3] << endl;
            return;
        } // if
        for (size_t i = permLength; i < path.size(); ++i) {
            if (path[permLength] == path[i] && i != permLength) {
                //cout << "skip permLength = " << permLength << " and i = " << i << endl;
                continue;
            }
            //cout << "Before swap, permLength = " << permLength << ", i = " << i << " path is " << path[0] << path[1] << path[2] << path[3] << endl;
            swap(path[permLength], path[i]);
            genPerms(path, permLength + 1);
            //swap(path[permLength], path[i]);
            //cout << "After swap back, permLength = " << permLength << ", i = " << i << " path is " << path[0] << path[1] << path[2] << path[3] << endl;
        } // for
    } // genPerms()
    vector<vector<int>> vec;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        genPerms(nums, 0);
        return vec;
    }
};

//int main() {
//    Solution sol;
//    vector<int> vec = { 1,1,2,2 };
//    vector<vector<int>> a = sol.permuteUnique(vec);
//    return 0;
//}