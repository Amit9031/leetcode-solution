class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lleft(n,0);
        vector<int>rleft(n,0);
        lleft[0]=height[0];
        rleft[n-1]=height[n-1];

        for(int i =1;i<n;i++){
            lleft[i]=max(height[i],lleft[i-1]);
        }
        for(int i =n-2;i>=0;i--){
            rleft[i]=max(height[i],rleft[i+1]);
        }
        int ans=0;
        for(int i =0;i<n;i++){
            ans+=min(lleft[i],rleft[i])-height[i];
        }
        return ans;
    }
};