class Solution {
public:

int solve(unordered_map<char, int>&mp){
    int maxi=0;
    int mini=INT_MAX;
    for(auto it: mp){
        mini=min(mini,it.second);
        maxi=max(maxi, it.second);
    }
    return maxi-mini;
}

    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char, int>mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                ans+=solve(mp);
            }
        }
        return ans;
    }
};