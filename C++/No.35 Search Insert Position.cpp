#include<string>
#include<vector>
#include<iostream>
using namespace std;



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // sorted array
        return binarysearch(nums, 0, nums.size(), target);
    }

    int binarysearch(vector<int>& nums, int start, int end, int& target) {
        if (start >= end) return start;
        int middle = (start + end) / 2;
        if (nums[middle] == target) return middle;
        else if (nums[middle] > target) return binarysearch(nums, start, middle, target);
        else return binarysearch(nums, middle + 1, end, target);
    }
};


//int main() {
//
//    Solution sol;
//    vector<int> vec = { 1};
//    int a = sol.searchInsert(vec, 0);
//    return 0;
//}