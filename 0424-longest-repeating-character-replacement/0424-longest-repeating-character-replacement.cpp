class Solution {
public:
    int characterReplacement(string s, int k) {
        int right=0,left=0, maxi=0, maxlen=0;
        unordered_map<char, int>mp;
        while(right<s.size()){
            mp[s[right]]++;
            maxi=max(maxi, mp[s[right]]);
            while((right-left+1)-maxi >k){
                mp[s[left]]--;
                left++;
            }
            maxlen=max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};