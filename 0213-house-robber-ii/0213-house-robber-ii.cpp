class Solution {
public:

    int solve(vector<int>& nums, int start, int end, vector<int>& dp) {

        if (start > end)
            return 0;

        if (start == end)
            return nums[start];

        if (dp[end] != -1)
            return dp[end];

        dp[end] = max(
            nums[end] + solve(nums, start, end - 2, dp),
            solve(nums, start, end - 1, dp)
        );

        return dp[end];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // Case 1: exclude last house
        int case1 = solve(nums, 0, n - 2, dp1);

        // Case 2: exclude first house
        int case2 = solve(nums, 1, n - 1, dp2);

        return max(case1, case2);
    }
};