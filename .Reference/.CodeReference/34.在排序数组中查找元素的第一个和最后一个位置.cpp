/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (45.45%)
 * Likes:    3044
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2.8M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
 *
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 *
 * 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 *
 * 示例 3：
 *
 *
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums 是一个非递减数组
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int getLeftBound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int leftBound = -1;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] < target)
            {
                left = mid + 1; // left是第一个等于target的索引（如果存在）
            }
            else
            {
                right = mid - 1;
            }
        }
        if (left < nums.size() && nums[left] == target)
            leftBound = left;
        return leftBound;
    }
    int getRightBound(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int rightBound = -1;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid] > target)
            {
                right = mid - 1; // right是从右开始第一个等于target的索引（如果存在）
            }
            else
            {
                left = mid + 1;
            }
        }
        if (right >= 0 && nums[right] == target)
            rightBound = right;
        return rightBound;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int leftBound = getLeftBound(nums, target);
        int rightBound = getRightBound(nums, target);
        return {leftBound, rightBound};
    }
};
// @lc code=end
