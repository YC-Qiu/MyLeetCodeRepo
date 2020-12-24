#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<stack>
#include<queue>
#include<cstdlib>
#include<deque>
using namespace std;


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minv = INT_MAX, sum = 0;
        for (int x : nums) minv = min(x, minv);
        for (int x : nums) sum += x - minv;
        return sum;
    }
};