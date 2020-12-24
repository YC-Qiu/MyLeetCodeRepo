#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
#include<stack>
#include<queue>
#include<deque>
#include<map>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> dict;
        int count = 0;
        for (char ch : order) dict[ch] = count++;
        for (int i = 1; i < words.size(); i++) {
            if (!lesser(dict, words[i - 1], words[i])) return false;
        }
        return true;
    }
    bool lesser(map<char, int>& dict, string a, string b) {
        for (int i = 0; i < a.length() && i < b.length(); i++) {
            if (dict[a[i]] < dict[b[i]]) return true;
            else if (dict[a[i]] > dict[b[i]]) return false;
        }
        return a.length() <= b.length();
    }
};