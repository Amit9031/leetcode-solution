class Solution {
public:
    string removeOuterParentheses(string s) {
        string a="";
int count=0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                if(count>0){
                    a+=s[i];
                }

                count++;
            }
            else{
                count--;
                if(count>0){
                    a+=s[i];
                }
            }
        }
        return a;
    }
};