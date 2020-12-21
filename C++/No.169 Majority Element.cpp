#include<vector>
using namespace std;



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = -1, count = 0;
        for (int& x : nums) {
            if (x != ele) count--;
            else count++;
            if (count <= 0) ele = x, count = 1;
        }
        return ele;
    }
};