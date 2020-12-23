#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int xsum = 0, truesum = nums[nums.size() - 1 ];
        for (int i = 0; i < nums.size()-1; i++)
            xsum ^= i, truesum ^= nums[i];
        return xsum ^ truesum;
    }
    
};