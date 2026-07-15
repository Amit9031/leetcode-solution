class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;

            int pre=0;
        for(int  i=0;i<nums.size();i++){
            pre+=nums[i];
            ans.push_back(pre);
        }
        return ans;
        
    }
};