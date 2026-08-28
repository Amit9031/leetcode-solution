class Solution {
  public:
  
    bool solve(vector<int> &nums, int k, int mid){
        int last=nums[0];
        k--;
        for(int i =1;i<nums.size();i++){
            if(nums[i]-last>=mid){
                k--;
                last=nums[i];
                
                if(k==0)return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        // code here
        sort(nums.begin(), nums.end());
        int left=1;
         int ans=0;
        int right=nums[nums.size()-1]-nums[0];
        while(left<=right){
            int mid=(left+right)/2;
           
            if(solve(nums, k, mid)){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
        
        
    }
};