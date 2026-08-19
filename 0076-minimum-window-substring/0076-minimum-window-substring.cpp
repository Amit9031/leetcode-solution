class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0;
        int minlen=INT_MAX;
        unordered_map<char, int>mp;
        int start=0,count=0;
        for(auto it: t){
            mp[it]++;
        }
        while(r<s.size()){
            if(mp[s[r]]>0){
                count++;
            }
            mp[s[r]]--;
            while(count==t.size()){
                if(r-l+1<minlen){
                    start=l;
                    minlen=r-l+1;

                }
                mp[s[l]]++;
                if(mp[s[l]]>0)count--;
                l++;
            }
            r++;
            
        }
        return minlen==INT_MAX?"":s.substr(start, minlen);

    }
};