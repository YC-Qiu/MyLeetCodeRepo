#include<string>
#include<vector>
#include<map>
using namespace std;
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * 
 */
int n;
int guess(int num) { return num == n ? 0 : (num < n ? -1 : 1); }



class Solution {
private:
    int binarysearch(unsigned int start, unsigned int end) {
        if (start >= end) return start;
        int middle = (start + end) / 2;
        if (guess(middle) == 0) return middle;
        else if (guess(middle) > 0) return binarysearch(start, middle);
        else return binarysearch(middle + 1, end);
    }
public:
    int guessNumber(int n) {
        return binarysearch(1, n + 1);
    }
};


//int main() {
//    Solution sol;
//    n = 1;
//    int a = sol.guessNumber(2);
//	return 0;
//}