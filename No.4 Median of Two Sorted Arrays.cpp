#include<string>
#include<vector>
#include<iostream>
using namespace std;



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double middle = double(nums1.size() + nums2.size()) / 2;
        int i = 0, j = 0, count = 0;
        double curr;
        while (i <= nums1.size() && j <= nums2.size()) {
            if (i == nums1.size()) curr = nums2[j++];
            else if (j == nums2.size()) curr = nums1[i++];
            else curr = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
            count++;
            if (2*count == 2*middle + 1) return curr;
            else if (count == middle) {
                int other;
                if (i == nums1.size()) other = nums2[j];
                else if (j == nums2.size()) other = nums1[i];
                else other = (nums1[i] < nums2[j] ? nums1[i] : nums2[j]);
                return (curr + other) / 2;
            }
        }
        return -1;
    }
};

//int main() {
//    Solution sol;
//    vector<int> v1({1}), v2({3 });
//    double d = sol.findMedianSortedArrays(v1, v2);
//    return 0;
//}