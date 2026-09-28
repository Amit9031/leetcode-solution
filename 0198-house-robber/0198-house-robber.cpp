class Solution {
public:
int solve(vector<int>&nums, int n , vector<int>&dp){
    if(n==0)return nums[0];
    if(n==1)return max(nums[0],nums[1]);
    if(dp[n]!=-1)return dp[n];
    dp[n]=max(nums[n]+solve(nums, n-2, dp), solve(nums, n-1, dp));
    return dp[n];
}
    int rob(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int>dp(n+1, -1);
        return solve(nums, n, dp);
        
        
    }
};