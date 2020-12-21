using namespace std;
#include<vector>
#include<unordered_map>



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myset;
        for (int i = 0; i < nums.size(); i++) {
            auto pair = myset.find(nums[i]);
            if (pair != myset.end()) return vector<int>{ i, pair->second };
            else myset.insert({ target - nums[i],i });
        }
        return vector<int>();
    }

};

//int main() {
//    Solution sol;
//    vector<int> vec{ 2, 7, 11, 15 };
//    sol.twoSum(vec, 9);
//    return 0;
//}