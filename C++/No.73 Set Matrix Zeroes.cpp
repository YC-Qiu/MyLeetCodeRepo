#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        bool col0 = false, row0 = false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!matrix[i][j]) {
                    if (!i) row0 = true;
                    else matrix[0][j] = 0;
                    if (!j)col0 = true;
                    else matrix[i][0] = 0;
                }
            }
        }

        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (!matrix[i][j])continue;
                if (!i && row0) matrix[i][j] = 0;
                else if (!j && col0) matrix[i][j] = 0;
                else if ((!matrix[i][0] || !matrix[0][j]) && i && j) matrix[i][j] = 0;
            }
        }
        return;
    }
};

//int main() {
//    vector<vector<int>> matrix = { {1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0} };
//    Solution sol;
//    sol.setZeroes(matrix);
//    return 0;
//}