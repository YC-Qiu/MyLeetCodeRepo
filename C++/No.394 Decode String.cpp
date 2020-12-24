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
    string decodeString(string s) {
        vector<string> st;
        stack<string, vector<string>> temp;
        string tempnum = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9')
                tempnum += s[i];
            else {
                if (!tempnum.empty())
                    st.push_back(tempnum), tempnum = "";
                if (s[i] != ']') 
                    st.push_back(string(1, s[i]));
                else {
                    while (st.back() != "[") {
                        temp.push(st.back());
                        st.pop_back();
                    }
                    st.pop_back();
                    string str = "";
                    while (!temp.empty()) {
                        str += temp.top();
                        temp.pop();
                    }
                    int num = atoi(st.back().data());
                    st.pop_back();
                    string s = "";
                    while (num > 0) s += str, num--;
                    st.push_back(s);
                }
            }
            
        }
        string result = "";
        for (string s1:st) {
            result += s1;
        }
        return result;
    }
};