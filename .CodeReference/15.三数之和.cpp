#include <vector>
#include <algorithm>
using namespace std;

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (39.56%)
 * Likes:    7523
 * Dislikes: 0
 * Total Accepted:    2.4M
 * Total Submissions: 6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j !=
 * k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
// 原始暴力解法 - O(n³) 时间复杂度，会超时
class SolutionBruteForce
{
public:
    void result_push_back(vector<vector<int>> &result, vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        if (find(result.begin(), result.end(), nums) == result.end())
            result.push_back(nums);
    }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int len = nums.size();
        for (int i = 0; i < len - 2; i++)
            for (int j = i + 1; j < len - 1; j++)
                for (int k = j + 1; k < len; k++)
                    if (nums[i] + nums[j] + nums[k] == 0)
                        result_push_back(result, {nums[i], nums[j], nums[k]});
        return result;
    }
};

// 优化解法 - 排序 + 双指针，O(n²) 时间复杂度
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();

        // 数组长度小于3，无法组成三元组
        if (n < 3)
            return result;

        // 先排序，便于去重和使用双指针
        sort(nums.begin(), nums.end());

        // 固定第一个数字
        for (int i = 0; i < n - 2; i++)
        {
            // 如果第一个数字大于0，后面的数字都更大，不可能和为0
            if (nums[i] > 0)
                break;

            // 跳过重复的第一个数字
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // 使用双指针查找另外两个数字
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // 跳过重复的left值
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // 跳过重复的right值
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    // 和太小，左指针右移
                    left++;
                }
                else
                {
                    // 和太大，右指针左移
                    right--;
                }
            }
        }

        return result;
    }
};
// @lc code=end
