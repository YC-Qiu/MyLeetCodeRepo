#include<string>
#include<vector>
#include<iostream>
using namespace std;

bool isBadVersion(int version) { cout << "use "; return true; }


class Solution {
public:
    int firstBadVersion(int n) {
        return binarysearch(1, (unsigned int)n + 1);
    }

    int binarysearch(unsigned int start, unsigned int end) {
        if (start >= end) return start;
        int middle = (start + end) / 2;
        if (isBadVersion(middle)) return binarysearch(start, middle);
        else return binarysearch(middle + 1, end);
    }
};