/**
 * Created by choucisan on 2025/7/12 22:10
 */

/*
73. 矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
// 设置矩阵中的零元素
        void setZeroes(vector<vector<int>>& matrix) {
            // 获取矩阵的行数和列数
            int m = matrix.size();
            int n = matrix[0].size();
            // 创建两个向量，用于记录每一行和每一列是否有零元素
            vector<int> row(m, 0);
            vector<int> col(n, 0);
            // 遍历矩阵，记录每一行和每一列是否有零元素
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == 0) {
                        row[i] = 1;
                        col[j] = 1;
                    }
                }
            }
            // 再次遍历矩阵，将记录有零元素的行和列置零
            for (int i = 0;i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (row[i] == 1 || col[j] == 1) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    s.setZeroes(matrix);

    cout << '[' << endl;
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "  [";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << ", ";
        }
        cout << ']';
        if (i < matrix.size() - 1) cout << ',';
        cout << endl;
    }
    cout << ']' << endl;

    return 0;
}
