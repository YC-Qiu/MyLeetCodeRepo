#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int x : nums) {
            result ^= x;
        }
        return result;
    }
};

int main() {
    cout << ((8 ^ 7 ^ 1 ^ 17) & ~(4)) << endl;
    cout << ((8 ^ 7^1^17) & ~(4 ^ 7)) << endl;
    cout << ((8 ^ 1 ^ 17)) << endl;
    return 0;
}