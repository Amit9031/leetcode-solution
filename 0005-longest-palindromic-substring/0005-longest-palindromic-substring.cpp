class Solution {
public:

int solve(string s ,int l,int r){
    int count=0;
    while(l>=0 && r<s.size()){
        if(s[l]==s[r]){
        count+=2;
        l--;
        r++;
    }

    else{
        break;
    }}
    return count;


}
    string longestPalindrome(string s) {
        int start=0, maxi=0;
   
        for(int i=0;i<s.size();i++){
            int ans=1+solve(s, i-1, i+1);
            if(ans>maxi){
                maxi=ans;
                start=i-ans/2;
            }
        }

for(int i=0;i<s.size();i++){
            int ans=solve(s, i-1, i);
            if(ans>maxi){
                maxi=ans;
                start=i-ans/2;
            }
        }
        return s.substr(start, maxi);

    }
};