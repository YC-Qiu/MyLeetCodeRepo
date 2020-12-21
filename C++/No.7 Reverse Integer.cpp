#include<string>
using namespace std;
#include<vector>
#include<iostream>

class Solution {
public:
    int reverse(int x) {
        long long num(0);
        while (x != 0) {
            int temp = x % 10;
            num = num * 10 + temp;
            x /= 10;
            if (num > INT32_MAX || num < INT_MIN) return 0;
        }
        return num;
    }
};