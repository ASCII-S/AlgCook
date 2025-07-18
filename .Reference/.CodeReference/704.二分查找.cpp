/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 *
 * https://leetcode.cn/problems/binary-search/description/
 *
 * algorithms
 * Easy (56.27%)
 * Likes:    1771
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 2.7M
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果 target
 * 存在返回下标，否则返回 -1。
 *
 * 你必须编写一个具有 O(log n) 时间复杂度的算法。
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [-1,0,3,5,9,12], target = 2
 * 输出: -1
 * 解释: 2 不存在 nums 中因此返回 -1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 你可以假设 nums 中的所有元素是不重复的。
 * n 将在 [1, 10000]之间。
 * nums 的每个元素都将在 [-9999, 9999]之间。
 *
 *
 */

// @lc code=start
#include <vector>
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = (left + right) / 2;
        while (left <= right)
        {
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
            mid = (left + right) / 2;
        }
        return -1;
    }
};
// @lc code=end
