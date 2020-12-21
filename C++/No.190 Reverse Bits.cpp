#include<string>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num = 0, curr = 31;
        while (n != 0) {
            num += (n & 1) << curr;
            n = n >> 1;
            curr -= 1;
        }
        return num;
    }
};