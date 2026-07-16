class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro=1;
        int count0=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0++;
            }
            else{
                pro*=nums[i];
            }
        }

        for(auto it: nums){
            if(count0>1)ans.push_back(0);

            else if(count0==1){
                if(it==0)ans.push_back(pro);
                else ans.push_back(0);
            }
            else{
                ans.push_back(pro/it);
            }
        }

 
        return ans;
    }
};