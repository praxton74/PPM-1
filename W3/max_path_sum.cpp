class Solution {
public:
    int path_helper(TreeNode *root, int &max_sum) {
        // base case
        if(!root)
            return 0;
        int left_sum = path_helper(root->left, max_sum);
        int right_sum = path_helper(root->right, max_sum);
        
        int opt1 = root->val;
        int opt2 = left_sum + root->val;
        int opt3 = right_sum + root->val;
        int opt4 = left_sum + right_sum + root->val;
        
        max_sum = max({max_sum, opt1, opt2, opt3, opt4});
        return max({0, opt1, opt2, opt3});
    }
    
    
    int maxPathSum(TreeNode* root) {
        // edge case
        if(!root)
            return 0;
        
        int max_sum = INT_MIN;
        path_helper(root, max_sum);
        
        return max_sum;
    }
};
