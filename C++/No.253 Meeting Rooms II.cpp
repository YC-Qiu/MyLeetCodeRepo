#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        for (vector<int>& v : intervals)
            start.push_back(v[0]), end.push_back(v[1]);
        sort(start.begin(), start.end(), less<int>());
        sort(end.begin(), end.end(), less<int>());
        int endstr = 0, count = 0;
        for (int i = 0; i < start.size(); i++) {
            if (start[i] < end[endstr]) count++;
            else endstr++;
        }
        return count;
    }
};