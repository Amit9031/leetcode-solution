class Solution {
public:

    int inorder(TreeNode* root, int &k, int &ans) {
        if (!root) return 0;

        inorder(root->left, k, ans);

        k--;
        if (k == 0) {
            ans = root->val;
            return ans;
        }

        inorder(root->right, k, ans);

        return ans;
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        inorder(root, k, ans);
        return ans;
    }
};