class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty())return true;
        if(s.size()>t.size())return false;
        int i=0, j=0;
       while(i<s.size() && j<t.size()){
        if(s[i]==t[j]){
            i++;
            
            if(i==s.size())return true;
        }
        j++;
       }
       
       
       return false;
    }
};