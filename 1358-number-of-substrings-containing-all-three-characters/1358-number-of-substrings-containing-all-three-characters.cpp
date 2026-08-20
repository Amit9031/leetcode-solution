class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int>mp;
        int left=0,right=0;
        int count=0;
        int ans=0;
        while(right<s.size()){
            mp[s[right]]++;
            while(mp.size()==3){
                count++;
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
            }
            ans+=count;
            right++;
        }
        return ans;
    }
};