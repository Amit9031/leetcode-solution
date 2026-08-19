class Solution {
public:
    string minWindow(string s, string t) {
       vector<int>hash(256,0);
       int n=s.size(),m=t.size(),l=0,r=0,startind=0,minlen=INT_MAX,cnt=0;;
       for(auto i: t){
        hash[i]++;
       }
       while(r<s.size()){
        if(hash[s[r]]>0)
        cnt++;
        hash[s[r]]--;
        while(cnt==m){
            if(r-l+1<minlen){
                minlen=r-l+1;
                startind=l;
            }
            hash[s[l]]++;
            if(hash[s[l]]>0)cnt--;
            l++;
        }
        r++;
       }
       return minlen==INT_MAX ?"":s.substr(startind,minlen);
    }
};
