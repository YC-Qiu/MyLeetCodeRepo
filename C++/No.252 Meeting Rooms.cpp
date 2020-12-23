#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        auto starttime_sort = [](vector<int>& a, vector<int>& b) ->bool { return a[0] < b[0]; };
        sort(intervals.begin(), intervals.end(), starttime_sort);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) return false;
        }
        return true;
    }
};
