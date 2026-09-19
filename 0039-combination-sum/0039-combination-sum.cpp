class Solution {
public:
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int sum, int index,
               vector<vector<int>>& ans) {

        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            sum += candidates[i];
            temp.push_back(candidates[i]);

            solve(candidates, target, sum, i, ans);

            temp.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        solve(candidates, target, 0, 0, ans);

        return ans;
    }
};