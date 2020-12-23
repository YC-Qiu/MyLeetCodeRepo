#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        vec.push_back(vector<int>());
        for (int i : nums) {
            int size = vec.size();
            for (int j = 0; j < size; j++) {
                vec.push_back(vec[j]);
                vec[vec.size() - 1].push_back(i);
            }
        }
        return vec;
    }
};