class Solution {
public:

vector<string>ans;
string temp;
 string mp[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
   

    void solve(string digits, int idx){
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }
        string lodu=mp[digits[idx]-'0'];
        for(auto ch:lodu){
            temp.push_back(ch);
            solve(digits, idx+1);
            temp.pop_back();
        }
    }



    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        solve(digits, 0);
        return ans;
    }
};