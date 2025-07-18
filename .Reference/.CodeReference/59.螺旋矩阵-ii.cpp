/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (70.57%)
 * Likes:    1471
 * Dislikes: 0
 * Total Accepted:    559.6K
 * Total Submissions: 793.3K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 *
 *
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> m(n, vector<int>(n, 0));
        int level = n / 2;
        int offset = 0;
        int count = 1;
        for (int i = 0; i < level; i++)
        {
            // 左到右
            for (int i1 = 0 + offset; i1 < n - 1 - offset; i1++)
            {
                m[0 + offset][i1] = count++;
            }
            //  上到下
            for (int i2 = 0 + offset; i2 < n - 1 - offset; i2++)
            {
                m[i2][n - 1 - offset] = count++;
            }
            // 右到左
            for (int i3 = n - 1 - offset; i3 > 0 + offset; i3--)
            {
                m[n - 1 - offset][i3] = count++;
            }
            // 下到上
            for (int i4 = n - 1 - offset; i4 > 0 + offset; i4--)
            {
                m[i4][0 + offset] = count++;
            }
            offset++;
        }
        if (n % 2 == 1)
        {
            m[n / 2][n / 2] = count++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << m[i][j] << " ";
            }
            std::cout << std::endl;
        }
        return m;
    }
};
// @lc code=end
