class Solution {
public:


    bool solve(vector<int>&nums, int k, int mid){
        int count=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                count++;
                sum=nums[i];
                
            }
            if(count>k)return false;
            }
        
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;

            if(solve(nums, k, mid)){
                right=mid-1;
            }
            else left=mid+1;
        }
        return left;

    }
};