class Solution {
public:
    int jump(vector<int>& nums) {
        
        int far=0;
        int curridx=0, jump=0;
        for(int i=0;i<nums.size()-1;i++){
            far=max(far, i+nums[i]);
            if(i==curridx){
                if(far==curridx)return -1;
                jump++;
                curridx=far;
            }
        }
        return jump;
    }
};