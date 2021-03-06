/*
 * @lc app=leetcode.cn id=1300 lang=cpp
 *
 * [1300] 转变数组后最接近目标值的数组和
 *
 * https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target/description/
 *
 * algorithms
 * Medium (46.48%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    24.8K
 * Total Submissions: 53.3K
 * Testcase Example:  '[4,9,3]\n10'
 *
 * 给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，使得将数组中所有大于 value 的值变成 value
 * 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。
 * 
 * 如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。
 * 
 * 请注意，答案不一定是 arr 中的数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [4,9,3], target = 10
 * 输出：3
 * 解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [2,3,5], target = 10
 * 输出：5
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [60864,25176,27249,21296,20204], target = 56803
 * 输出：11361
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 1 <= arr[i], target <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int sum=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            //计算平均值，如果从第i个开始所有元素为tmp,此时所有元素和为target
            double tmp =(double) (target-sum)/(n-i); 

            //题目要求大于tmp的所有值都变成tmp，所以判断第i个元素满不满足， 
            //因为排过序了，如果arr[i]>tmp,后面的元素也必定>tmp
            if (arr[i]>tmp)                                
                return int(tmp+0.4); //返回整数，所以五舍六入

            sum+=arr[i];
        }
        return arr[n-1]; //返回最后一个元素
    }
};
// @lc code=end

