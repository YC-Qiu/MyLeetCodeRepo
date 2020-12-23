#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
private:
    void genPerms(vector<int>& path, size_t permLength) {
        if (permLength == path.size()) {
            // Do something with the path
            vec.push_back(path);
            return;
        } // if
        for (size_t i = permLength; i < path.size(); ++i) {
            swap(path[permLength], path[i]);
            genPerms(path, permLength + 1);
            swap(path[permLength], path[i]);
        } // for
    } // genPerms()
    vector<vector<int>> vec;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        genPerms(nums, 0);
        return vec;
    }
};

//int main() {
//    Solution sol;
//    vector<int> vec = { 1,2,3,4 };
//    vector<vector<int>> a = sol.permute(vec);
//    return 0;
//}
